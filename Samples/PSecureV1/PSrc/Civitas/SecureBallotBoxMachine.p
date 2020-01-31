/*****************************
BallotBox Machine
* BallotBox -> BulletinBoard -> AllVotesFor.
******************************/

//Receives direct votes from VotingClients and upon voting completion, requests the TabulationTeller to count the votes
secure_machine SecureBallotBoxMachine
{
    var bulletinBoard: machine_handle;
    var tabulationTeller: machine_handle;
    var appendOnlyLog: machine_handle;
    var numberOfTotalVotes: int;
    var currentNumberOfVotes: int;

    start state Init {
        defer TRUSTEDeVote;
        entry (payload: (bBoard: machine_handle, bBoardCapability: capability)){
            bulletinBoard = payload.bBoard;
            appendOnlyLog = new SecureTamperEvidentLogMachine((parentMachine = GetThis(), parentCapability = GetCapability(GetThis()) )); //essentially the db of votes for this ballotbox
            tabulationTeller = new SecureTabulationTellerMachine((bBoard = bulletinBoard, bBoardCapability = payload.bBoardCapability)); //counts the votes
        }
        on TRUSTEDeStartElection goto WaitForVotes;
        // on TRUSTEDeVote do {
        //     print "Vote ignored, voting has not started yet !!";
        // }
    }

    state WaitForVotes {
        entry (payload: int) {
            numberOfTotalVotes = payload;
            currentNumberOfVotes = 0;
        }
        on TRUSTEDeVote do (payload: (credential : int, vote : int, requestingMachine : machine_handle, requestingMachineCapability: capability))
        {
            SaveCapability(payload.requestingMachineCapability);
            secure_send appendOnlyLog, TRUSTEDeAddItem, (credential = payload.credential, vote = payload.vote);
            receive {
                case TRUSTEDeRespAddItem : (result: bool) {
                    if(result)
                    {
                        secure_send payload.requestingMachine, TRUSTEDeRespConfirmVote;
                        currentNumberOfVotes = currentNumberOfVotes + 1;
                    }
                }
            }
            if (currentNumberOfVotes >= numberOfTotalVotes) {
                goto VoteCounting;
            }
            
        }
        // on eCloseElection goto VoteCounting;
    }

    state VoteCounting {
        entry {
            secure_send appendOnlyLog, TRUSTEDeGetLog;
            receive{
                case TRUSTEDeRespGetLog: (payload: seq[(credential : int, vote : int)]) //p is all the votes returned by the appendOnlyLog
                {
                    print "Sending votes to Secure Tabulation teller";
                    secure_send tabulationTeller, TRUSTEDeAllVotes, (ballotID = 0, votes = payload);
                }
            }

            // goto WaitForGetResultsQuery;
        }


    }

    // state WaitForGetResultsQuery {
    //     //     on eVote do {
    //     //     print "Vote ignored, voting phase is over";
    //     // }
    // }
}