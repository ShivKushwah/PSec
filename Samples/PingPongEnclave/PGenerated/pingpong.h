
  #ifndef P_PINGPONG_H_
    #define P_PINGPONG_H_
    #include "Prt.h"
    #ifdef __cplusplus
      extern "C"{
    #endif
    enum P_FUNS_Main
    {
      P_FUN_Main_ANON0 = 1,
      P_FUN_Main_ANON1 = 3,
      P_FUN_Main_ANON2 = 5,
      P_FUN_Main_ANON3 = 7,
      P_FUN_Main_ANON4 = 9,
      P_FUN_Main_ANON5 = 11,
      P_FUN_Main_ANON6 = 13,
      _P_FUNS_Main_COUNT = 13,
      P_FUN_Main_ANON7 = 15,
      P_FUN_Main_ANON8 = 17,
      P_FUN_Main_ANON9 = 19,
      P_FUN_Main_ANON10 = 21,
      P_FUN_Main_ANON11 = 23,
      P_FUN_Main_ANON12 = 25
    };

    enum P_FUNS_PONG
    {
      P_FUN_PONG_ANON0 = 1,
      P_FUN_PONG_ANON1 = 3,
      P_FUN_PONG_ANON2 = 5,
      P_FUN_PONG_ANON3 = 7,
      _P_FUNS_PONG_COUNT = 8,
      P_FUN_PONG_ANON4 = 9,
      P_FUN_PONG_ANON5 = 11,
      P_FUN_PONG_ANON6 = 13,
      P_FUN_PONG_ANON7 = 15
    };

    enum P_STATES_Main
    {
      P_STATE_Main_Done = 0,
      P_STATE_Main_Ping_Init = 1,
      P_STATE_Main_Ping_SendPing = 2,
      P_STATE_Main_Ping_WaitPong = 3,
      _P_STATES_Main_COUNT = 4
    };

    enum P_STATES_PONG
    {
      P_STATE_PONG_Pong_SendPong = 0,
      P_STATE_PONG_Pong_WaitPing = 1,
      _P_STATES_PONG_COUNT = 2
    };

    enum P_VARS_Main
    {
      P_VAR_Main_pongId = 0,
      _P_VARS_Main_COUNT = 1
    };

    enum P_VARS_PONG
    {
      _P_VARS_PONG_COUNT = 0
    };

    extern PRT_EVENTDECL P_EVENT_Ping_STRUCT;
    extern PRT_EVENTDECL P_EVENT_Pong_STRUCT;
    extern PRT_EVENTDECL P_EVENT_Success_STRUCT;
    extern PRT_EVENTDECL _P_EVENT_HALT_STRUCT;
    extern PRT_EVENTDECL _P_EVENT_NULL_STRUCT;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_Ping;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_Pong;
    extern PRT_EVENTSETDECL P_GEND_EVENTSET_Success;
    extern PRT_FUNDECL P_FUN_Main_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON10_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON11_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON12_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON7_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON8_STRUCT;
    extern PRT_FUNDECL P_FUN_Main_ANON9_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON0_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON1_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON2_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON3_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON4_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON5_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON6_STRUCT;
    extern PRT_FUNDECL P_FUN_PONG_ANON7_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_Main_STRUCT;
    extern PRT_MACHINEDECL P_MACHINE_PONG_STRUCT;
    extern PRT_PROGRAMDECL P_GEND_PROGRAM;
    extern PRT_UINT32 P_I_Main;
    extern PRT_UINT32 P_I_PONG;
    extern PRT_UINT32 P_MACHINE_Main;
    extern PRT_UINT32 P_MACHINE_PONG;
    #ifdef __cplusplus
      }
    #endif
  #endif
  