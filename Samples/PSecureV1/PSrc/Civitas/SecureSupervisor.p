/**************************************
Secure Supervisor machine
* Root of trust of election.
* Creates SecureBulletinBoard and SecureBallotBox 
* Sends out SecureVotingClients to VotingUSMs
***************************************/

secure_machine SecureSupervisorMachine 
{
    var bBoard : machine_handle;
    var bBox : machine_handle;
    var tTeller: machine_handle;
    var username_passwords : seq[(int, int)];
    
    start state Init {
        entry {
            var i : int;

            bBoard = new SecureBulletinBoardMachine();
            bBox = new SecureBallotBoxMachine((bBoard = bBoard, bBoardCapability = GetCapability(bBoard)));

            //These are the username and passwords of voters that have
            //registered to vote in the past
            username_passwords += (sizeof(username_passwords), (2,2)); //TODO setup username_passwords using user input
            username_passwords += (sizeof(username_passwords), (1,1));

            //We send 2 because this is how many votes we need to be submitted
            //before the election is considered finished
            secure_send bBox, TRUSTEDeStartElection, 2;

            goto WaitToSendVotingClientMachines;
        }
    }

    state WaitToSendVotingClientMachines {
        on UNTRUSTEDGetVotingSSM goto SendVotingSSM;
    }

    state SendVotingSSM {
        entry (payload: (requestingMachine: machine_handle, username: int)) {
            var i : int;
            var secureVotingClientMachine : machine_handle;

            i = 0;
            while (i < sizeof(username_passwords)) {
                if (username_passwords[i].0 == payload.username) {
                    print "Provisioning a secure voting client!";
                    secureVotingClientMachine = new SecureVotingClientMachine((ballotBox = bBox, bulletinBoard = bBoard, username = username_passwords[i].0, password = username_passwords[i].1, ballotBoxCapability = GetCapability(bBox), bulletinBoardCapability = GetCapability(bBoard)));
                    untrusted_send payload.requestingMachine, UNTRUSTEDReceiveVotingSSM, secureVotingClientMachine;
                }
                i = i + 1;
                
            }
            goto WaitToSendVotingClientMachines;
        }
    }
}