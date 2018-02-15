
  #include "SecuredVoting.h"
  #define P_SEQ
  #define P_STMT_0(s, x0, f0) P_SEQ(p_tmp_stmt_0 = (x0), (s), ((f0) ? PrtFreeValue(p_tmp_stmt_0) : 0U))
  #define P_STMT_1(s, x1, f1, x0, f0) P_SEQ(p_tmp_stmt_0 = (x0), p_tmp_stmt_1 = (x1), (s), ((f0) ? PrtFreeValue(p_tmp_stmt_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_stmt_1) : 0U))
  #define P_BOOL_EXPR(x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_bool = PrtPrimGetBool(p_tmp_expr_0), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), p_tmp_bool)
  #define P_EXPR_0(x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_0)
  #define P_EXPR_1(x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), p_tmp_expr_1)
  #define P_EXPR_2(x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), p_tmp_expr_2)
  #define P_EXPR_3(x3, f3, x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), p_tmp_expr_3 = (x3), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), ((f2) ? PrtFreeValue(p_tmp_expr_2) : 0U), p_tmp_expr_3)
  #define P_EXPR_4(x4, f4, x3, f3, x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), p_tmp_expr_3 = (x3), p_tmp_expr_4 = (x4), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), ((f2) ? PrtFreeValue(p_tmp_expr_2) : 0U), ((f3) ? PrtFreeValue(p_tmp_expr_3) : 0U), p_tmp_expr_4)
  #define P_EXPR_5(x5, f5, x4, f4, x3, f3, x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), p_tmp_expr_3 = (x3), p_tmp_expr_4 = (x4), p_tmp_expr_5 = (x5), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), ((f2) ? PrtFreeValue(p_tmp_expr_2) : 0U), ((f3) ? PrtFreeValue(p_tmp_expr_3) : 0U), ((f4) ? PrtFreeValue(p_tmp_expr_4) : 0U), p_tmp_expr_5)
  #define P_EXPR_6(x6, f6, x5, f5, x4, f4, x3, f3, x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), p_tmp_expr_3 = (x3), p_tmp_expr_4 = (x4), p_tmp_expr_5 = (x5), p_tmp_expr_6 = (x6), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), ((f2) ? PrtFreeValue(p_tmp_expr_2) : 0U), ((f3) ? PrtFreeValue(p_tmp_expr_3) : 0U), ((f4) ? PrtFreeValue(p_tmp_expr_4) : 0U), ((f5) ? PrtFreeValue(p_tmp_expr_5) : 0U), p_tmp_expr_6)
  #define P_EXPR_7(x7, f7, x6, f6, x5, f5, x4, f4, x3, f3, x2, f2, x1, f1, x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_expr_1 = (x1), p_tmp_expr_2 = (x2), p_tmp_expr_3 = (x3), p_tmp_expr_4 = (x4), p_tmp_expr_5 = (x5), p_tmp_expr_6 = (x6), p_tmp_expr_7 = (x7), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), ((f1) ? PrtFreeValue(p_tmp_expr_1) : 0U), ((f2) ? PrtFreeValue(p_tmp_expr_2) : 0U), ((f3) ? PrtFreeValue(p_tmp_expr_3) : 0U), ((f4) ? PrtFreeValue(p_tmp_expr_4) : 0U), ((f5) ? PrtFreeValue(p_tmp_expr_5) : 0U), ((f6) ? PrtFreeValue(p_tmp_expr_6) : 0U), p_tmp_expr_7)
  #define P_TUPLE_0(t, x0) P_SEQ(p_tmp_tuple = PrtMkDefaultValue(t), PrtTupleSet(p_tmp_tuple, 0U, (x0)), p_tmp_tuple)
  #define P_TUPLE_1(t, x0, x1) P_SEQ(p_tmp_tuple = PrtMkDefaultValue(t), PrtTupleSet(p_tmp_tuple, 0U, (x0)), PrtTupleSet(p_tmp_tuple, 1U, (x1)), p_tmp_tuple)
  static PRT_TYPE P_GEND_TYPE_0 = 
  {
    PRT_KIND_ANY,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_1 = 
  {
    PRT_KIND_BOOL,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_2 = 
  {
    PRT_KIND_EVENT,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_3 = 
  {
    PRT_KIND_INT,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_4 = 
  {
    PRT_KIND_MACHINE,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_5 = 
  {
    PRT_KIND_NULL,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_6 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_TYPE P_GEND_TYPE_7 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_TYPE P_GEND_TYPE_8 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_TYPE P_GEND_TYPE_9 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_TYPE P_GEND_TYPE_10 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_MAPTYPE P_GEND_TYPE_MAP_11 = 
  {
    &P_GEND_TYPE_3,
    &P_GEND_TYPE_3
  };
  static PRT_TYPE P_GEND_TYPE_11 = 
  {
    PRT_KIND_MAP,
    
    {
        &P_GEND_TYPE_MAP_11
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_12[] = 
  {
    "doVoting"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_12[] = 
  {
    &P_GEND_TYPE_1
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_12 = 
  {
    1,
    P_GEND_TYPE_NMDTUP_NARR_12,
    P_GEND_TYPE_NMDTUP_TARR_12
  };
  static PRT_TYPE P_GEND_TYPE_12 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_12
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_13[] = 
  {
    "i"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_13[] = 
  {
    &P_GEND_TYPE_3
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_13 = 
  {
    1,
    P_GEND_TYPE_NMDTUP_NARR_13,
    P_GEND_TYPE_NMDTUP_TARR_13
  };
  static PRT_TYPE P_GEND_TYPE_13 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_13
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_14[] = 
  {
    "res"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_14[] = 
  {
    &P_GEND_TYPE_1
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_14 = 
  {
    1,
    P_GEND_TYPE_NMDTUP_NARR_14,
    P_GEND_TYPE_NMDTUP_TARR_14
  };
  static PRT_TYPE P_GEND_TYPE_14 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_14
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_15[] = 
  {
    "vote"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_15[] = 
  {
    &P_GEND_TYPE_3
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_15 = 
  {
    1,
    P_GEND_TYPE_NMDTUP_NARR_15,
    P_GEND_TYPE_NMDTUP_TARR_15
  };
  static PRT_TYPE P_GEND_TYPE_15 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_15
    }
  };
  static PRT_SEQTYPE P_GEND_TYPE_SEQ_16 = 
  {
    &P_GEND_TYPE_0
  };
  static PRT_TYPE P_GEND_TYPE_16 = 
  {
    PRT_KIND_SEQ,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_SEQ_16
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_17[] = 
  {
    "bBox",
    "bBoard"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_17[] = 
  {
    &P_GEND_TYPE_4,
    &P_GEND_TYPE_4
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_17 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_17,
    P_GEND_TYPE_NMDTUP_TARR_17
  };
  static PRT_TYPE P_GEND_TYPE_17 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_17
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_18[] = 
  {
    "credentials",
    "vote"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_18[] = 
  {
    &P_GEND_TYPE_3,
    &P_GEND_TYPE_3
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_18 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_18,
    P_GEND_TYPE_NMDTUP_TARR_18
  };
  static PRT_TYPE P_GEND_TYPE_18 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_18
    }
  };
  static PRT_TYPE *P_GEND_TYPE_TUP_ARR_19[] = 
  {
    &P_GEND_TYPE_3,
    &P_GEND_TYPE_0
  };
  static PRT_TUPTYPE P_GEND_TYPE_TUP_19 = 
  {
    2,
    P_GEND_TYPE_TUP_ARR_19
  };
  static PRT_TYPE P_GEND_TYPE_19 = 
  {
    PRT_KIND_TUPLE,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_TUP_19
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_20[] = 
  {
    "allVotes",
    "whoWon"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_20[] = 
  {
    &P_GEND_TYPE_11,
    &P_GEND_TYPE_3
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_20 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_20,
    P_GEND_TYPE_NMDTUP_TARR_20
  };
  static PRT_TYPE P_GEND_TYPE_20 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_20
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_21[] = 
  {
    "result",
    "i"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_21[] = 
  {
    &P_GEND_TYPE_11,
    &P_GEND_TYPE_3
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_21 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_21,
    P_GEND_TYPE_NMDTUP_TARR_21
  };
  static PRT_TYPE P_GEND_TYPE_21 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_21
    }
  };
  static PRT_SEQTYPE P_GEND_TYPE_SEQ_22 = 
  {
    &P_GEND_TYPE_18
  };
  static PRT_TYPE P_GEND_TYPE_22 = 
  {
    PRT_KIND_SEQ,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_SEQ_22
    }
  };
  static PRT_TYPE *P_GEND_TYPE_TUP_ARR_23[] = 
  {
    &P_GEND_TYPE_18,
    &P_GEND_TYPE_4
  };
  static PRT_TUPTYPE P_GEND_TYPE_TUP_23 = 
  {
    2,
    P_GEND_TYPE_TUP_ARR_23
  };
  static PRT_TYPE P_GEND_TYPE_23 = 
  {
    PRT_KIND_TUPLE,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_TUP_23
    }
  };
  static PRT_TYPE *P_GEND_TYPE_TUP_ARR_24[] = 
  {
    &P_GEND_TYPE_18,
    &P_GEND_TYPE_10
  };
  static PRT_TUPTYPE P_GEND_TYPE_TUP_24 = 
  {
    2,
    P_GEND_TYPE_TUP_ARR_24
  };
  static PRT_TYPE P_GEND_TYPE_24 = 
  {
    PRT_KIND_TUPLE,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_TUP_24
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_25[] = 
  {
    "ballotId",
    "votes"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_25[] = 
  {
    &P_GEND_TYPE_3,
    &P_GEND_TYPE_22
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_25 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_25,
    P_GEND_TYPE_NMDTUP_TARR_25
  };
  static PRT_TYPE P_GEND_TYPE_25 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_25
    }
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eCloseElection_INNER[] = 
  {
    &P_EVENT_eCloseElection_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eDoTally_INNER[] = 
  {
    &P_EVENT_eDoTally_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eGetElectionResults_INNER[] = 
  {
    &P_EVENT_eGetElectionResults_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eGetElectionResults_eAllVotes_INNER[] = 
  {
    &P_EVENT_eAllVotes_STRUCT,
    &P_EVENT_eGetElectionResults_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eGetLog_eAddItem_INNER[] = 
  {
    &P_EVENT_eAddItem_STRUCT,
    &P_EVENT_eGetLog_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eMergedVotes_INNER[] = 
  {
    &P_EVENT_eMergedVotes_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eRespAddItem_INNER[] = 
  {
    &P_EVENT_eRespAddItem_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eRespConfirmVote_INNER[] = 
  {
    &P_EVENT_eRespConfirmVote_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eRespElectionResults_INNER[] = 
  {
    &P_EVENT_eRespElectionResults_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eRespGetLog_INNER[] = 
  {
    &P_EVENT_eRespGetLog_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eStartElection_INNER[] = 
  {
    &P_EVENT_eStartElection_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_eVote_INNER[] = 
  {
    &P_EVENT_eVote_STRUCT
  };
  PRT_EVENTDECL *P_GEND_EVENTSET_null_INNER[] = 
  {
    &_P_EVENT_NULL_STRUCT
  };
  static PRT_VALUE P_GEND_VALUE_0 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        0U
    }
  };
  static PRT_VALUE P_GEND_VALUE_1 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        1U
    }
  };
  static PRT_VALUE P_GEND_VALUE_2 = 
  {
    PRT_VALUE_KIND_BOOL,
    
    {
        PRT_TRUE
    }
  };
  PRT_EVENTDECL P_EVENT_eAddItem_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eAddItem",
    4294967295U,
    &P_GEND_TYPE_0,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eAllVotes_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eAllVotes",
    4294967295U,
    &P_GEND_TYPE_25,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eCloseElection_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eCloseElection",
    4294967295U,
    &P_GEND_TYPE_5,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eDoTally_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eDoTally",
    4294967295U,
    &P_GEND_TYPE_5,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eElectionResults_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eElectionResults",
    4294967295U,
    &P_GEND_TYPE_11,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eGetElectionResults_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eGetElectionResults",
    4294967295U,
    &P_GEND_TYPE_4,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eGetLog_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eGetLog",
    4294967295U,
    &P_GEND_TYPE_5,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eMergedVotes_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eMergedVotes",
    4294967295U,
    &P_GEND_TYPE_22,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eRespAddItem_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eRespAddItem",
    4294967295U,
    &P_GEND_TYPE_1,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eRespConfirmVote_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eRespConfirmVote",
    4294967295U,
    &P_GEND_TYPE_5,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eRespElectionResults_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eRespElectionResults",
    4294967295U,
    &P_GEND_TYPE_20,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eRespGetLog_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eRespGetLog",
    4294967295U,
    &P_GEND_TYPE_16,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eStartElection_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eStartElection",
    4294967295U,
    &P_GEND_TYPE_5,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_eVote_STRUCT = 
  {
    
    {
        PRT_VALUE_KIND_EVENT,
        0U
    },
    "eVote",
    4294967295U,
    &P_GEND_TYPE_23,
    0U,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET = 
  {
    0U,
    NULL,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eCloseElection = 
  {
    1U,
    P_GEND_EVENTSET_eCloseElection_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eDoTally = 
  {
    1U,
    P_GEND_EVENTSET_eDoTally_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eGetElectionResults = 
  {
    1U,
    P_GEND_EVENTSET_eGetElectionResults_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eGetElectionResults_eAllVotes = 
  {
    2U,
    P_GEND_EVENTSET_eGetElectionResults_eAllVotes_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eGetLog_eAddItem = 
  {
    2U,
    P_GEND_EVENTSET_eGetLog_eAddItem_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eMergedVotes = 
  {
    1U,
    P_GEND_EVENTSET_eMergedVotes_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eRespAddItem = 
  {
    1U,
    P_GEND_EVENTSET_eRespAddItem_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eRespConfirmVote = 
  {
    1U,
    P_GEND_EVENTSET_eRespConfirmVote_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eRespElectionResults = 
  {
    1U,
    P_GEND_EVENTSET_eRespElectionResults_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eRespGetLog = 
  {
    1U,
    P_GEND_EVENTSET_eRespGetLog_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eStartElection = 
  {
    1U,
    P_GEND_EVENTSET_eStartElection_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_eVote = 
  {
    1U,
    P_GEND_EVENTSET_eVote_INNER,
    NULL
  };
  PRT_EVENTSETDECL P_GEND_EVENTSET_null = 
  {
    1U,
    P_GEND_EVENTSET_null_INNER,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_AllVotesInBallot = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_25
    }
  };
  PRT_TYPE P_GEND_TYPE_BallotBoxMachine = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_BulletinBoardMachine = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_ElectionResults = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_20
    }
  };
  PRT_TYPE P_GEND_TYPE_SupervisorMachine = 
  {
    PRT_KIND_MACHINE,
    
    {
        NULL
    }
  };
  PRT_TYPE P_GEND_TYPE_TabulationTellerMachine = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_TamperEvidentLogMachine = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_Vote = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_18
    }
  };
  PRT_TYPE P_GEND_TYPE_VotingClientMachine = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_VARDECL P_GEND_VARS_BallotBoxMachine[] = 
  {
    
    {
        "appendOnlyLog",
        &P_GEND_TYPE_4,
        0U,
        NULL
    },
    
    {
        "bulletinBoard",
        &P_GEND_TYPE_4,
        0U,
        NULL
    }
  };
  PRT_VARDECL P_GEND_VARS_BulletinBoardMachine[] = 
  {
    
    {
        "allVotes",
        &P_GEND_TYPE_22,
        0U,
        NULL
    },
    
    {
        "electionResults",
        &P_GEND_TYPE_11,
        0U,
        NULL
    }
  };
  PRT_VARDECL P_GEND_VARS_SupervisorMachine[] = 
  {
    
    {
        "bBoard",
        &P_GEND_TYPE_4,
        0U,
        NULL
    },
    
    {
        "bBox",
        &P_GEND_TYPE_4,
        0U,
        NULL
    },
    
    {
        "tTeller",
        &P_GEND_TYPE_4,
        0U,
        NULL
    }
  };
  PRT_VARDECL P_GEND_VARS_TabulationTellerMachine[] = 
  {
    
    {
        "allVotes",
        &P_GEND_TYPE_22,
        0U,
        NULL
    },
    
    {
        "bulletinBoard",
        &P_GEND_TYPE_4,
        0U,
        NULL
    }
  };
  PRT_VARDECL P_GEND_VARS_TamperEvidentLogMachine[] = 
  {
    
    {
        "log",
        &P_GEND_TYPE_16,
        0U,
        NULL
    },
    
    {
        "parent",
        &P_GEND_TYPE_4,
        0U,
        NULL
    }
  };
  PRT_VARDECL P_GEND_VARS_VotingClientMachine[] = 
  {
    
    {
        "ballotBox",
        &P_GEND_TYPE_4,
        0U,
        NULL
    },
    
    {
        "bulletinBoard",
        &P_GEND_TYPE_4,
        0U,
        NULL
    },
    
    {
        "credentials",
        &P_GEND_TYPE_3,
        0U,
        NULL
    }
  };
  PRT_TRANSDECL P_GEND_TRANS_BallotBoxMachine_Init[] = 
  {
    
    {
        P_STATE_BallotBoxMachine_Init,
        &P_EVENT_eStartElection_STRUCT,
        P_STATE_BallotBoxMachine_WaitForVotes,
        &P_FUN_BallotBoxMachine_ANON3_STRUCT,
        0U,
        NULL
    }
  };
  PRT_TRANSDECL P_GEND_TRANS_BallotBoxMachine_WaitForVotes[] = 
  {
    
    {
        P_STATE_BallotBoxMachine_WaitForVotes,
        &P_EVENT_eCloseElection_STRUCT,
        P_STATE_BallotBoxMachine_VoteCounting,
        &P_FUN_BallotBoxMachine_ANON6_STRUCT,
        0U,
        NULL
    }
  };
  PRT_TRANSDECL P_GEND_TRANS_VotingClientMachine_SubmitVote[] = 
  {
    
    {
        P_STATE_VotingClientMachine_SubmitVote,
        &P_EVENT_eRespConfirmVote_STRUCT,
        P_STATE_VotingClientMachine_Done,
        &P_FUN_VotingClientMachine_ANON8_STRUCT,
        0U,
        NULL
    }
  };
  PRT_VALUE *P_FUN_SupervisorMachine_DoCloseElection_IMPL(PRT_MACHINEINST *context)
  {
    PRT_MACHINEINST_PRIV *p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
    PRT_FUNSTACK_INFO p_tmp_frame;
    PRT_VALUE *retVal;
    PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
    retVal = P_FUN_SupervisorMachine_DoCloseElection_FOREIGN(context);
    PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
    return retVal;
  }

  PRT_VALUE *P_FUN_VotingClientMachine_ReadCredentials_IMPL(PRT_MACHINEINST *context)
  {
    PRT_MACHINEINST_PRIV *p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
    PRT_FUNSTACK_INFO p_tmp_frame;
    PRT_VALUE *retVal;
    PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
    retVal = P_FUN_VotingClientMachine_ReadCredentials_FOREIGN(context);
    PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
    return retVal;
  }

  PRT_VALUE *P_FUN_VotingClientMachine_ReadOperationToPerform_IMPL(PRT_MACHINEINST *context)
  {
    PRT_MACHINEINST_PRIV *p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
    PRT_FUNSTACK_INFO p_tmp_frame;
    PRT_VALUE *retVal;
    PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
    retVal = P_FUN_VotingClientMachine_ReadOperationToPerform_FOREIGN(context);
    PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
    return retVal;
  }

  PRT_VALUE *P_FUN_VotingClientMachine_ReadVote_IMPL(PRT_MACHINEINST *context)
  {
    PRT_MACHINEINST_PRIV *p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
    PRT_FUNSTACK_INFO p_tmp_frame;
    PRT_VALUE *retVal;
    PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
    retVal = P_FUN_VotingClientMachine_ReadVote_FOREIGN(context);
    PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
    return retVal;
  }

  PRT_DODECL P_GEND_DOS_BallotBoxMachine_Init[] = 
  {
    
    {
        P_STATE_BallotBoxMachine_Init,
        &P_EVENT_eVote_STRUCT,
        &P_FUN_BallotBoxMachine_ANON11_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_BallotBoxMachine_WaitForGetResultsQuery[] = 
  {
    
    {
        P_STATE_BallotBoxMachine_WaitForGetResultsQuery,
        &P_EVENT_eVote_STRUCT,
        &P_FUN_BallotBoxMachine_ANON12_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_BallotBoxMachine_WaitForVotes[] = 
  {
    
    {
        P_STATE_BallotBoxMachine_WaitForVotes,
        &P_EVENT_eVote_STRUCT,
        &P_FUN_BallotBoxMachine_ANON15_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_BulletinBoardMachine_ComputeResults[] = 
  {
    
    {
        P_STATE_BulletinBoardMachine_ComputeResults,
        &P_EVENT_eGetElectionResults_STRUCT,
        &P_FUN_BulletinBoardMachine_ANON5_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_BulletinBoardMachine_Init[] = 
  {
    
    {
        P_STATE_BulletinBoardMachine_Init,
        &P_EVENT_eAllVotes_STRUCT,
        &P_FUN_BulletinBoardMachine_ANON6_STRUCT,
        0U,
        NULL
    },
    
    {
        P_STATE_BulletinBoardMachine_Init,
        &P_EVENT_eGetElectionResults_STRUCT,
        &P_FUN_BulletinBoardMachine_ANON4_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_SupervisorMachine_StartElection[] = 
  {
    
    {
        P_STATE_SupervisorMachine_StartElection,
        &_P_EVENT_NULL_STRUCT,
        &P_FUN_SupervisorMachine_ANON9_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_TabulationTellerMachine_Init[] = 
  {
    
    {
        P_STATE_TabulationTellerMachine_Init,
        &P_EVENT_eMergedVotes_STRUCT,
        &P_FUN_TabulationTellerMachine_ANON5_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_TabulationTellerMachine_WaiForDoTally[] = 
  {
    
    {
        P_STATE_TabulationTellerMachine_WaiForDoTally,
        &P_EVENT_eDoTally_STRUCT,
        &P_FUN_TabulationTellerMachine_ANON6_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_TamperEvidentLogMachine_WaitForRequests[] = 
  {
    
    {
        P_STATE_TamperEvidentLogMachine_WaitForRequests,
        &P_EVENT_eAddItem_STRUCT,
        &P_FUN_TamperEvidentLogMachine_ANON6_STRUCT,
        0U,
        NULL
    },
    
    {
        P_STATE_TamperEvidentLogMachine_WaitForRequests,
        &P_EVENT_eGetLog_STRUCT,
        &P_FUN_TamperEvidentLogMachine_ANON4_STRUCT,
        0U,
        NULL
    }
  };
  PRT_DODECL P_GEND_DOS_VotingClientMachine_ValidateResults[] = 
  {
    
    {
        P_STATE_VotingClientMachine_ValidateResults,
        &P_EVENT_eRespElectionResults_STRUCT,
        &P_FUN_VotingClientMachine_ANON13_STRUCT,
        0U,
        NULL
    }
  };
  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (P_BOOL_EXPR(P_EXPR_0(p_tmp_frame.locals[1U], PRT_FALSE), PRT_FALSE))
      {
        P_STMT_1(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_stmt_0), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_stmt_0), p_tmp_stmt_1, 0U)), P_EXPR_0(&P_EVENT_eRespConfirmVote_STRUCT.value, PRT_FALSE), PRT_FALSE, P_EXPR_1(PrtTupleGetNC(p_tmp_expr_0, 1), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      }
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON10_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON11_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      PrtPrintf("Vote ignored, voting has not started yet !!");
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON12_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      PrtPrintf("Vote ignored, voting phase is over");
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON13_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_expr_4;
      PRT_VALUE *p_tmp_expr_5;
      PRT_VALUE *p_tmp_expr_6;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_tuple;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_BallotBoxMachine_bulletinBoard], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eAllVotes_STRUCT.value, PRT_FALSE), P_EXPR_6(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_5), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_5), p_tmp_expr_4, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_3), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, P_TUPLE_1(&P_GEND_TYPE_25, p_tmp_expr_1, p_tmp_expr_2), PRT_TRUE, PrtCastValue(p_tmp_expr_0, &P_GEND_TYPE_22), PRT_FALSE, &P_GEND_VALUE_0, PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON14_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_BallotBoxMachine_bulletinBoard, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      P_EXPR_1(P_SEQ(p_tmp_funstmt_ret = PrtCloneValue(PrtMkInterface(context, P_I_TamperEvidentLogMachine, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0)->id), NULL), PRT_FALSE, p_tmp_mach_priv->id, PRT_FALSE);
      PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_BallotBoxMachine_appendOnlyLog, p_tmp_funstmt_ret, PRT_FALSE);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON15_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_expr_4;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 0U)
      {
        goto L0;
      }
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_BallotBoxMachine_appendOnlyLog], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eAddItem_STRUCT.value, PRT_FALSE), P_EXPR_4(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_3), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_3), p_tmp_expr_2, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_1), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, PrtTupleGetNC(p_tmp_expr_0, 0), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE));
      L0:
      if (p_tmp_frame.rcase == NULL && !PrtReceive(p_tmp_mach_priv, &p_tmp_frame, 0U))
      {
        return NULL;
      }
      (p_tmp_frame.rcase->fun->implementation)(context);
      if (p_tmp_mach_priv->receive != NULL)
      {
        PrtPushFrame(p_tmp_mach_priv, &p_tmp_frame);
        return NULL;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      p_tmp_frame.rcase = NULL;
      p_tmp_frame.returnTo = 0x0FFFFU;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON16_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 1U)
      {
        goto L1;
      }
      P_STMT_1(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_stmt_0), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_stmt_0), p_tmp_stmt_1, 0U)), P_EXPR_0(&P_EVENT_eGetLog_STRUCT.value, PRT_FALSE), PRT_FALSE, P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_BallotBoxMachine_appendOnlyLog], PRT_FALSE), PRT_FALSE);
      L1:
      if (p_tmp_frame.rcase == NULL && !PrtReceive(p_tmp_mach_priv, &p_tmp_frame, 1U))
      {
        return NULL;
      }
      (p_tmp_frame.rcase->fun->implementation)(context);
      if (p_tmp_mach_priv->receive != NULL)
      {
        PrtPushFrame(p_tmp_mach_priv, &p_tmp_frame);
        return NULL;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      p_tmp_frame.rcase = NULL;
      p_tmp_frame.returnTo = 0x0FFFFU;
      PrtGoto(p_tmp_mach_priv, P_STATE_BallotBoxMachine_WaitForGetResultsQuery, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON7_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON8_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BallotBoxMachine_ANON9_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      PrtPrintf("Election Results not Available");
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_expr_4;
      PRT_VALUE *p_tmp_expr_5;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_tuple;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_frame.locals[0U], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eRespElectionResults_STRUCT.value, PRT_FALSE), P_EXPR_5(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_4), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_4), p_tmp_expr_3, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_2), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, P_TUPLE_1(&P_GEND_TYPE_20, p_tmp_expr_0, p_tmp_expr_1), PRT_TRUE, &P_GEND_VALUE_0, PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_BulletinBoardMachine_electionResults], PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_BulletinBoardMachine_allVotes, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_1(PrtTupleGetNC(p_tmp_expr_0, 1), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      PrtGoto(p_tmp_mach_priv, P_STATE_BulletinBoardMachine_ComputeResults, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_BulletinBoardMachine_ANON7_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetLocalVarEx(p_tmp_frame.locals, 1U, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(&P_GEND_VALUE_0, PRT_FALSE), PRT_FALSE);
      while (P_BOOL_EXPR(P_EXPR_3(PrtMkBoolValue(PrtPrimGetInt(p_tmp_expr_1) < PrtPrimGetInt(p_tmp_expr_2)), PRT_TRUE, PrtMkIntValue(PrtSeqSizeOf(p_tmp_expr_0)), PRT_TRUE, p_tmp_frame.locals[1U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_BulletinBoardMachine_allVotes], PRT_FALSE), PRT_TRUE))
      {
        P_STMT_1(PrtMapUpdateEx(p_tmp_mach_priv->varValues[P_VAR_BulletinBoardMachine_electionResults], p_tmp_stmt_1, PRT_TRUE, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_3(PrtTupleGetNC(p_tmp_expr_2, 0), PRT_FALSE, PrtSeqGetNC(p_tmp_expr_0, p_tmp_expr_1), PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_BulletinBoardMachine_allVotes], PRT_FALSE), PRT_FALSE, P_EXPR_3(PrtTupleGetNC(p_tmp_expr_2, 1), PRT_FALSE, PrtSeqGetNC(p_tmp_expr_0, p_tmp_expr_1), PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_BulletinBoardMachine_allVotes], PRT_FALSE), PRT_FALSE);
        P_STMT_0(PrtSetLocalVarEx(p_tmp_frame.locals, 1U, p_tmp_stmt_0, !PRT_TRUE), P_EXPR_2(PrtMkIntValue(PrtPrimGetInt(p_tmp_expr_0) + PrtPrimGetInt(p_tmp_expr_1)), PRT_TRUE, &P_GEND_VALUE_1, PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE), PRT_FALSE);
      }
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_1(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_stmt_0), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_stmt_0), p_tmp_stmt_1, 0U)), P_EXPR_0(&P_EVENT_eStartElection_STRUCT.value, PRT_FALSE), PRT_FALSE, P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBox], PRT_FALSE), PRT_FALSE);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON7_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_tuple;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      p_tmp_funstmt_ret = PrtCloneValue(PrtMkInterface(context, P_I_BulletinBoardMachine, 0U)->id);
      PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_SupervisorMachine_bBoard, p_tmp_funstmt_ret, PRT_FALSE);
      P_EXPR_1(P_SEQ(p_tmp_funstmt_ret = PrtCloneValue(PrtMkInterface(context, P_I_BallotBoxMachine, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0)->id), NULL), PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBoard], PRT_FALSE);
      PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_SupervisorMachine_bBox, p_tmp_funstmt_ret, PRT_FALSE);
      P_EXPR_3(P_SEQ(p_tmp_funstmt_ret = PrtCloneValue(PrtMkInterface(context, P_I_VotingClientMachine, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_2)->id), NULL), PRT_FALSE, P_TUPLE_1(&P_GEND_TYPE_17, p_tmp_expr_1, p_tmp_expr_0), PRT_TRUE, p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBox], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBoard], PRT_FALSE);
      if (p_tmp_funstmt_ret != NULL)
      {
        PrtFreeValue(p_tmp_funstmt_ret);
      }
      P_EXPR_3(P_SEQ(p_tmp_funstmt_ret = PrtCloneValue(PrtMkInterface(context, P_I_VotingClientMachine, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_2)->id), NULL), PRT_FALSE, P_TUPLE_1(&P_GEND_TYPE_17, p_tmp_expr_1, p_tmp_expr_0), PRT_TRUE, p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBox], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBoard], PRT_FALSE);
      if (p_tmp_funstmt_ret != NULL)
      {
        PrtFreeValue(p_tmp_funstmt_ret);
      }
      PrtGoto(p_tmp_mach_priv, P_STATE_SupervisorMachine_StartElection, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON8_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_1(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_stmt_0), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_stmt_0), p_tmp_stmt_1, 0U)), P_EXPR_0(&P_EVENT_eCloseElection_STRUCT.value, PRT_FALSE), PRT_FALSE, P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_SupervisorMachine_bBox], PRT_FALSE), PRT_FALSE);
      P_STMT_0(PrtRaise(p_tmp_mach_priv, p_tmp_stmt_0, 0U), P_EXPR_0(&_P_EVENT_HALT_STRUCT.value, PRT_FALSE), PRT_FALSE);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_SupervisorMachine_ANON9_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 0U)
      {
        goto L0;
      }
      PrtPushNewFrame(p_tmp_mach_priv, PRT_FALSE, &P_FUN_SupervisorMachine_DoCloseElection_STRUCT);
      L0:
      p_tmp_funstmt_ret = PrtWrapFunStmt(&p_tmp_frame, 0U, p_tmp_mach_priv, &P_FUN_SupervisorMachine_DoCloseElection_STRUCT);
      if (p_tmp_mach_priv->receive != NULL)
      {
        return p_tmp_funstmt_ret;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      PrtSetLocalVarEx(p_tmp_frame.locals, 1U, p_tmp_funstmt_ret, PRT_FALSE);
      if (P_BOOL_EXPR(P_EXPR_0(p_tmp_frame.locals[1U], PRT_FALSE), PRT_FALSE))
      {
        PrtGoto(p_tmp_mach_priv, P_STATE_SupervisorMachine_CloseElection, 0U);
        goto P_EXIT_FUN;
      }
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_TabulationTellerMachine_bulletinBoard, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_TabulationTellerMachine_allVotes, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      PrtGoto(p_tmp_mach_priv, P_STATE_TabulationTellerMachine_WaiForDoTally, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TabulationTellerMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_stmt_1;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetLocalVarEx(p_tmp_frame.locals, 2U, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(&P_GEND_VALUE_0, PRT_FALSE), PRT_FALSE);
      while (P_BOOL_EXPR(P_EXPR_3(PrtMkBoolValue(PrtPrimGetInt(p_tmp_expr_1) < PrtPrimGetInt(p_tmp_expr_2)), PRT_TRUE, PrtMkIntValue(PrtSeqSizeOf(p_tmp_expr_0)), PRT_TRUE, p_tmp_frame.locals[2U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_TabulationTellerMachine_allVotes], PRT_FALSE), PRT_TRUE))
      {
        P_STMT_1(PrtMapUpdateEx(p_tmp_frame.locals[1U], p_tmp_stmt_1, PRT_TRUE, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_3(PrtTupleGetNC(p_tmp_expr_2, 0), PRT_FALSE, PrtSeqGetNC(p_tmp_expr_0, p_tmp_expr_1), PRT_FALSE, p_tmp_frame.locals[2U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_TabulationTellerMachine_allVotes], PRT_FALSE), PRT_FALSE, P_EXPR_3(PrtTupleGetNC(p_tmp_expr_2, 1), PRT_FALSE, PrtSeqGetNC(p_tmp_expr_0, p_tmp_expr_1), PRT_FALSE, p_tmp_frame.locals[2U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_TabulationTellerMachine_allVotes], PRT_FALSE), PRT_FALSE);
        P_STMT_0(PrtSetLocalVarEx(p_tmp_frame.locals, 2U, p_tmp_stmt_0, !PRT_TRUE), P_EXPR_2(PrtMkIntValue(PrtPrimGetInt(p_tmp_expr_0) + PrtPrimGetInt(p_tmp_expr_1)), PRT_TRUE, &P_GEND_VALUE_1, PRT_FALSE, p_tmp_frame.locals[2U], PRT_FALSE), PRT_FALSE);
      }
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_TabulationTellerMachine_bulletinBoard], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eElectionResults_STRUCT.value, PRT_FALSE), P_EXPR_3(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_2), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_2), p_tmp_expr_1, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_TamperEvidentLogMachine_parent], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eRespGetLog_STRUCT.value, PRT_FALSE), P_EXPR_3(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_2), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_2), p_tmp_expr_1, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_TamperEvidentLogMachine_log], PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_TamperEvidentLogMachine_parent, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_0(p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      PrtGoto(p_tmp_mach_priv, P_STATE_TamperEvidentLogMachine_WaitForRequests, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_TamperEvidentLogMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      PRT_VALUE *p_tmp_tuple;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      P_STMT_0(PrtSeqInsertEx(p_tmp_mach_priv->varValues[P_VAR_TamperEvidentLogMachine_log], PrtTupleGetNC(p_tmp_stmt_0, 0U), PrtTupleGetNC(p_tmp_stmt_0, 1U), PRT_FALSE), P_EXPR_3(P_TUPLE_1(&P_GEND_TYPE_19, p_tmp_expr_2, p_tmp_expr_0), PRT_TRUE, PrtMkIntValue(PrtSeqSizeOf(p_tmp_expr_1)), PRT_TRUE, p_tmp_mach_priv->varValues[P_VAR_TamperEvidentLogMachine_log], PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      PrtFree(PrtTupleGetNC(p_tmp_stmt_0, 0U));
      PrtFree(p_tmp_stmt_0->valueUnion.tuple->values);
      PrtFree(p_tmp_stmt_0->valueUnion.tuple);
      PrtFree(p_tmp_stmt_0);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_TamperEvidentLogMachine_parent], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eRespAddItem_STRUCT.value, PRT_FALSE), P_EXPR_3(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_2), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_2), p_tmp_expr_1, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, &P_GEND_VALUE_2, PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON0_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON10_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      PrtPrintf("Operation successfully performed, closing client safely");
      P_STMT_0(PrtRaise(p_tmp_mach_priv, p_tmp_stmt_0, 0U), P_EXPR_0(&_P_EVENT_HALT_STRUCT.value, PRT_FALSE), PRT_FALSE);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON11_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 0U)
      {
        goto L0;
      }
      if (p_tmp_frame.returnTo == 1U)
      {
        goto L1;
      }
      PrtPushNewFrame(p_tmp_mach_priv, PRT_FALSE, &P_FUN_VotingClientMachine_ReadCredentials_STRUCT);
      L0:
      p_tmp_funstmt_ret = PrtWrapFunStmt(&p_tmp_frame, 0U, p_tmp_mach_priv, &P_FUN_VotingClientMachine_ReadCredentials_STRUCT);
      if (p_tmp_mach_priv->receive != NULL)
      {
        return p_tmp_funstmt_ret;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_VotingClientMachine_credentials, p_tmp_funstmt_ret, PRT_FALSE);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_VotingClientMachine_ballotBox, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_1(PrtTupleGetNC(p_tmp_expr_0, 0), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      P_STMT_0(PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_VotingClientMachine_bulletinBoard, p_tmp_stmt_0, !PRT_FALSE), P_EXPR_1(PrtTupleGetNC(p_tmp_expr_0, 1), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE), PRT_FALSE);
      PrtPushNewFrame(p_tmp_mach_priv, PRT_FALSE, &P_FUN_VotingClientMachine_ReadOperationToPerform_STRUCT);
      L1:
      p_tmp_funstmt_ret = PrtWrapFunStmt(&p_tmp_frame, 1U, p_tmp_mach_priv, &P_FUN_VotingClientMachine_ReadOperationToPerform_STRUCT);
      if (p_tmp_mach_priv->receive != NULL)
      {
        return p_tmp_funstmt_ret;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      PrtSetLocalVarEx(p_tmp_frame.locals, 1U, p_tmp_funstmt_ret, PRT_FALSE);
      if (P_BOOL_EXPR(P_EXPR_0(p_tmp_frame.locals[1U], PRT_FALSE), PRT_FALSE))
      {
        PrtGoto(p_tmp_mach_priv, P_STATE_VotingClientMachine_SubmitVote, 0U);
        goto P_EXIT_FUN;
      }
      else
      {
        PrtGoto(p_tmp_mach_priv, P_STATE_VotingClientMachine_ValidateResults, 0U);
        goto P_EXIT_FUN;
      }
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON12_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_expr_4;
      PRT_VALUE *p_tmp_expr_5;
      PRT_VALUE *p_tmp_expr_6;
      PRT_VALUE *p_tmp_expr_7;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_tuple;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 2U)
      {
        goto L2;
      }
      PrtPushNewFrame(p_tmp_mach_priv, PRT_FALSE, &P_FUN_VotingClientMachine_ReadVote_STRUCT);
      L2:
      p_tmp_funstmt_ret = PrtWrapFunStmt(&p_tmp_frame, 2U, p_tmp_mach_priv, &P_FUN_VotingClientMachine_ReadVote_STRUCT);
      if (p_tmp_mach_priv->receive != NULL)
      {
        return p_tmp_funstmt_ret;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      PrtSetLocalVarEx(p_tmp_frame.locals, 1U, p_tmp_funstmt_ret, PRT_FALSE);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_VotingClientMachine_ballotBox], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eVote_STRUCT.value, PRT_FALSE), P_EXPR_7(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_6), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_6), p_tmp_expr_5, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_4), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, P_TUPLE_1(&P_GEND_TYPE_24, p_tmp_expr_3, p_tmp_expr_2), PRT_TRUE, P_TUPLE_1(&P_GEND_TYPE_18, p_tmp_expr_0, p_tmp_expr_1), PRT_TRUE, p_tmp_mach_priv->id, PRT_FALSE, p_tmp_frame.locals[1U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_VotingClientMachine_credentials], PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON13_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_BOOLEAN p_tmp_bool;
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_expr_4;
      PRT_VALUE *p_tmp_ret;
      PRT_VALUE *p_tmp_stmt_0;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (P_BOOL_EXPR(P_EXPR_4(PrtMkBoolValue(!PrtPrimGetBool(p_tmp_expr_3)), PRT_TRUE, PrtMkBoolValue(PrtMapExists(p_tmp_expr_2, p_tmp_expr_0)), PRT_TRUE, PrtTupleGetNC(p_tmp_expr_1, 0), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_VotingClientMachine_credentials], PRT_FALSE), PRT_TRUE))
      {
        PrtPrintf("My vote not found!!");
        P_STMT_0(PrtRaise(p_tmp_mach_priv, p_tmp_stmt_0, 0U), P_EXPR_0(&_P_EVENT_HALT_STRUCT.value, PRT_FALSE), PRT_FALSE);
        goto P_EXIT_FUN;
      }
      else
      {
        P_EXPR_4(P_SEQ(PrtFormatPrintf("Your vote for ", 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_3, 1U, 0U, " was counted"), NULL), PRT_FALSE, PrtMapGetNC(p_tmp_expr_2, p_tmp_expr_0), PRT_FALSE, PrtTupleGetNC(p_tmp_expr_1, 0), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE, p_tmp_mach_priv->varValues[P_VAR_VotingClientMachine_credentials], PRT_FALSE);
      }
      P_EXPR_2(P_SEQ(PrtFormatPrintf("", 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_1, 1U, 0U, " won the election"), NULL), PRT_FALSE, PrtTupleGetNC(p_tmp_expr_0, 1), PRT_FALSE, p_tmp_frame.locals[0U], PRT_FALSE);
      PrtGoto(p_tmp_mach_priv, P_STATE_VotingClientMachine_Done, 0U);
      goto P_EXIT_FUN;
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON1_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON2_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON3_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON4_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON5_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON6_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON7_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON8_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      PrtPrintf("Vote successfully submitted to the ballot box");
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  static PRT_VALUE *P_FUN_VotingClientMachine_ANON9_IMPL(PRT_MACHINEINST *context)
  {
    {
      PRT_FUNSTACK_INFO p_tmp_frame;
      PRT_MACHINEINST_PRIV *p_tmp_mach_priv;
      PRT_VALUE *p_tmp_event;
      PRT_VALUE *p_tmp_expr_0;
      PRT_VALUE *p_tmp_expr_1;
      PRT_VALUE *p_tmp_expr_2;
      PRT_VALUE *p_tmp_expr_3;
      PRT_VALUE *p_tmp_funstmt_ret;
      PRT_VALUE *p_tmp_machine;
      PRT_VALUE *p_tmp_ret;
      p_tmp_mach_priv = (PRT_MACHINEINST_PRIV *)context;
      p_tmp_ret = NULL;
      PrtPopFrame(p_tmp_mach_priv, &p_tmp_frame);
      if (p_tmp_frame.returnTo == 3U)
      {
        goto L3;
      }
      PrtPushNewFrame(p_tmp_mach_priv, PRT_FALSE, &P_FUN_VotingClientMachine_ReadCredentials_STRUCT);
      L3:
      p_tmp_funstmt_ret = PrtWrapFunStmt(&p_tmp_frame, 3U, p_tmp_mach_priv, &P_FUN_VotingClientMachine_ReadCredentials_STRUCT);
      if (p_tmp_mach_priv->receive != NULL)
      {
        return p_tmp_funstmt_ret;
      }
      if (p_tmp_mach_priv->lastOperation != ReturnStatement)
      {
        goto P_EXIT_FUN;
      }
      PrtSetGlobalVarEx(p_tmp_mach_priv, P_VAR_VotingClientMachine_credentials, p_tmp_funstmt_ret, PRT_FALSE);
      P_SEQ(p_tmp_machine = P_EXPR_0(p_tmp_mach_priv->varValues[P_VAR_VotingClientMachine_bulletinBoard], PRT_FALSE), p_tmp_event = P_EXPR_0(&P_EVENT_eGetElectionResults_STRUCT.value, PRT_FALSE), P_EXPR_3(P_SEQ(PrtCheckIsLocalMachineId(context, p_tmp_expr_2), PrtSendInternal(context, PrtGetMachine(context->process, p_tmp_expr_2), p_tmp_expr_1, 1U, PRT_FUN_PARAM_CLONE, p_tmp_expr_0), NULL), PRT_FALSE, p_tmp_machine, PRT_FALSE, p_tmp_event, PRT_FALSE, p_tmp_mach_priv->id, PRT_FALSE));
      goto P_EXIT_FUN;
      P_EXIT_FUN:
      PrtFreeLocals(p_tmp_mach_priv, &p_tmp_frame);
      return p_tmp_ret;
    }
  }

  PRT_CASEDECL P_GEND_CASES_P_FUN_BallotBoxMachine_ANON15_0[] = 
  {
    
    {
        &P_EVENT_eRespAddItem_STRUCT,
        &P_FUN_BallotBoxMachine_ANON0_STRUCT
    }
  };
  PRT_CASEDECL P_GEND_CASES_P_FUN_BallotBoxMachine_ANON16_1[] = 
  {
    
    {
        &P_EVENT_eRespGetLog_STRUCT,
        &P_FUN_BallotBoxMachine_ANON13_STRUCT
    }
  };
  PRT_RECEIVEDECL P_GEND_RECEIVE_P_FUN_BallotBoxMachine_ANON15[] = 
  {
    
    {
        0U,
        &P_GEND_EVENTSET_eRespAddItem,
        1U,
        P_GEND_CASES_P_FUN_BallotBoxMachine_ANON15_0
    }
  };
  PRT_RECEIVEDECL P_GEND_RECEIVE_P_FUN_BallotBoxMachine_ANON16[] = 
  {
    
    {
        1U,
        &P_GEND_EVENTSET_eRespGetLog,
        1U,
        P_GEND_CASES_P_FUN_BallotBoxMachine_ANON16_1
    }
  };
  PRT_FUNDECL *P_GEND_FUNS_BallotBoxMachine[] = 
  {
    &P_FUN_BallotBoxMachine_ANON0_STRUCT,
    &P_FUN_BallotBoxMachine_ANON1_STRUCT,
    &P_FUN_BallotBoxMachine_ANON2_STRUCT,
    &P_FUN_BallotBoxMachine_ANON3_STRUCT,
    &P_FUN_BallotBoxMachine_ANON4_STRUCT,
    &P_FUN_BallotBoxMachine_ANON5_STRUCT,
    &P_FUN_BallotBoxMachine_ANON6_STRUCT,
    &P_FUN_BallotBoxMachine_ANON7_STRUCT,
    &P_FUN_BallotBoxMachine_ANON8_STRUCT,
    &P_FUN_BallotBoxMachine_ANON9_STRUCT,
    &P_FUN_BallotBoxMachine_ANON10_STRUCT,
    &P_FUN_BallotBoxMachine_ANON11_STRUCT,
    &P_FUN_BallotBoxMachine_ANON12_STRUCT,
    &P_FUN_BallotBoxMachine_ANON13_STRUCT,
    &P_FUN_BallotBoxMachine_ANON14_STRUCT,
    &P_FUN_BallotBoxMachine_ANON15_STRUCT,
    &P_FUN_BallotBoxMachine_ANON16_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS_BulletinBoardMachine[] = 
  {
    &P_FUN_BulletinBoardMachine_ANON0_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON1_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON2_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON3_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON4_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON5_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON6_STRUCT,
    &P_FUN_BulletinBoardMachine_ANON7_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS_SupervisorMachine[] = 
  {
    &P_FUN_SupervisorMachine_ANON0_STRUCT,
    &P_FUN_SupervisorMachine_ANON1_STRUCT,
    &P_FUN_SupervisorMachine_ANON2_STRUCT,
    &P_FUN_SupervisorMachine_ANON3_STRUCT,
    &P_FUN_SupervisorMachine_ANON4_STRUCT,
    &P_FUN_SupervisorMachine_ANON5_STRUCT,
    &P_FUN_SupervisorMachine_ANON6_STRUCT,
    &P_FUN_SupervisorMachine_ANON7_STRUCT,
    &P_FUN_SupervisorMachine_ANON8_STRUCT,
    &P_FUN_SupervisorMachine_ANON9_STRUCT,
    &P_FUN_SupervisorMachine_DoCloseElection_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS_TabulationTellerMachine[] = 
  {
    &P_FUN_TabulationTellerMachine_ANON0_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON1_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON2_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON3_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON4_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON5_STRUCT,
    &P_FUN_TabulationTellerMachine_ANON6_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS_TamperEvidentLogMachine[] = 
  {
    &P_FUN_TamperEvidentLogMachine_ANON0_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON1_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON2_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON3_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON4_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON5_STRUCT,
    &P_FUN_TamperEvidentLogMachine_ANON6_STRUCT
  };
  PRT_FUNDECL *P_GEND_FUNS_VotingClientMachine[] = 
  {
    &P_FUN_VotingClientMachine_ANON0_STRUCT,
    &P_FUN_VotingClientMachine_ANON1_STRUCT,
    &P_FUN_VotingClientMachine_ANON2_STRUCT,
    &P_FUN_VotingClientMachine_ANON3_STRUCT,
    &P_FUN_VotingClientMachine_ANON4_STRUCT,
    &P_FUN_VotingClientMachine_ANON5_STRUCT,
    &P_FUN_VotingClientMachine_ANON6_STRUCT,
    &P_FUN_VotingClientMachine_ANON7_STRUCT,
    &P_FUN_VotingClientMachine_ANON8_STRUCT,
    &P_FUN_VotingClientMachine_ANON9_STRUCT,
    &P_FUN_VotingClientMachine_ANON10_STRUCT,
    &P_FUN_VotingClientMachine_ANON11_STRUCT,
    &P_FUN_VotingClientMachine_ANON12_STRUCT,
    &P_FUN_VotingClientMachine_ANON13_STRUCT,
    &P_FUN_VotingClientMachine_ReadCredentials_STRUCT,
    &P_FUN_VotingClientMachine_ReadOperationToPerform_STRUCT,
    &P_FUN_VotingClientMachine_ReadVote_STRUCT
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON0_IMPL,
    1U,
    1U,
    2U,
    &P_GEND_TYPE_1,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON10_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON10_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON11_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON11_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON12_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON12_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON13_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON13_IMPL,
    1U,
    1U,
    2U,
    &P_GEND_TYPE_16,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON14_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON14_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_4,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON15_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON15_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_23,
    NULL,
    1U,
    P_GEND_RECEIVE_P_FUN_BallotBoxMachine_ANON15,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON16_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON16_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    1U,
    P_GEND_RECEIVE_P_FUN_BallotBoxMachine_ANON16,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON6_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON7_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON7_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON8_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON8_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BallotBoxMachine_ANON9_STRUCT = 
  {
    NULL,
    &P_FUN_BallotBoxMachine_ANON9_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON0_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_4,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON6_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_25,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_BulletinBoardMachine_ANON7_STRUCT = 
  {
    NULL,
    &P_FUN_BulletinBoardMachine_ANON7_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_5,
    &P_GEND_TYPE_13,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON0_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON6_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON7_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON7_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON8_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON8_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_ANON9_STRUCT = 
  {
    NULL,
    &P_FUN_SupervisorMachine_ANON9_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_5,
    &P_GEND_TYPE_14,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_SupervisorMachine_DoCloseElection_STRUCT = 
  {
    "DoCloseElection",
    &P_FUN_SupervisorMachine_DoCloseElection_IMPL,
    0U,
    0U,
    0U,
    NULL,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON0_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_4,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_22,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TabulationTellerMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_TabulationTellerMachine_ANON6_IMPL,
    1U,
    3U,
    1U,
    &P_GEND_TYPE_5,
    &P_GEND_TYPE_21,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON0_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_4,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_TamperEvidentLogMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_TamperEvidentLogMachine_ANON6_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_0,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON0_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON0_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON10_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON10_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON11_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON11_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_17,
    &P_GEND_TYPE_12,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON12_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON12_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_5,
    &P_GEND_TYPE_15,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON13_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON13_IMPL,
    1U,
    2U,
    1U,
    &P_GEND_TYPE_20,
    &P_GEND_TYPE_15,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON1_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON1_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON2_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON2_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON3_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON3_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON4_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON4_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON5_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON5_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON6_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON6_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON7_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON7_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON8_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON8_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ANON9_STRUCT = 
  {
    NULL,
    &P_FUN_VotingClientMachine_ANON9_IMPL,
    1U,
    1U,
    1U,
    &P_GEND_TYPE_5,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ReadCredentials_STRUCT = 
  {
    "ReadCredentials",
    &P_FUN_VotingClientMachine_ReadCredentials_IMPL,
    0U,
    0U,
    0U,
    NULL,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ReadOperationToPerform_STRUCT = 
  {
    "ReadOperationToPerform",
    &P_FUN_VotingClientMachine_ReadOperationToPerform_IMPL,
    0U,
    0U,
    0U,
    NULL,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_FUNDECL P_FUN_VotingClientMachine_ReadVote_STRUCT = 
  {
    "ReadVote",
    &P_FUN_VotingClientMachine_ReadVote_IMPL,
    0U,
    0U,
    0U,
    NULL,
    NULL,
    0U,
    NULL,
    0U,
    NULL
  };
  PRT_STATEDECL P_GEND_STATES_BallotBoxMachine[] = 
  {
    
    {
        "Init",
        1,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eStartElection,
        &P_GEND_EVENTSET_eVote,
        P_GEND_TRANS_BallotBoxMachine_Init,
        P_GEND_DOS_BallotBoxMachine_Init,
        &P_FUN_BallotBoxMachine_ANON14_STRUCT,
        &P_FUN_BallotBoxMachine_ANON2_STRUCT,
        0U,
        NULL
    },
    
    {
        "VoteCounting",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_BallotBoxMachine_ANON16_STRUCT,
        &P_FUN_BallotBoxMachine_ANON8_STRUCT,
        0U,
        NULL
    },
    
    {
        "WaitForGetResultsQuery",
        0,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eVote,
        NULL,
        P_GEND_DOS_BallotBoxMachine_WaitForGetResultsQuery,
        &P_FUN_BallotBoxMachine_ANON9_STRUCT,
        &P_FUN_BallotBoxMachine_ANON10_STRUCT,
        0U,
        NULL
    },
    
    {
        "WaitForVotes",
        1,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eCloseElection,
        &P_GEND_EVENTSET_eVote,
        P_GEND_TRANS_BallotBoxMachine_WaitForVotes,
        P_GEND_DOS_BallotBoxMachine_WaitForVotes,
        &P_FUN_BallotBoxMachine_ANON4_STRUCT,
        &P_FUN_BallotBoxMachine_ANON5_STRUCT,
        0U,
        NULL
    }
  };
  PRT_STATEDECL P_GEND_STATES_BulletinBoardMachine[] = 
  {
    
    {
        "ComputeResults",
        0,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eGetElectionResults,
        NULL,
        P_GEND_DOS_BulletinBoardMachine_ComputeResults,
        &P_FUN_BulletinBoardMachine_ANON7_STRUCT,
        &P_FUN_BulletinBoardMachine_ANON3_STRUCT,
        0U,
        NULL
    },
    
    {
        "Init",
        0,
        2,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eGetElectionResults_eAllVotes,
        NULL,
        P_GEND_DOS_BulletinBoardMachine_Init,
        &P_FUN_BulletinBoardMachine_ANON0_STRUCT,
        &P_FUN_BulletinBoardMachine_ANON1_STRUCT,
        0U,
        NULL
    }
  };
  PRT_STATEDECL P_GEND_STATES_SupervisorMachine[] = 
  {
    
    {
        "CloseElection",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_SupervisorMachine_ANON8_STRUCT,
        &P_FUN_SupervisorMachine_ANON5_STRUCT,
        0U,
        NULL
    },
    
    {
        "Init",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_SupervisorMachine_ANON7_STRUCT,
        &P_FUN_SupervisorMachine_ANON1_STRUCT,
        0U,
        NULL
    },
    
    {
        "StartElection",
        0,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_null,
        NULL,
        P_GEND_DOS_SupervisorMachine_StartElection,
        &P_FUN_SupervisorMachine_ANON6_STRUCT,
        &P_FUN_SupervisorMachine_ANON3_STRUCT,
        0U,
        NULL
    }
  };
  PRT_STATEDECL P_GEND_STATES_TabulationTellerMachine[] = 
  {
    
    {
        "Init",
        0,
        1,
        &P_GEND_EVENTSET_eDoTally,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eMergedVotes,
        NULL,
        P_GEND_DOS_TabulationTellerMachine_Init,
        &P_FUN_TabulationTellerMachine_ANON0_STRUCT,
        &P_FUN_TabulationTellerMachine_ANON2_STRUCT,
        0U,
        NULL
    },
    
    {
        "WaiForDoTally",
        0,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eDoTally,
        NULL,
        P_GEND_DOS_TabulationTellerMachine_WaiForDoTally,
        &P_FUN_TabulationTellerMachine_ANON3_STRUCT,
        &P_FUN_TabulationTellerMachine_ANON4_STRUCT,
        0U,
        NULL
    }
  };
  PRT_STATEDECL P_GEND_STATES_TamperEvidentLogMachine[] = 
  {
    
    {
        "Init",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_TamperEvidentLogMachine_ANON5_STRUCT,
        &P_FUN_TamperEvidentLogMachine_ANON1_STRUCT,
        0U,
        NULL
    },
    
    {
        "WaitForRequests",
        0,
        2,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eGetLog_eAddItem,
        NULL,
        P_GEND_DOS_TamperEvidentLogMachine_WaitForRequests,
        &P_FUN_TamperEvidentLogMachine_ANON2_STRUCT,
        &P_FUN_TamperEvidentLogMachine_ANON3_STRUCT,
        0U,
        NULL
    }
  };
  PRT_STATEDECL P_GEND_STATES_VotingClientMachine[] = 
  {
    
    {
        "Done",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_VotingClientMachine_ANON10_STRUCT,
        &P_FUN_VotingClientMachine_ANON7_STRUCT,
        0U,
        NULL
    },
    
    {
        "Init",
        0,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        NULL,
        NULL,
        &P_FUN_VotingClientMachine_ANON11_STRUCT,
        &P_FUN_VotingClientMachine_ANON1_STRUCT,
        0U,
        NULL
    },
    
    {
        "SubmitVote",
        1,
        0,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eRespConfirmVote,
        &P_GEND_EVENTSET,
        P_GEND_TRANS_VotingClientMachine_SubmitVote,
        NULL,
        &P_FUN_VotingClientMachine_ANON12_STRUCT,
        &P_FUN_VotingClientMachine_ANON3_STRUCT,
        0U,
        NULL
    },
    
    {
        "ValidateResults",
        0,
        1,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET,
        &P_GEND_EVENTSET_eRespElectionResults,
        NULL,
        P_GEND_DOS_VotingClientMachine_ValidateResults,
        &P_FUN_VotingClientMachine_ANON9_STRUCT,
        &P_FUN_VotingClientMachine_ANON5_STRUCT,
        0U,
        NULL
    }
  };
  PRT_MACHINEDECL P_MACHINE_BallotBoxMachine_STRUCT = 
  {
    0U,
    "BallotBoxMachine",
    2,
    4,
    17,
    4294967295,
    P_STATE_BallotBoxMachine_Init,
    P_GEND_VARS_BallotBoxMachine,
    P_GEND_STATES_BallotBoxMachine,
    P_GEND_FUNS_BallotBoxMachine,
    0U,
    NULL
  };
  PRT_MACHINEDECL P_MACHINE_BulletinBoardMachine_STRUCT = 
  {
    0U,
    "BulletinBoardMachine",
    2,
    2,
    8,
    4294967295,
    P_STATE_BulletinBoardMachine_Init,
    P_GEND_VARS_BulletinBoardMachine,
    P_GEND_STATES_BulletinBoardMachine,
    P_GEND_FUNS_BulletinBoardMachine,
    0U,
    NULL
  };
  PRT_MACHINEDECL P_MACHINE_SupervisorMachine_STRUCT = 
  {
    0U,
    "SupervisorMachine",
    3,
    3,
    11,
    4294967295,
    P_STATE_SupervisorMachine_Init,
    P_GEND_VARS_SupervisorMachine,
    P_GEND_STATES_SupervisorMachine,
    P_GEND_FUNS_SupervisorMachine,
    0U,
    NULL
  };
  PRT_MACHINEDECL P_MACHINE_TabulationTellerMachine_STRUCT = 
  {
    0U,
    "TabulationTellerMachine",
    2,
    2,
    7,
    4294967295,
    P_STATE_TabulationTellerMachine_Init,
    P_GEND_VARS_TabulationTellerMachine,
    P_GEND_STATES_TabulationTellerMachine,
    P_GEND_FUNS_TabulationTellerMachine,
    0U,
    NULL
  };
  PRT_MACHINEDECL P_MACHINE_TamperEvidentLogMachine_STRUCT = 
  {
    0U,
    "TamperEvidentLogMachine",
    2,
    2,
    7,
    4294967295,
    P_STATE_TamperEvidentLogMachine_Init,
    P_GEND_VARS_TamperEvidentLogMachine,
    P_GEND_STATES_TamperEvidentLogMachine,
    P_GEND_FUNS_TamperEvidentLogMachine,
    0U,
    NULL
  };
  PRT_MACHINEDECL P_MACHINE_VotingClientMachine_STRUCT = 
  {
    0U,
    "VotingClientMachine",
    3,
    4,
    17,
    4294967295,
    P_STATE_VotingClientMachine_Init,
    P_GEND_VARS_VotingClientMachine,
    P_GEND_STATES_VotingClientMachine,
    P_GEND_FUNS_VotingClientMachine,
    0U,
    NULL
  };
  