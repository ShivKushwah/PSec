#ifndef CONSTANT_FILE
#define CONSTANT_FILE
#include "CivitasHeaders.h"
// #include "PingPongEnclave.h"
// #include "OTPBankServerCode.h"

const int SIZE_OF_IDENTITY_STRING = 385; //TODO figure out why i cant make this 384
const int SIZE_OF_PUBLIC_CAPABILITY_KEY = 384 + 4;
const int SIZE_OF_PRIVATE_CAPABILITY_KEY = 384 + 384 + 4;
const int SIZE_OF_CAPABILITYKEY = SIZE_OF_PUBLIC_CAPABILITY_KEY + 1 + SIZE_OF_PRIVATE_CAPABILITY_KEY;//384 + 1 + 384;
const int SIZE_OF_MESSAGE = SIZE_OF_CAPABILITYKEY;
const int SIZE_OF_NEWMACHINETYPE = 20;
const int SIZE_OF_SESSION_KEY = 70;
const int SIZE_OF_MAX_MESSAGE = 16400;
const int MAX_NETWORK_MESSAGE = 16400;

const int SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST = 384 + 1 + 384 + 4;

const int SIZE_OF_REAL_SESSION_KEY = 16;
const int SIZE_OF_IV = 12;
const int SIZE_OF_MAC = 16;


const int SIZE_OF_MAX_SERIALIZED_TUPLE = 16000;
const int MAX_TUPLE_ELEMENT_LENGTH = 16000;

const int SIZE_OF_MAX_SERIALIZED_MAP = 16000;

const int SIZE_OF_MAX_SERIALIZED_SEQ = 16000;

const int SIZE_OF_PRT_STRING_SERIALIZED = 384;
const int SIZE_OF_P_CAPABILITY_FOREIGN_TYPE = 384 + 1 + SIZE_OF_CAPABILITYKEY; //Identity:CapabilityKeyPublic:Private
const int SIZE_OF_SECURE_MACHINE_HANDLE = 384 + 1 + 384 + 4 + 1 + SIZE_OF_CAPABILITYKEY;
const int SIZE_OF_MACHINE_HANDLE = 384 + 1 + 384 + 4;

const int SIZE_OF_MAX_EVENT_NAME = 20;
const int SIZE_OF_MAX_EVENT_PAYLOAD = 16000;

const int ENCLAVE_NUMBER = 0; //TODO retrieve this from network after registering this entire enclave

const int CREATE_CAPABILITY_KEY_CONSTANT = 1;
const int RETRIEVE_CAPABLITY_KEY_CONSTANT = 2;



const int ENABLE_KPS_ATTESTATION_PRINT = 0;
const int ENABLE_ENCLAVE_ATTESTATION_PRINT = 0;

const int PROGRAM_DEBUG = 1;

const int NETWORK_DEBUG = 0;
#endif

