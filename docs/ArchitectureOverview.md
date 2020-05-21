# Code Architecture Overview


### Distributed Host Machine

The distributed host machine runs the `main` method in app.cpp first. This spawns a thread to listen for network requests from other distributed host machines. This also spawns the appropiate P Process to host USMs in this host and parses the command line instructions in order to create the first USM in the system or wait to receive a network message from the start distributed host. App.cpp contains all of the USM hosting code and various API functions to handle USM operations (such as USM creation, USM message sending). 

###### Network Request Processing in Distributed Host Machines
Network_simulator.cpp contains all of the functions for handling network socket requests and sending out network socket requests to other distributed host machines. Incoming requests are forwarded to the `send_network_request_API` method in network_ra.cpp.

Network_ra.cpp contains the first layer of network processing logic. The `send_network_request_API` method creates a thread that calls the `network_request_logic`, which forwards the request to the `receiveNetworkRequest` method in app.cpp. 

`receiveNetworkRequest` in app.cpp forwards the request to `receiveNetworkRequestHelper` in helper.cpp with flag isEnclaveUntrustedHost set to false (since this method is being called in the context of app.cpp and not enclave_untrusted_host.cpp). As a brief note, app.cpp handles the USM APIs and enclave_untrusted_host.provides provides the bridge to call enclave SSM APIs. `receiveNetworkRequestHelper` parses the network payload and determines whether the message is intended for a USM. If it is, it executes the appropiate USM API function in app.cpp and returns the result. If the message is intended for an SSM, it forwards the network payload to the `untrusted_enclave_host_receiveNetworkRequest` method in enclave_untrusted_host.cpp.

Provided the message is for an SSM, `untrusted_enclave_host_receiveNetworkRequest` in enclave_untrusted_host.cpp sends the message back to `receiveNetworkRequestHelper` in helper.cpp with flag isEnclaveUntrustedHost set to true. Now, if this method parses the payload the same as before, but it additionally determines which SSM the message pertains too (and the corresponding enclave by using PublicIdentityKeyToEidDictionary) and calls that enclave's appropiate SSM API function. It returns this result.

###### SSM APIs

Untrusted Create Machine API (`UntrustedCreateMachineAPI`): This method allows an external party to spawn a new SSM on a new enclave in this distributed host machine ("Untrusted Create"). This method is called from `receiveNetworkRequestHelper` in helper.cpp, and it creates a new enclave and then calls this method on that new enclave. This method takes in the type of machine to be created, as well as an optional payload to be enqueued to the machine upon creation (this optional payload is passed used plaintext and should never contain sensitive information - it is better to create a machine and use the send method right after to send a payload). This method calls `createMachineHelper` in enclave.cpp which spawns a new P Process inside enclave memory. It then goes ahead and generates an identity for the to-be-created SSM and calls `ocall_add_identity_to_eid_dictionary` so that the distributed host knows which enclave to forward future messages. It then calls `receiveNewCapabilityKeyFromKPS` in enclave.cpp which then calls `ocall_enclave_attestation_in_thread` in order to remotely attest the enclave to the KPS and receive the capability key for this SSM. After this, `createPMachine` in helper.cpp (within the context of the enclave) is called in order to spawn the SSM within enclave memory, and it returns the public identity key of the newly created machine.

Trusted Create Machine API (`createMachineAPI`): This method allows an external SSM to spawn a new SSM on a new enclave in this distributed host machine ("Trusted Create"). This method is called from `receiveNetworkRequestHelper` in helper.cpp, and it creates a new enclave and then calls this method on that new enclave. This method takes in the type of machine to be created, as well as an optional payload to be enqueued to the machine upon creation (this optional payload is passed used plaintext and should never contain sensitive information - it is better to create a machine and use the send method right after to send a payload). This method calls `createMachineHelper` in enclave.cpp which spawns a new P Process inside enclave memory. It then goes ahead and generates an identity for the to-be-created SSM and calls `ocall_add_identity_to_eid_dictionary` so that the distributed host knows which enclave to forward future messages. It then calls `receiveNewCapabilityKeyFromKPS` in enclave.cpp which then calls `ocall_enclave_attestation_in_thread` in order to remotely attest the enclave to the KPS and receive the capability key for this SSM. After this, `createPMachine` in helper.cpp (within the context of the enclave) is called in order to spawn the SSM within enclave memory, and it returns the public identity key of the newly created machine. Using this public identity key, the external SSM can attest itself to the KPS and call `retrievePublicCapabilityKey` in enclave.cpp to get the newly created SSM's capability key (required for Trusted Send operations).


