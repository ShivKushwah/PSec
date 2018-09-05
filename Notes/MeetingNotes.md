# Meeting with Sanjit: Tuesday, 09/04/18

- Discussed project with Sanjit and gave thumbs up
- Workshop paper deadline in November
- Sign up for units CS199
- Check in biweekly

TODOs:
- Build spark electronic voting system as described earlier
- Experiment with zmq for interaction between different enclaves

------------------------------------------------

# First Project Skype Meeting: Thursday, 08/30/18

Big Project #1
Problem:
Want to ensure that certain types of operations are allowed on that data in certain stages. 
Contains 3 aspects:
- Security Aspect
- Systems building
- Formal Methods and Programming Language

Example: Electronic Voting system with ballot box. Votes have ID, and vote.
Operations: read, counting, compare operation 
Initially voter can only read vote
Policy is a state machine: allow read operation only to the voter
Tabulation teller can read only ID and not vote and perform operation of removing duplicates.
Anonymize, tabulation teller can perform anonymization operation to allow reading of the vote.
Throw an exception if behavior deviates from this
Who can do that operation and what is that operation.
Ballot box: container add operation by legitimate voters. Counting
Implemented in Spark
Contains votes, operation accesses those votes, anonymization 
Policies:
Can be represented by State machine, logical formulas
Checked using SAT query, and exhaustive search
Need to figure out which representation is best
Modify spark code to evaluate policies
Run instead enclaves

Short Term, Main Project
Write distributed application to run on intel SGX
P can write programs as state machines
Extend programming language P:
Ensure that each state machine runs on a separate intel SGX and data is encrypted
First do remote attestation

Action Items:
Install P, run simple examples
Run and show Intel SGX example

