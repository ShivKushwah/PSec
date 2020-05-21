# Code Architecture Overview


### Distributed Host Machine

The distributed host machine runs the `main` method in app.cpp first. This spawns a thread to listen for network requests from other distributed host machines. This also spawns the appropiate P Process to host USMs in this host and parses the command line instructions in order to create the first USM in the system or wait to receive a network message from the start distributed host. App.cpp contains all of the USM hosting code and various API functions to handle USM operations (such as USM creation, USM message sending). 

###### Network Request Processing in Distributed Host Machines
Network_simulator.cpp contains all of the functions for handling network socket requests and sending out network socket requests to other distributed host machines. Incoming requests are forwarded to the `send_network_request_API` method in network_ra.cpp.

Network_ra.cpp contains the first layer of network processing logic. The `send_network_request_API` method creates a thread that calls the `network_request_logic`, which forwards the request to the `receiveNetworkRequest` method in app.cpp. 

`receiveNetworkRequest` in app.cpp forwards the request to `receiveNetworkRequestHelper` in helper.cpp with flag isEnclaveUntrustedHost set to false (since this method is being called in the context of app.cpp and not enclave_untrusted_host.cpp). As a brief note, app.cpp handles the USM APIs and enclave_untrusted_host.provides provides the bridge to call enclave SSM APIs. `receiveNetworkRequestHelper` parses the network payload and determines whether the message is intended for a USM. If it is, it executes the appropiate USM API function in app.cpp and returns the result. If the message is intended for an SSM, it forwards the network payload to the `untrusted_enclave_host_receiveNetworkRequest` method in enclave_untrusted_host.cpp.

Provided the message is for an SSM, `untrusted_enclave_host_receiveNetworkRequest` in enclave_untrusted_host.cpp sends the message back to `receiveNetworkRequestHelper` in helper.cpp with flag isEnclaveUntrustedHost set to true. Now, if this method parses the payload the same as before, but it additionally determines which SSM the message pertains too (and the corresponding enclave by using PublicIdentityKeyToEidDictionary) and calls that enclave's appropiate SSM API function. It returns this result.

###### SSM and USM APIs
TODO, if time, list out SSM and USM APIs


### KPS

The KPS distributed host machine runs the `main` method in app.cpp first. This spawns a thread that listens for network messages sent to the KPS for attestation requests and other functionality. 

###### Network Request Processing in KPS
Network_simulator.cpp contains all of the functions for handling network socket requests for attestation and other KPS functionality. Incoming requests are forwarded to either the `handle_socket_attestation_request` or `handle_socket_kps_generic_request` method in network_ra.cpp.

`handle_socket_kps_generic_request` parses the request and calls the appropiate API function in kps.cpp.

`handle_socket_attestation_request` calls `ra_network_send_receive` which interfaces with various methods in kps.cpp to perform an attestation check on the requesting machine.