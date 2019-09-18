event OTPSecretMsg: (machine, int);
event OTPSecretReceived;
event OTPCodeMsg: int;
event OTPCodeValidated;
event OTPCodeFailed;
fun SaveOTPSecret(secret : int): int;

machine BANK_SERVER 
{
    var clientOtpGenerator: machine;
	var secret: int;

    // This is the entry point.
    start state Init {
        entry (payload:any) {
          clientOtpGenerator = payload as machine;
          goto GenerateOTPSecret;   	   
        }
    }

    state GenerateOTPSecret {
        entry {
			// generate OTP secret 
			secret = 123456788;
			send clientOtpGenerator, OTPSecretMsg, (this, secret);
	    }
        on OTPSecretReceived goto WaitOTPCode;
     }

     state WaitOTPCode {
        on OTPCodeMsg goto ValidateOTPCode;
     }

	 state ValidateOTPCode {
        entry (payload: int) {
		  // validate OTP code
		  if (payload == 123456789) {
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
	var OTPSecret: int;

    start state Init {
        on OTPSecretMsg goto HandleOTPSecret;
    }

    state HandleOTPSecret {
	    entry (payload: (machine, int)) {
	        bankServer = payload.0;
			OTPSecret = payload.1;
			SaveOTPSecret(7);
			send bankServer, OTPSecretReceived;
			goto GenerateOTPCode;	 	  
	    }
    }

	state GenerateOTPCode {
	    entry {
			send bankServer, OTPCodeMsg, OTPSecret + 1;
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