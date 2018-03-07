# Principals

1. KeyValServer
1. User
1. User[i]


    ``forall i: User[i] actsfor User``


# Enclaves (Private Machines)

  - Server enclave (``actsfor KeyValServer``)
  - User enclave 1 (``actsfor User, actsfor User[1]``)
  - User enclave 2 (``actsfor User, actsfor User[2]``)

The two user enclaves have identical code but represent different instances of the same machine.

# Pseudocode

## User Enclave

    while (*)
    {  
      if (*) {
         generate key, value
         label with owner User[i], readers either User or User[i]
         // Note: may fail if key already exists and is owned by User 2
         Server.put(key, value, label) 
       } else {
         key = *
         // Note: may fail if key doesn't exist or is readable only by User 1
         value = Server.get(key)
       }
    }

## Server Enclave

    method put(key, value, label)
    method get(key, value, label)

# Threat Model

Adversary controls all privileged software. This means the following:

  * Adversary can read, modify and drop messages between enclaves
  * Adversary can replay messages between enclaves
  * Adversary can read and modify all non-enclave memory
  * Adversary can start an arbitrary number of enclaves
  * Adversary can destroy enclaves

## Security Requirements

  * Only two instances of the user enclave are created for each run of the system
  * Only one instance of the server enclave is created for each run of the system
  * Only instances created are the "correct" ones (measurement)
  * If any of the enclaves is killed, the entire system aborts execution
  * The only put/get msgs received by the server are from User 1 or User 2
  * Any key labelled User[1] is only readable/modifiable by User[i]
  * Any key labelled User is readable/modifiable by both User[1] and User[2]

# Implementation

* The runtime handles message authentication, encryption and replay using cryptography.
* The central server maintains an "enclave budget" so that too many copies of an enclave not launched by the adversary.. 
* The central server also uses the initial authentication of newly launched enclaves to can detect when an enclave is destroyed by the adversary
