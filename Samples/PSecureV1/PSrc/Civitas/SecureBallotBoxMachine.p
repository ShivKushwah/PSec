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

    start state Init {
        defer TRUSTEDeVote;
        entry (bBoard: machine_handle){
            bulletinBoard = bBoard;
            // print "Kirat Debug";
            // PrintKey(GetThis());
            appendOnlyLog = new SecureTamperEvidentLogMachine(GetThis()); //essentially the db of votes for this ballotbox
            tabulationTeller = new SecureTabulationTellerMachine(bulletinBoard); //counts the votes
        }
        on TRUSTEDeStartElection goto WaitForVotes;
        // on TRUSTEDeVote do {
        //     print "Vote ignored, voting has not started yet !!";
        // }
    }

    state WaitForVotes {
        entry (payload: int) {

        }
        on TRUSTEDeVote do (payload: (credentials : int, vote : int, requestingMachine : machine_handle))
        {
            secure_send appendOnlyLog, TRUSTEDeAddItem, payload.vote;
            receive {
                case TRUSTEDeRespAddItem : (result: bool) {
                    if(result)
                    {
                        untrusted_send payload.requestingMachine, TRUSTEDeRespConfirmVote;
                    }
                }
            }
        }
        on eCloseElection goto VoteCounting;
    }

    state VoteCounting {
        entry {
            secure_send appendOnlyLog, TRUSTEDeGetLog;
            receive{
                case TRUSTEDeRespGetLog: (payload: seq[int]) //p is all the votes returned by the appendOnlyLog
                {
                    secure_send tabulationTeller, TRUSTEDeAllVotes, (ballotID = 0, votes = payload);
                }
            }

            goto WaitForGetResultsQuery;
        }


    }

    state WaitForGetResultsQuery {
        //     on eVote do {
        //     print "Vote ignored, voting phase is over";
        // }
    }
}