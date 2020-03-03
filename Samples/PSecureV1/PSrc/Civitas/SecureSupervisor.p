/**************************************
Secure Supervisor machine
* Root of trust of election.
* Creates SecureBulletinBoard and SecureBallotBox 
* Sends out SecureVotingClients to VotingUSMs
***************************************/

secure_machine SecureSupervisorMachine 
{
    var bBoard : secure_machine_handle;
    var bBox : secure_machine_handle;
    var tTeller: machine_handle;
    var valid_credentials : seq[int];

    fun generateRandomCredential() : int {
        return 3;
    }
    
    start state Registration {
        entry {
            var i : int;

            bBoard = new SecureBulletinBoardMachine();
            bBox = new SecureBallotBoxMachine();
            send bBox, TRUSTEDProvisionSecureBallotBoxMachine, (bBoard = bBoard, supervisor = this); //secure_send

            //These are the credentials of voters that have registered to vote
            //One credential per valid voter
            valid_credentials += (sizeof(valid_credentials), 17);
            valid_credentials += (sizeof(valid_credentials), 98);

            //We send 2 because this is how many votes we need to be submitted
            //before the election is considered finished
            send bBox, TRUSTEDeStartElection, 2; //secure_send

            goto SendVotingClientMachinesOrValidateCredentials;
        }
    }

    
    state SendVotingClientMachinesOrValidateCredentials {
        on UNTRUSTEDGetVotingSSM do (requestingMachine: machine_handle) {
            var secureVotingClientMachine : secure_machine_handle;
            print "Provisioning a secure voting client!";
            secureVotingClientMachine = new SecureVotingClientMachine();
            send secureVotingClientMachine, TRUSTEDProvisionSecureVotingClientMachine, (ballotBox = bBox, bulletinBoard = bBoard); //secure_send
            
            send requestingMachine, UNTRUSTEDReceiveVotingSSM, secureVotingClientMachine as machine_handle; //untrusted_send, CastHandle(secureVotingClientMachine)
        }
        on TRUSTEDValidateCredential do (payload: (tabulationTellerMachine : secure_machine_handle, credentialToCheck : int)) {
            var i : int;
            var found : bool;

            i = 0;
            found = false;

            while (i < sizeof(valid_credentials)) {
                if (valid_credentials[i] == payload.credentialToCheck) {
                    found = true;
                }
                i = i + 1;
            }
            if (found) {
                send payload.tabulationTellerMachine, TRUSTEDValidCredential; //secure_send
            } else {
                send payload.tabulationTellerMachine, TRUSTEDInvalidCredential; //secure_send
            }

        }
    }
}