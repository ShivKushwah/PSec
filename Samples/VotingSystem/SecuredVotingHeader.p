type Vote = (credentials:int, vote:int);
type AllVotesInBallot = (ballotId: int, votes: map[int, int]);
type ElectionResults = (allVotes: map[int, int], whoWon: int) ;

event eVote: (Vote, machine);
event eRespConfirmVote;
event eStartElection;
event eCloseElection;
event eAllVotes: AllVotesInBallot;
event eGetElectionResults: machine;
event eRespElectionResults: ElectionResults;
