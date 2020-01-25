/**************************************
Supervisor Machine
* Supervisor -> BallotBox = StartElection, CLoseElection.
* Supervistor -> TabulationTeller = DoTally.
***************************************/

//Root of trust of election. Creates trusted bulletin board and ballotbox, and sends out trusted VotingClients to VotingUSMs
//Starts and ends elections
secure_machine SecureSupervisorMachine 
{
    var bBoard : machine_handle;
    var bBox : machine_handle;
    var tTeller: machine_handle;
    var username_passwords : seq[(int, int)];
    var votingClients : seq[machine_handle]; //seq[VotingClientMachine];
    var numRequestsFulfilled : int;
    var temp : int;
    var i : int;
    var tempMachineHandle : machine_handle;
    var requestingMachineHandle : machine_handle;
    var username: int;
    //Assume there is a setup phase where each voter registers a username and password with the Government
    // and the number of available credentials are = # of eligible voters
    start state Init {
        entry {
            bBoard = new SecureBulletinBoardMachine();
            bBox = new SecureBallotBoxMachine(bBoard);

            //TODO setup username_passwords using some GetStringFromUser
            username_passwords += (0, (1,1));
            username_passwords += (0, (2,2));
            
            
            i = 0;
            while (i < sizeof(username_passwords)){
                //NOTE: another design is to have each VotingUSM create a Voting Client machine, and pass in Supervisor as parameter to VotingClient. 
                //Problem with this approach is that VotingClient doesn't have capability of Supervisor, and there is no trust.

                temp = username_passwords[i].0;
                tempMachineHandle = new SecureVotingClientMachine((bBox, bBoard, username_passwords[i].0, username_passwords[i].1));
                votingClients += (0, tempMachineHandle);
                i = i + 1;
            }

            numRequestsFulfilled = 0;
            
            goto WaitToSendVotingClientMachines;
        }
    }

    state WaitToSendVotingClientMachines {
        on UNTRUSTEDGetVotingSSM goto SendVotingSSM;
    }

    state SendVotingSSM {
        entry (payload: (machine_handle, int)) {
            requestingMachineHandle = payload.0;
            username = payload.1;
            i = 0;
            while (i < sizeof(username_passwords)) {
                if (username_passwords[i].0 == username) {
                    untrusted_send requestingMachineHandle, UNTRUSTEDReceiveVotingSSM, votingClients[i];
                    numRequestsFulfilled = numRequestsFulfilled + 1;
                }
                i = i + 1;
                
            }
            if (numRequestsFulfilled < 2) { //TODO what if 2 malcious people know the usernames, and 
                // claim the votingClients (even tho they can't do anything with them) and numRequestFulfilled = 2
                // and voting begins. Maybe we should have the votingClient tell the SecureSupervisor that they have
                // been authenticated so that the secureSupervisor begins the voting
                goto WaitToSendVotingClientMachines;
            } else {
                goto StartElection;
            }
        }
    }

    // fun DoCloseElection() : bool;/*
    // {
    //     return $;
    // }*/

    state StartElection {
        entry {     
            secure_send bBox, TRUSTEDeStartElection;
        }
        // on null do {
        //     var res: bool;
        //     res = DoCloseElection(); //TODO call this when both machines have finished voting
        //     if(res)
        //     {
        //         goto CloseElection;
        //     }
        // }
    }

    // state CloseElection {
    //     entry {
    //         send bBox, TRUSTEDeCloseElection;
    //         raise halt;
    //     }
    // }
}