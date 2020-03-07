/*****************************
Secure BallotBox Machine
* Receive direct votes from SecureVotingClients and save them in SecureTamperEvidentLogMachine
* After predetemined number of votes are received, votes are
forwarded to SecureTabulationTellerMachine to be counted
******************************/

secure_machine SecureBallotBoxMachine
{
    var bulletinBoard: secure_machine_handle;
    var tabulationTeller: secure_machine_handle;
    var appendOnlyLog: secure_machine_handle;
    var numberOfTotalVotesAllowed: int;
    var currentNumberOfVotes: int;

    start state Init {
        on TRUSTEDProvisionSecureBallotBoxMachine do (payload: (bBoard: secure_machine_handle, supervisor : secure_machine_handle)){
            bulletinBoard = payload.bBoard;
            appendOnlyLog = new SecureTamperEvidentLogMachine(); //essentially the db of votes for this ballotbox
            send appendOnlyLog, TRUSTEDProvisionSecureTamperEvidentLogMachine, this; //secure_send
            tabulationTeller = new SecureTabulationTellerMachine(); //counts the votes
            send tabulationTeller, TRUSTEDProvisionSecureTabulationTellerMachine, (bBoard = bulletinBoard, supervisor = payload.supervisor);//secure_send
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
        on TRUSTEDeVote do (payload: (credential : secure_int, vote : secure_int, requestingMachine : secure_machine_handle))
        {
            send appendOnlyLog, TRUSTEDeAddItem, (credential = payload.credential, vote = payload.vote); //secure_send
            receive {
                case TRUSTEDeRespAddItem : (result: bool) {
                    if(result)
                    {
                        send payload.requestingMachine, TRUSTEDeRespConfirmVote; //secure_send
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
            send appendOnlyLog, TRUSTEDeGetLog; //secure_send
            receive{
                case TRUSTEDeRespGetLog: (payload: seq[(credential : secure_int, vote : secure_int)])
                {
                    print "Sending votes to Secure Tabulation Teller";
                    send tabulationTeller, TRUSTEDeAllVotes, (ballotID = 0, votes = payload); //secure_send
                }
            }

        }

    }

}