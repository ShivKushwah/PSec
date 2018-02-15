
  #include "linker.h"
  PRT_UINT32 P_I_BallotBoxMachine = 0;
  PRT_UINT32 P_I_BulletinBoardMachine = 1;
  PRT_UINT32 P_I_SupervisorMachine = 2;
  PRT_UINT32 P_I_TabulationTellerMachine = 3;
  PRT_UINT32 P_I_TamperEvidentLogMachine = 4;
  PRT_UINT32 P_I_VotingClientMachine = 5;
  PRT_UINT32 P_MACHINE_BallotBoxMachine = 0;
  PRT_UINT32 P_MACHINE_BulletinBoardMachine = 1;
  PRT_UINT32 P_MACHINE_SupervisorMachine = 2;
  PRT_UINT32 P_MACHINE_TabulationTellerMachine = 3;
  PRT_UINT32 P_MACHINE_TamperEvidentLogMachine = 4;
  PRT_UINT32 P_MACHINE_VotingClientMachine = 5;
  PRT_UINT32 _P_FOREIGN_TYPES_COUNT = 0;
  PRT_UINT32 _P_I_COUNT = 6;
  PRT_UINT32 _P_MACHINES_COUNT = 6;
  PRT_UINT32 P_GEND_LINKMAP_BallotBoxMachine[] = 
  {
    -1L,
    -1L,
    4U,
    -1L
  };
  PRT_UINT32 P_GEND_LINKMAP_BulletinBoardMachine[] = 
  {
    -1L,
    -1L,
    -1L,
    -1L
  };
  PRT_UINT32 P_GEND_LINKMAP_SupervisorMachine[] = 
  {
    0U,
    1U,
    -1L,
    5U
  };
  PRT_UINT32 P_GEND_LINKMAP_TabulationTellerMachine[] = 
  {
    -1L,
    -1L,
    -1L,
    -1L
  };
  PRT_UINT32 P_GEND_LINKMAP_TamperEvidentLogMachine[] = 
  {
    -1L,
    -1L,
    -1L,
    -1L
  };
  PRT_UINT32 P_GEND_LINKMAP_VotingClientMachine[] = 
  {
    -1L,
    -1L,
    -1L,
    -1L
  };
  PRT_UINT32 P_GEND_MACHDEF_MAP[] = 
  {
    0U,
    1U,
    2U,
    3U,
    4U,
    5U
  };
  PRT_EVENTDECL *P_GEND_EVENTS[] = 
  {
    &_P_EVENT_NULL_STRUCT,
    &_P_EVENT_HALT_STRUCT,
    &P_EVENT_eAddItem_STRUCT,
    &P_EVENT_eAllVotes_STRUCT,
    &P_EVENT_eCloseElection_STRUCT,
    &P_EVENT_eDoTally_STRUCT,
    &P_EVENT_eElectionResults_STRUCT,
    &P_EVENT_eGetElectionResults_STRUCT,
    &P_EVENT_eGetLog_STRUCT,
    &P_EVENT_eMergedVotes_STRUCT,
    &P_EVENT_eRespAddItem_STRUCT,
    &P_EVENT_eRespConfirmVote_STRUCT,
    &P_EVENT_eRespElectionResults_STRUCT,
    &P_EVENT_eRespGetLog_STRUCT,
    &P_EVENT_eStartElection_STRUCT,
    &P_EVENT_eVote_STRUCT
  };
  PRT_MACHINEDECL *P_GEND_MACHINES[] = 
  {
    &P_MACHINE_BallotBoxMachine_STRUCT,
    &P_MACHINE_BulletinBoardMachine_STRUCT,
    &P_MACHINE_SupervisorMachine_STRUCT,
    &P_MACHINE_TabulationTellerMachine_STRUCT,
    &P_MACHINE_TamperEvidentLogMachine_STRUCT,
    &P_MACHINE_VotingClientMachine_STRUCT
  };
  PRT_UINT32 *P_GEND_LINKMAP[] = 
  {
    P_GEND_LINKMAP_BallotBoxMachine,
    P_GEND_LINKMAP_BulletinBoardMachine,
    P_GEND_LINKMAP_SupervisorMachine,
    P_GEND_LINKMAP_TabulationTellerMachine,
    P_GEND_LINKMAP_TamperEvidentLogMachine,
    P_GEND_LINKMAP_VotingClientMachine
  };
  PRT_PROGRAMDECL P_GEND_PROGRAM = 
  {
    16U,
    6U,
    0U,
    0U,
    P_GEND_EVENTS,
    P_GEND_MACHINES,
    NULL,
    NULL,
    P_GEND_LINKMAP,
    P_GEND_MACHDEF_MAP,
    0U,
    NULL
  };
  