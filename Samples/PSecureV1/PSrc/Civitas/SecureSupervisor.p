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
    var valid_credentials : seq[secure_StringType];
    
    start state Registration {
        entry {
            var i : int;

            bBoard = new SecureBulletinBoardMachine() @ this;
            bBox = new SecureBallotBoxMachine() @ this;
            send bBox, TRUSTEDProvisionSecureBallotBoxMachine, (bBoard = bBoard, supervisor = this); //secure_send

            //These are the credentials of voters that have registered to vote
            //One credential per valid voter
            valid_credentials += (sizeof(valid_credentials), Endorse(GenerateCredential1()) as secure_StringType);
            valid_credentials += (sizeof(valid_credentials), Endorse(GenerateCredential2()) as secure_StringType);

            //We send 1 because this is how many votes we need to be submitted
            //before the election is considered finished
            send bBox, TRUSTEDeStartElection, Endorse(10) as secure_int; //secure_send

            goto SendVotingClientMachinesOrValidateCredentials;
        }
    }

    
    state SendVotingClientMachinesOrValidateCredentials {
        on UNTRUSTEDGetVotingSSM do (requestingMachine: machine_handle) {
            var secureVotingClientMachine : secure_machine_handle;
            print "Provisioning a secure voting client!";
            secureVotingClientMachine = new SecureVotingClientMachine() @ requestingMachine;
            send secureVotingClientMachine, TRUSTEDProvisionSecureVotingClientMachine, (ballotBox = bBox, bulletinBoard = bBoard); //secure_send
            
            send requestingMachine, UNTRUSTEDReceiveVotingSSM, Declassify(secureVotingClientMachine) as machine_handle; //untrusted_send, CastHandle(secureVotingClientMachine)
        }
        on TRUSTEDValidateCredential do (payload: (tabulationTellerMachine : secure_machine_handle, credentialToCheck : secure_StringType)) {
            var i : int;
            var found : bool;

            i = 0;
            found = false;

            while (i < sizeof(valid_credentials)) {
                if (Declassify(valid_credentials[i]) as StringType == Declassify(payload.credentialToCheck) as StringType) {
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