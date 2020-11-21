/**************************************
Secure Supervisor machine
* Root of trust of election.
* Creates SecureBulletinBoard and SecureBallotBox 
* Sends out SecureVotingClients to VotingUSMs
***************************************/

machine SecureSupervisorMachine 
{
    var bBoard : machine_handle;
    var bBox : machine_handle;
    var tTeller: machine_handle;
    var valid_credentials : seq[StringType];
    
    start state Registration {
        entry {
            var i : int;

            bBoard = new SecureBulletinBoardMachine() @ this;
            bBox = new SecureBallotBoxMachine() @ this;
            send bBox, TRUSTEDProvisionSecureBallotBoxMachine, (bBoard = bBoard, supervisor = this); //send

            //These are the credentials of voters that have registered to vote
            //One credential per valid voter
            valid_credentials += (sizeof(valid_credentials), GenerateCredential1());
            valid_credentials += (sizeof(valid_credentials), GenerateCredential2());

            //We send 1 because this is how many votes we need to be submitted
            //before the election is considered finished
            send bBox, TRUSTEDeStartElection, 100; //send

            goto SendVotingClientMachinesOrValidateCredentials;
        }
    }

    
    state SendVotingClientMachinesOrValidateCredentials {
        on UNTRUSTEDGetVotingSSM do (requestingMachine: machine_handle) {
            var secureVotingClientMachine : machine_handle;
            print "Provisioning a secure voting client!";
            secureVotingClientMachine = new SecureVotingClientMachine() @ requestingMachine;
            send secureVotingClientMachine, TRUSTEDProvisionSecureVotingClientMachine, (ballotBox = bBox, bulletinBoard = bBoard); //send
            
            send requestingMachine, UNTRUSTEDReceiveVotingSSM, secureVotingClientMachine; //untrusted_send, CastHandle(secureVotingClientMachine)
        }
        on TRUSTEDValidateCredential do (payload: (tabulationTellerMachine : machine_handle, credentialToCheck : StringType)) {
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
                send payload.tabulationTellerMachine, TRUSTEDValidCredential; //send
            } else {
                send payload.tabulationTellerMachine, TRUSTEDInvalidCredential; //send
            }

        }
    }
}