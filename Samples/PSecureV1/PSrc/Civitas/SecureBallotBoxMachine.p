/*****************************
BallotBox Machine
* Receive direct votes from SecureVotingClients and save them in SecureTamperEvidentLogMachine
* After predetemined number of votes are received, votes are
forwarded to SecureTabulationTellerMachine to be counted
******************************/

secure_machine SecureBallotBoxMachine
{
    var bulletinBoard: machine_handle;
    var tabulationTeller: machine_handle;
    var appendOnlyLog: machine_handle;
    var numberOfTotalVotesAllowed: int;
    var currentNumberOfVotes: int;

    start state Init {
        defer TRUSTEDeVote;
        entry (payload: (bBoard: machine_handle, bBoardCapability: capability)){
            bulletinBoard = payload.bBoard;
            appendOnlyLog = new SecureTamperEvidentLogMachine((parentMachine = GetThis(), parentCapability = GetCapability(GetThis()) )); //essentially the db of votes for this ballotbox
            tabulationTeller = new SecureTabulationTellerMachine((bBoard = bulletinBoard, bBoardCapability = payload.bBoardCapability)); //counts the votes
        }
        on TRUSTEDeStartElection goto WaitForVotes;
    }

    state WaitForVotes {
        entry (payload: int) {
            numberOfTotalVotesAllowed = payload;
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
            if (currentNumberOfVotes >= numberOfTotalVotesAllowed) {
                goto VoteCounting;
            }
            
        }
    }

    state VoteCounting {
        entry {
            secure_send appendOnlyLog, TRUSTEDeGetLog;
            receive{
                case TRUSTEDeRespGetLog: (payload: seq[(credential : int, vote : int)])
                {
                    print "Sending votes to Secure Tabulation Teller";
                    secure_send tabulationTeller, TRUSTEDeAllVotes, (ballotID = 0, votes = payload);
                }
            }

        }

    }

}