type Vote = (credentials:int, vote:int);
type AllVotesInBallot: (ballotId: int, votes: seq[Vote]);

event eVote: Vote;

event eStartElection;
event eCloseElection;
event eAllVotes: AllVotesInBallot;