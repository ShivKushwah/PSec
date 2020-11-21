/*****************************
Secure BallotBox Machine
* Receive direct votes from SecureVotingClients and save them in SecureTamperEvidentLogMachine
* After predetemined number of votes are received, votes are
forwarded to SecureTabulationTellerMachine to be counted
******************************/

machine SecureBallotBoxMachine
{
    var bulletinBoard: machine_handle;
    var tabulationTeller: machine_handle;
    var appendOnlyLog: machine_handle;
    var numberOfTotalVotesAllowed: int;
    var currentNumberOfVotes: int;

    start state Init {
        on TRUSTEDProvisionSecureBallotBoxMachine do (payload: (bBoard: machine_handle, supervisor : machine_handle)){
            bulletinBoard = payload.bBoard;
            appendOnlyLog = new SecureTamperEvidentLogMachine() @ this; //essentially the db of votes for this ballotbox
            send appendOnlyLog, TRUSTEDProvisionSecureTamperEvidentLogMachine, this;
            tabulationTeller = new SecureTabulationTellerMachine() @ this; //counts the votes
            send tabulationTeller, TRUSTEDProvisionSecureTabulationTellerMachine, (bBoard = bulletinBoard, supervisor = payload.supervisor);//send
            goto StartElection;
        }
        
    }

    state StartElection {
        defer TRUSTEDeVote;
        on TRUSTEDeStartElection goto WaitForVotes;
    }

    state WaitForVotes {
        entry (payload: int) {
            numberOfTotalVotesAllowed = payload;
            currentNumberOfVotes = 0;
        }
        on TRUSTEDeVote do (payload: (credential : StringType, vote : int, requestingMachine : machine_handle))
        {
            if (currentNumberOfVotes == 0) {
                send appendOnlyLog, TRUSTEDeAddItem, (credential = payload.credential, vote = payload.vote); //send
                receive {
                    case TRUSTEDeRespAddItem : (result: bool) {
                        if(result)
                        {
                            send payload.requestingMachine, TRUSTEDeRespConfirmVote; //send
                            currentNumberOfVotes = currentNumberOfVotes + 1;
                        }
                    }
                }
            } else {
                send payload.requestingMachine, TRUSTEDeRespConfirmVote; //send
                currentNumberOfVotes = currentNumberOfVotes + 1;
            }
            
            if (currentNumberOfVotes >= numberOfTotalVotesAllowed) {
                goto VoteCounting;
            }
            // if ($) {
            //     goto VoteCounting;
            // }
            
        }
    }

    state VoteCounting {
        ignore TRUSTEDeVote;
        entry {
            send appendOnlyLog, TRUSTEDeGetLog; //send
            receive{
                case TRUSTEDeRespGetLog: (payload: seq[(credential : StringType, vote : int)])
                {
                    print "Sending votes to Secure Tabulation Teller";
                    send tabulationTeller, TRUSTEDeAllVotes, (ballotID = 0, votes = payload); //send
                }
            }

        }

    }

}