event OTPSecretMsg: machine;
event OTPSecretReceived;
event OTPCodeMsg: int;
event OTPCodeValidated;
event OTPCodeFailed;

fun EnclaveOneInitialize();
fun EnclaveTwoInitialize();

fun EnclaveOneSendSecret(secret: int);
fun EnclaveTwoGenerateOTPCode(): int;


machine BANK_SERVER 
{
    var clientOtpGenerator: machine;
	var secret: int;

    // This is the entry point.
    start state Init {
        entry (payload:any) {
			EnclaveOneInitialize();
          	clientOtpGenerator = payload as machine;
          	goto GenerateOTPSecret;   	   
        }
    }

    state GenerateOTPSecret {
        entry {
			// generate OTP secret 
			secret = 12344;
			EnclaveOneSendSecret(secret);
			send clientOtpGenerator, OTPSecretMsg, this;
	    }
        on OTPSecretReceived goto WaitOTPCode;
     }

     state WaitOTPCode {
        on OTPCodeMsg goto ValidateOTPCode;
     }

	 state ValidateOTPCode {
        entry (payload: int) {
		  // validate OTP code
		  if (payload == 12345) {
			send clientOtpGenerator, OTPCodeValidated;
          	goto Done;  
		  } else  {
			send clientOtpGenerator, OTPCodeFailed;
			goto WaitOTPCode;
		  }  
        }
     }

     state Done {}
}

machine CLIENT_OTP_GENERATOR
{
	var bankServer: machine;

    start state Init {
		entry {
			EnclaveTwoInitialize(); // Potential Race Condition if 2 isn't intialized right after 1
		}
        on OTPSecretMsg goto HandleOTPSecret;
    }

    state HandleOTPSecret {
	    entry (payload: machine) {
	        bankServer = payload;
			send bankServer, OTPSecretReceived;
			goto GenerateOTPCode;	 	  
	    }
    }

	state GenerateOTPCode {
	    entry {
			var code: int;
			code = EnclaveTwoGenerateOTPCode();
			send bankServer, OTPCodeMsg, code;
	    }
        on OTPCodeValidated goto End;
		on OTPCodeFailed goto GenerateOTPCode;
    }
	
	state End {
		entry {
			raise(halt);
		}
	}
}

machine IntializerMachine
{
    var clientMachine: machine;
	var bankMachine: machine;

    start state Init {
	    entry {
            clientMachine = new CLIENT_OTP_GENERATOR();
			bankMachine = new BANK_SERVER(clientMachine);
	    }
	}
}