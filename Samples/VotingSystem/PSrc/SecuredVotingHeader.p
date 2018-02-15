type Vote = (credentials:int, vote:int);
type AllVotesInBallot = (ballotId: int, votes: seq[Vote]);
type ElectionResults = (allVotes: map[int, int], whoWon: int) ;

event eVote: (Vote, machine);
event eRespConfirmVote;
event eStartElection;
event eCloseElection;
event eAllVotes: AllVotesInBallot;
event eMergedVotes: seq[Vote];
event eDoTally;
event eElectionResults: map[int, int];
event eGetElectionResults: machine;
event eRespElectionResults: ElectionResults;
