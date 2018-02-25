
  #ifndef P_SECUREDVOTING_H_
    #define P_SECUREDVOTING_H_
    #include "Prt.h"
    #ifdef __cplusplus
      extern "C"{
    #endif
    enum P_FIELD_INDEX_AllVotesInBallot
    {
      P_FIELD_INDEX_AllVotesInBallot_ballotId = 0,
      P_FIELD_INDEX_AllVotesInBallot_votes = 1,
      _P_FIELD_INDEX_AllVotesInBallot_COUNT = 2
    };

    enum P_FIELD_INDEX_ElectionResults
    {
      P_FIELD_INDEX_ElectionResults_allVotes = 0,
      P_FIELD_INDEX_ElectionResults_whoWon = 1,
      _P_FIELD_INDEX_ElectionResults_COUNT = 2
    };

    enum P_FIELD_INDEX_Vote
    {
      P_FIELD_INDEX_Vote_credentials = 0,
      P_FIELD_INDEX_Vote_vote = 1,
      _P_FIELD_INDEX_Vote_COUNT = 2
    };

    enum P_FUNS_BallotBoxMachine
    {
      P_FUN_BallotBoxMachine_ANON0 = 1,
      P_FUN_BallotBoxMachine_ANON1 = 3,
      P_FUN_BallotBoxMachine_ANON2 = 5,
      P_FUN_BallotBoxMachine_ANON3 = 7,
      P_FUN_BallotBoxMachine_ANON4 = 9,
      P_FUN_BallotBoxMachine_ANON5 = 11,
      P_FUN_BallotBoxMachine_ANON6 = 13,
      P_FUN_BallotBoxMachine_ANON7 = 15,
      P_FUN_BallotBoxMachine_ANON8 = 17,
      _P_FUNS_BallotBoxMachine_COUNT = 17,
      P_FUN_BallotBoxMachine_ANON9 = 19,
      P_FUN_BallotBoxMachine_ANON10 = 21,
      P_FUN_BallotBoxMachine_ANON11 = 23,
      P_FUN_BallotBoxMachine_ANON12 = 25,
      P_FUN_BallotBoxMachine_ANON13 = 27,
      P_FUN_BallotBoxMachine_ANON14 = 29,
      P_FUN_BallotBoxMachine_ANON15 = 31,
      P_FUN_BallotBoxMachine_ANON16 = 33
    };

    enum P_FUNS_BulletinBoardMachine
    {
      P_FUN_BulletinBoardMachine_ANON0 = 1,
      P_FUN_BulletinBoardMachine_ANON1 = 3,
      P_FUN_BulletinBoardMachine_ANON2 = 5,
      P_FUN_BulletinBoardMachine_ANON3 = 7,
      _P_FUNS_BulletinBoardMachine_COUNT = 8,
      P_FUN_BulletinBoardMachine_ANON4 = 9,
      P_FUN_BulletinBoardMachine_ANON5 = 11,
      P_FUN_BulletinBoardMachine_ANON6 = 13,
      P_FUN_BulletinBoardMachine_ANON7 = 15
    };

    enum P_FUNS_SupervisorMachine
    {
      P_FUN_SupervisorMachine_ANON0 = 1,
      P_FUN_SupervisorMachine_ANON1 = 3,
      P_FUN_SupervisorMachine_ANON2 = 5,
      P_FUN_SupervisorMachine_ANON3 = 7,
      P_FUN_SupervisorMachine_ANON4 = 9,
      P_FUN_SupervisorMachine_ANON5 = 11,
      _P_FUNS_SupervisorMachine_COUNT = 11,
      P_FUN_SupervisorMachine_ANON6 = 13,
      P_FUN_SupervisorMachine_ANON7 = 15,
      P_FUN_SupervisorMachine_ANON8 = 17,
      P_FUN_SupervisorMachine_ANON9 = 19,
      P_FUN_SupervisorMachine_DoCloseElection = 21
    };

    enum P_FUNS_TabulationTellerMachine
    {
      P_FUN_TabulationTellerMachine_ANON0 = 1,
      P_FUN_TabulationTellerMachine_ANON1 = 3,
      P_FUN_TabulationTellerMachine_ANON2 = 5,
      P_FUN_TabulationTellerMachine_ANON3 = 7,
      _P_FUNS_TabulationTellerMachine_COUNT = 7,
      P_FUN_TabulationTellerMachine_ANON4 = 9,
      P_FUN_TabulationTellerMachine_ANON5 = 11,
      P_FUN_TabulationTellerMachine_ANON6 = 13
    };

    enum P_FUNS_TamperEvidentLogMachine
    {
      P_FUN_TamperEvidentLogMachine_ANON0 = 1,
      P_FUN_TamperEvidentLogMachine_ANON1 = 3,
      P_FUN_TamperEvidentLogMachine_ANON2 = 5,
      P_FUN_TamperEvidentLogMachine_ANON3 = 7,
      _P_FUNS_TamperEvidentLogMachine_COUNT = 7,
      P_FUN_TamperEvidentLogMachine_ANON4 = 9,
      P_FUN_TamperEvidentLogMachine_ANON5 = 11,
      P_FUN_TamperEvidentLogMachine_ANON6 = 13
    };

    enum P_FUNS_VotingClientMachine
    {
      P_FUN_VotingClientMachine_ANON0 = 1,
      P_FUN_VotingClientMachine_ANON1 = 3,
      P_FUN_VotingClientMachine_ANON2 = 5,
      P_FUN_VotingClientMachine_ANON3 = 7,
      P_FUN_VotingClientMachine_ANON4 = 9,
      P_FUN_VotingClientMachine_ANON5 = 11,
      P_FUN_VotingClientMachine_ANON6 = 13,
      P_FUN_VotingClientMachine_ANON7 = 15,
      P_FUN_VotingClientMachine_ANON8 = 17,
      _P_FUNS_VotingClientMachine_COUNT = 17,
      P_FUN_VotingClientMachine_ANON9 = 19,
      P_FUN_VotingClientMachine_ANON10 = 21,
      P_FUN_VotingClientMachine_ANON11 = 23,
      P_FUN_VotingClientMachine_ANON12 = 25,
      P_FUN_VotingClientMachine_ANON13 = 27,
      P_FUN_VotingClientMachine_ReadCredentials = 29,
      P_FUN_VotingClientMachine_ReadOperationToPerform = 31,
      P_FUN_VotingClientMachine_ReadVote = 33
    };

    enum P_STATES_BallotBoxMachine
    {
      P_STATE_BallotBoxMachine_Init = 0,
      P_STATE_BallotBoxMachine_VoteCounting = 1,
      P_STATE_BallotBoxMachine_WaitForGetResultsQuery = 2,
      P_STATE_BallotBoxMachine_WaitForVotes = 3,
      _P_STATES_BallotBoxMachine_COUNT = 4
    };

    enum P_STATES_BulletinBoardMachine
    {
      P_STATE_BulletinBoardMachine_ComputeResults = 0,
      P_STATE_BulletinBoardMachine_Init = 1,
      _P_STATES_BulletinBoardMachine_COUNT = 2
    };

    enum P_STATES_SupervisorMachine
    {
      P_STATE_SupervisorMachine_CloseElection = 0,
      P_STATE_SupervisorMachine_Init = 1,
      P_STATE_SupervisorMachine_StartElection = 2,
      _P_STATES_SupervisorMachine_COUNT = 3
    };

    enum P_STATES_TabulationTellerMachine
    {
      P_STATE_TabulationTellerMachine_Init = 0,
      P_STATE_TabulationTellerMachine_WaiForDoTally = 1,
      _P_STATES_TabulationTellerMachine_COUNT = 2
    };

    enum P_STATES_TamperEvidentLogMachine
    {
      P_STATE_TamperEvidentLogMachine_Init = 0,
      P_STATE_TamperEvidentLogMachine_WaitForRequests = 1,
      _P_STATES_TamperEvidentLogMachine_COUNT = 2
    };

    enum P_STATES_VotingClientMachine
    {
      P_STATE_VotingClientMachine_Done = 0,
      P_STATE_VotingClientMachine_Init = 1,
      P_STATE_VotingClientMachine_SubmitVote = 2,
      P_STATE_VotingClientMachine_ValidateResults = 3,
      _P_STATES_VotingClientMachine_COUNT = 4
    };

    enum P_VARS_BallotBoxMachine
    {
      P_VAR_BallotBoxMachine_appendOnlyLog = 0,
      P_VAR_BallotBoxMachine_bulletinBoard = 1,
      _P_VARS_BallotBoxMachine_COUNT = 2
    };

    enum P_VARS_BulletinBoardMachine
    {
      P_VAR_BulletinBoardMachine_allVotes = 0,
      P_VAR_BulletinBoardMachine_electionResults = 1,
      _P_VARS_BulletinBoardMachine_COUNT = 2
    };

    enum P_VARS_SupervisorMachine
    {
      P_VAR_SupervisorMachine_bBoard = 0,
      P_VAR_SupervisorMachine_bBox = 1,
      P_VAR_SupervisorMachine_tTeller = 2,
      _P_VARS_SupervisorMachine_COUNT = 3
    };

    enum P_VARS_TabulationTellerMachine
    {
      P_VAR_TabulationTellerMachine_allVotes = 0,
      P_VAR_TabulationTellerMachine_bulletinBoard = 1,
      _P_VARS_TabulationTellerMachine_COUNT = 2
    };

    enum P_VARS_TamperEvidentLogMachine
    {
      P_VAR_TamperEvidentLogMachine_log = 0,
      P_VAR_TamperEvidentLogMachine_parent = 1,
      _P_VARS_TamperEvidentLogMachine_COUNT = 2
    };

    enum P_VARS_VotingClientMachine
    {
      P_VAR_VotingClientMachine_ballotBox = 0,
      P_VAR_VotingClientMachine_bulletinBoard = 1,
      P_VAR_VotingClientMachine_credentials = 2,
      _P_VARS_VotingClientMachine_COUNT = 3
    };

    PRT_VALUE *P_FUN_SupervisorMachine_DoCloseElection_FOREIGN(PRT_MACHINEINST *context);

    PRT_VALUE *P_FUN_VotingClientMachine_ReadCredentials_FOREIGN(PRT_MACHINEINST *context);

    PRT_VALUE *P_FUN_VotingClientMachine_ReadOperationToPerform_FOREIGN(PRT_MACHINEINST *context);

    PRT_VALUE *P_FUN_VotingClientMachine_ReadVote_FOREIGN(PRT_MACHINEINST *context);

    extern PRT_EVENTDECL P_EVENT_eAddItem_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eAllVotes_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eCloseElection_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eDoTally_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eElectionResults_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eGetElectionResults_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eGetLog_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eMergedVotes_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eRespAddItem_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eRespConfirmVote_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eRespElectionResults_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eRespGetLog_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eStartElection_STRUCT;
    extern PRT_EVENTDECL P_EVENT_eVote_STRUCT;
    extern PRT_EVENTDECL _P_EVENT_HALT_STRUCT;
    extern PRT_EVENTDECL _P_EVENT_NULL_STRUCT;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eCloseElection;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eDoTally;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eGetElectionResults;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eGetElectionResults_eAllVotes;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eGetLog_eAddItem;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eMergedVotes;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eRespAddItem;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eRespConfirmVote;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eRespElectionResults;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eRespGetLog;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eStartElection;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_eVote;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_null;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON10_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON11_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON12_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON13_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON14_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON15_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON16_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON7_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON8_STRUCT;
    extern PRT_FUNDECL P_FUN_BallotBoxMachine_ANON9_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON7_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON7_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON8_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_ANON9_STRUCT;
    extern PRT_FUNDECL P_FUN_SupervisorMachine_DoCloseElection_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON10_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON11_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON12_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON13_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON7_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON8_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ANON9_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ReadCredentials_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ReadOperationToPerform_STRUCT;
    extern PRT_FUNDECL P_FUN_VotingClientMachine_ReadVote_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_BallotBoxMachine_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_BulletinBoardMachine_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_SupervisorMachine_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_TabulationTellerMachine_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_TamperEvidentLogMachine_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_VotingClientMachine_STRUCT;
    extern PRT_PROGRAMDECL P_GEND_PROGRAM;
    extern PRT_TYPE P_GEND_TYPE_AllVotesInBallot;
    extern PRT_TYPE P_GEND_TYPE_ElectionResults;
    extern PRT_TYPE P_GEND_TYPE_Vote;
    extern PRT_UINT32 P_I_BallotBoxMachine;
    extern PRT_UINT32 P_I_BulletinBoardMachine;
    extern PRT_UINT32 P_I_SupervisorMachine;
    extern PRT_UINT32 P_I_TabulationTellerMachine;
    extern PRT_UINT32 P_I_TamperEvidentLogMachine;
    extern PRT_UINT32 P_I_VotingClientMachine;
    extern PRT_UINT32 P_MACHINE_BallotBoxMachine;
    extern PRT_UINT32 P_MACHINE_BulletinBoardMachine;
    extern PRT_UINT32 P_MACHINE_SupervisorMachine;
    extern PRT_UINT32 P_MACHINE_TabulationTellerMachine;
    extern PRT_UINT32 P_MACHINE_TamperEvidentLogMachine;
    extern PRT_UINT32 P_MACHINE_VotingClientMachine;
    #ifdef __cplusplus
      }
    #endif
  #endif
  
