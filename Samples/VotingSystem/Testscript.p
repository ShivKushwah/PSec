module votingsystem = 
{ 
    SupervisorMachine,
    VotingClientMachine,
    TabulationTellerMachine,
    BulletinBoardMachine,
    BallotBoxMachine,
    TamperEvidentLogMachine
};

test test1: main SupervisorMachine in votingsystem;