Initialize Communication API (`initializeCommunicationAPI`): This method sets up an encrypted channel between an external party and a SSM in an enclave on this distributed host machine. It takes in the public identity key of the requested SSM and the encrypted session key generated by the external party. This method goes ahead and decrypts the encrypted session key to obtain the session key by calling `decryptMessageInteralPrivateKey` with the private key of the SSM. It then saves the session key and associates it between the external party and the SSM.

Trusted and Untrusted Send Message API (`decryptAndSendMessageAPI`): This method is used to send a trusted or an untrusted encrypted message to a SSM hosted by an enclave on this distributed host. It takes in the public identity of the requested USM, the isSecureSend flag to distinguish between Trusted Send Message API and Untrusted Send Message API, and the encrypted payload (which is encrypted over the session key and if isSecureSend then additionally signed over the capability key of this SSM, the crypto is detailed in the thesis). This method calls `decryptAndSendInternalMessageHelper` in helper.cpp with the isSecureSend flag, which decrypts the payload and calls `handle_incoming_event` in helper.cpp that actually enqueues this payload into the appropiate SSM.

###### SSM External Methods
Call Create Machine




###### USM APIs
Untrusted Create Machine API (`createUSMMachineAPI`): This method allows an external party to spawn a new USM on this distributed host machine ("Untrusted Create"). It takes in the type of machine to be created, as well as an optional payload to be enqueued to the machine upon creation (this optional payload is passed used plaintext and should never contain sensitive information - it is better to create a machine and use the send method right after to send a payload). This method goes ahead and generates an identity for the to-be-created machine and adds it to the USMPublicIdentityKeyToMachinePIDDictionary map so that the distributed host knows which P machine to forward future messages. It then calls `createPMachine` in helper.cpp to go ahead and actually spawn the USM, and it returns the public identity key of the newly created machine.


Initialize Communication API (`USMinitializeCommunicationAPI`): This method sets up an encrypted channel between an external party and a USM on this distributed host machine. It takes in the public identity key of the requested USM and the encrypted session key generated by the external party. This method goes ahead and decrypts the encrypted session key to obtain the session key by calling `enclave_decryptMessageInteralPrivateKeyEcall` with the private key of the USM (we are calling an enclave method for the decryption because we want to use SGX library APIs for public key encryption and decryption). It then saves the session key and associates it between the external party and the USM.

Untrusted Send Message API (`USMSendMessageAPI`): This method is used to send an untrusted encrypted message to a USM hosted by this distributed host. It takes in the public identity of the requested USM as well as the encrypted payload (which is encrypted over the session key, the crypto is detailed in the thesis). This method calls `decryptAndSendInternalMessageHelper` in helper.cpp with the isSecureSend flag sent to false, which decrypts the payload and calls `handle_incoming_event` in helper.cpp that actually enqueues this payload into the appropiate USM.

###### USM External Methods






TODO, if time, list out SSM and USM APIs
Go through each one and describe how exaclty it works and clean up code futher and add comments


### KPS

The KPS distributed host machine runs the `main` method in app.cpp first. This spawns a thread that listens for network messages sent to the KPS for attestation requests and other functionality. 

###### Network Request Processing in KPS
Network_simulator.cpp contains all of the functions for handling network socket requests for attestation and other KPS functionality. Incoming requests are forwarded to either the `handle_socket_attestation_request` or `handle_socket_kps_generic_request` method in network_ra.cpp.

`handle_socket_kps_generic_request` parses the request and calls the appropiate API function in kps.cpp.

`handle_socket_attestation_request` calls `ra_network_send_receive` which interfaces with various methods in kps.cpp to perform an attestation check on the requesting machine.