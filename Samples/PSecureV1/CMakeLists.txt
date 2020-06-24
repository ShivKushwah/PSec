# need 3.0 for multiple line strings
cmake_minimum_required(VERSION 3.0)
project(ExampleEnclave)
set(CMAKE_BUILD_TYPE Debug)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/CivitasHeaders.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/InitializerMachine.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureSupervisor.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/VotingMachine.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureBulletinBoard.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureBallotBoxMachine.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureTamperEvidentLog.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureTabulationTellerMachine.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/SecureVotingClientMachine.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/CivitasHeaders.c) #only need CivitasHeaders.c because P compiler writes all p code from multiple files into first p file with c extension
# add_definitions(-DCIVITAS_EXAMPLE)

set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample/OTPBankServerCode.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample/OTPClientCode.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample/OTPHeaderDeclarations.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPBankServerCode.c) #only need OTPBankServerCode.c because P compiler writes all p code from multiple files into first p file with c extension
add_definitions(-DOTP_EXAMPLE)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample-PBaseline/OTPBankServerCode.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample-PBaseline/OTPClientCode.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample-PBaseline/OTPHeaderDeclarations.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPBankServerCode.c) #only need OTPBankServerCode.c because P compiler writes all p code from multiple files into first p file with c extension
# add_definitions(-DOTP_EXAMPLE)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PerformanceMetricsExample/PerformanceMachines1.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PerformanceMetricsExample/PerformanceMachines2.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PerformanceMetricsExample/PerformanceHeaderDeclarations.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/PerformanceMachines1.c) #only need OTPBankServerCode.c because P compiler writes all p code from multiple files into first p file with c extension
# add_definitions(-DPERFORMANCE_METRICS_EXAMPLE)


# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/EmailProcessing/EmailProcessingClient.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/EmailProcessing/EmailProcessingServer.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/EmailProcessing/EmailProcessingHeaderDeclarations.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/EmailProcessingClient.c) #only need EmailProcessingClient.c because P compiler writes all p code from multiple files into first p file with c extension
# add_definitions(-DEMAIL_PROCESSING)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/HealthAnalysis/HealthAnalysisClient.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/HealthAnalysis/HealthAnalysisServer.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/HealthAnalysis/HealthAnalysisHeaderDeclarations.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PSecInternalLib.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/HealthAnalysisClient.c) #only need HealthAnalysisClient.c because P compiler writes all p code from multiple files into first p file with c extension
# add_definitions(-DHEALTH_ANALYSIS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(Src/enclave)
add_subdirectory(Src/app)
