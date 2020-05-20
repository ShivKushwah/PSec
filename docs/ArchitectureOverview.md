# Code Architecture Overview


### Distributed Host Machine

The distributed host machine runs the `main` method in app.cpp first. This spawns a thread to listen for network requests from other distributed host machines. This also spawns the appropiate P Process to host USMs in this host and parses the command line instructions in order to create the first USM in the system or wait to receive a network message from the start distributed host. App.cpp contains all of the USM hosting code and various foreign functions to handle USM operations (such as USM creation, USM message sending). 


### KPS

The KPS distributed host machine runs the `main` method in app.cpp first. This spawns a thread that listens for network messages sent to the KPS for attestation requests and other functionality. The main KPS functionality is implemented in TODO