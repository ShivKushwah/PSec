module votingsystem = 
{ 
    SupervisorMachine,
    VotingClientMachine,
    BulletinBoardMachine,
    BallotBoxMachine,
    TamperEvidentLogMachine
};

test test1: main SupervisorMachine in votingsystem;

implementation votingsystem;
