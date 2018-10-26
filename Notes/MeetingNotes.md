# Hangouts Meeting Tuesday, 10/25/18
- Went over the code for Cancer Classifier, and recapped Health care system behavior
- Discussed HIPAA and how we should focus on making a better system, not break the existing one
- Capture 4 scenarios and write policies where patient information transitions to other people
- Examples:
	1: anonymize data for billing people
	2: my data can be used for

- Need to go thru hipaa and find people of interest, patient, doctor, specialist, billing, insurance, research (training entity)
 
 Action Items:
 1. Go through the HIPAA paper and note down examples of such transitions and policy changes
 2. Meet with Shiv and note these policy changes to the data and feel free to add extra columsn for data
 
 Deadline: 1 week
------------------------------------------------

# Hangouts Meeting Tuesday, 10/16/18
- Verify if healthcare runs correctly
- Train a simple regression model on data? age, smoking -> disease
- Find online data for cancer
- Training of the model over data, the training will have policy
- Train: output a model with policy which is a conjunction
- Training Data: Data that goes into trainer, figure out the set of features
- Patient data and diagnosis in different tables and putting together puts together the policies and then training takes the conjunction of policies of all that is inputted into trainer. Online data on medical records to input for our
- Generate bigger mount of data for voting system
- Run medical records on realistic example

# Hangouts Meeting: Friday, 10/05/18

- 3 Use cases:
	- Social media graph analysis
		- Write a policy where you cannot infer information on who you are with the connection graph
	- Event calendar
		- Ensure no one knows youre going to party but you want to let the people  
	- Healthcare:
		- TODO: Get this example running, no policy yet
		- no data, but we have schema so generate our own inputs
		- ML model from A to B, should not leak information about who was used to train the model
	- Pagerank:
		- Used for benchmarking 

- Action Items:
	- Search a bit more on privacy violations in medical records
	- Get medical example running
	- Get pagerank example running
	- Talk to Fernando about data access
		- What kind of learning do people normally do? 
		- Did this learning lead to privacy concerns?

- Ankush will implement the kavach dataset
------------------------------------------------
# Hangouts Meeting: Tuesday, 09/26/18
- Vote class looks ok
- Ballotbox needs to be changed
	- Drop validateVote
	- Figure out how things are getting stored in the dataset
	- Use groupbykey instead instead of groupby
	- Prevent access to vote fields
- DAG visualizations
- There are objects only, container is an object that contains other objects
- Implement a class called Kavach
	- T Data 
	- Statemachine Policy
	- func performOperation (op). Func also transitions the policy
- class Votepolicy extends
- Implement Votepolicy
------------------------------------------------
# Friday Extended Meeting: Friday, 09/21/18
- Emphasized importance of having clean code from the start
- Created a Todoist of all tasks that need to be completed with deadlines
- Again discussed overall architecture of the spark code displayed below (transcribed from whiteboard image):

class BallotBox:
  - addVote: vote -> BallotBox
  - RemoveDup: Ballotox -> BallotBox
  
  
class Vote:
  - compareCredential: vote -> bool
  - readCredential: vote -> credential
  - readVote: true -> vote
  - anonVote: true -> vote

- All of the above methods should all other internal methods when approriate
- All class variables and fields should be private

TODOs:
- Clean up Spark code to reflec this architecture
- Read Spark paper
- Read Typestates paper

- **This upcoming week we will transition to the P project for the workshop paper. Must make up for lost time this past week.**
------------------------------------------------
# Monday Extended Meeting: Monday, 09/17/18
- Finish Spark
- Run Pinpong using setup 
- Spawn 2 threads and create pinpong program with zeroMQ and RPC. 
- Look into Binn
- Ping Pong Ding Dong Example
- Try and get Voting System in Programming Enclaves to compile
- Send unbounded array or linked list over ping pong

------------------------------------------------
# Thursday Extended Meeting: Thursday, 09/15/18
- Went over electronic voting system code and were provided with feedback for improvements
- Went over how DAG of spark code fits into the state policy diagrams
- Had P tutorial
- Breifly went over Helio paper and compared it to what we are doing. The difference is Helio paper has only one source. 

TODOs:
- Visualize DAGs, want to see the disassembly
- Refactor code to create minimal DAG, toDf() method becomes problematic since it creates an instance of the DF. We want to create expressions in the form of queries using the most minimal subset. Ideally want to use map and reduce.
------------------------------------------------
# Weekly Friday Meeting: Friday, 09/07/18

- Discussed the electronic voting system and state diagrams for each
- Breifly talked about helio paper. The dataset was directly provided from UCSF, not publicly available. 

Electronic Voting Spec:

- Vote: (credentials: int, id: int, vote: int);
- VotersList: List<credentials>
- BallotBox: List<Vote>

Functions:

1. CastVote: Vote -> bool. 
true: if its a valid voter and legit vote then add it to the BallotBox, false otherwise.
2. RemoveDuplicate: VotersList -> VotersList. 
Removes all the duplicates and picks the latest vote.
3. AnonVote: 
replace the credentials by null.
4. GenerateResults
return the results.
5. CheckVote: BallotBox -> bool

Questions:
Q1: Would you implement it using RDD, DataFrame, Dataset etc. What is the difference in all of them?
Q2: How does spark-submit really work?
Q3: DAG for each of the spark queries.

TODOs:
- Finish spark electronic voting system by Tuesday
- Read Helio Paper

------------------------------------------------

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
- Initially voter can only read vote
- Policy is a state machine: allow read operation only to the voter
- Tabulation teller can read only ID and not vote and perform operation of removing duplicates.
- Anonymize, tabulation teller can perform anonymization operation to allow reading of the vote.
- Throw an exception if behavior deviates from this
- Who can do that operation and what is that operation.
- Ballot box: container add operation by legitimate voters. Counting
- Implemented in Spark
- Contains votes, operation accesses those votes, anonymization 

Policies:
- Can be represented by State machine, logical formulas
- Checked using SAT query, and exhaustive search
- Need to figure out which representation is best
- Modify spark code to evaluate policies
- Run inside enclaves

Short Term, Main Project:
- Write distributed application to run on intel SGX
- P can write programs as state machines
- Extend programming language P:
- Ensure that each state machine runs on a separate intel SGX and data is encrypted
- First do remote attestation

TODOs:
- Install P, run simple examples
- Run and show Intel SGX example

