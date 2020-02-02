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
    var valid_credentials : seq[int];

    fun generateRandomCredential() : int {
        return 3;
    }
    
    start state Registration {
        entry {
            var i : int;

            bBoard = new SecureBulletinBoardMachine();
            bBox = new SecureBallotBoxMachine((bBoard = bBoard, bBoardCapability = GetCapability(bBoard), supervisor = GetThis(), supervisorCapability = GetCapability(GetThis()) ) );

            //These are the credentials of voters that have registered to vote
            //One credential per valid voter
            valid_credentials += (sizeof(valid_credentials), 17);
            valid_credentials += (sizeof(valid_credentials), 98);

            //We send 2 because this is how many votes we need to be submitted
            //before the election is considered finished
            secure_send bBox, TRUSTEDeStartElection, 2;

            goto SendVotingClientMachinesOrValidateCredentials;
        }
    }

    
    state SendVotingClientMachinesOrValidateCredentials {
        on UNTRUSTEDGetVotingSSM do (requestingMachine: machine_handle) {
            var secureVotingClientMachine : machine_handle;
            print "Provisioning a secure voting client!";
            secureVotingClientMachine = new SecureVotingClientMachine((ballotBox = bBox, bulletinBoard = bBoard, ballotBoxCapability = GetCapability(bBox), bulletinBoardCapability = GetCapability(bBoard)));
            untrusted_send requestingMachine, UNTRUSTEDReceiveVotingSSM, secureVotingClientMachine;
        }
        //TODO add validate credential event here
        on TRUSTEDValidateCredential do (payload: (tabulationTellerMachine : machine_handle, tabulationTellerCapability : capability, credentialToCheck : int)) {
            var i : int;
            var found : bool;

            i = 0;
            found = false;
            SaveCapability(payload.tabulationTellerCapability);

            while (i < sizeof(valid_credentials)) {
                if (valid_credentials[i] == payload.credentialToCheck) {
                    found = true;
                }
                i = i + 1;
            }
            if (found) {
                secure_send payload.tabulationTellerMachine, TRUSTEDValidCredential;
            } else {
                secure_send payload.tabulationTellerMachine, TRUSTEDInvalidCredential;
            }

        }
    }
}