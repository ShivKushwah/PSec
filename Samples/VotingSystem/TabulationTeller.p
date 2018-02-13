/**************************************
Supervisor Machine
* Supervisor -> BallotBox = StartElection, CLoseElection.
* Supervistor -> TabulationTeller = DoTally.
***************************************/
machine SupervisorMachine 
receives;
sends eStartElection, eCloseElection, eDoTally;
{
    var bBoard : machine;
    var bBox : machine;
    var tTeller: machine;
    start state Init {
        entry {

            bBoard = new BulletinBoardMachine();
            bBox = new BallotBoxMachine(bBoard);
            new VotingClientMachine((bBox = bBox, bBoard = bBoard));
            new VotingClientMachine((bBox = bBox, bBoard = bBoard));
            goto StartElection;
        }
    }

    fun DoCloseElection() : bool
    {
        return $;
    }

    state StartElection {
        entry {
            
            send bBox, eStartElection;
        }
        on null do {
            var res: bool;
            res = DoCloseElection();
            if(res)
            {
                goto CloseElection;
            }
        }
    }

    state CloseElection {
        entry {
            send bBox, eCloseElection;
            raise halt;
        }
    }
}


/****************************************
* Tabulation Teller Machine
* TabulationTeller -> BulletinBoard -> ElectionResults.
****************************************/

machine TabulationTellerMachine 
receives eDoTally, eMergedVotes;
sends eElectionResults;
{
    var bulletinBoard: machine;
    var allVotes: seq[Vote];
    start state Init {
        defer eDoTally;
        entry (bBoard: machine){
            bulletinBoard = bBoard;
        }
        on eMergedVotes do (payload: seq[Vote]){
            allVotes = payload;
            goto WaiForDoTally;
        }
    }
    
    state WaiForDoTally {
        on eDoTally do {
            var result: map[int, int];
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                //consider the latest vote
                //validate the credentials
                result[allVotes[i].credentials] = allVotes[i].vote;
                i = i + 1;
            }

            send bulletinBoard, eElectionResults, result;
        }
    }
}
                    