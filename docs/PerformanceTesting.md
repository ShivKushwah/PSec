# Performance Testing

We provide helper scripts to do PSec performance testing located in the PerformanceMetricsScript folder. For the OTP and Civitas examples, we have created both a PSec version as well as a Distributed P version (look at [this](Running.md) to see how to change between running different examples, under "Choose which Sample to Run"). The scripts runs the currently selected example a specified number of times and displays average runtime as well as standard deviation metrics. The current iteration of the script supports up to 2 distributed hosts, and the 

The `ApplicationLevelPerformanceMetricsScript.py` script conducts the actual runnning of the examples for a single host and outputs `BaselineCacheHostX.txt` where X can be 1 or 2, depending on the selected host instance. This output text file contains the raw start time and end time for each run of the examples. You need to invoke this script in 2 terminal windows to simulate 2 distributed hosts and obtain the output text files. Then, you need to run `ApplicationLevelPerformanceMetricsParsing.py` to parse the text files and obtain the average runtime and standard deviation.

`ApplicationLevelPerformanceMetricsScript.py` takes the following arguments:


` python3 ApplicationLevelPerformanceMetricsScript.py [EXAMPLE_NAME] [HW/SIM] [NUM_ITERATIONS] [host1/host2]
`

##### Sample Code

Before running these examples, make sure you change the cmake file to the relevant example ([here](Running.md)!)

Running on 1 local machine:
```
ALL: cd PSec/PerformanceMetricsScript

SHELL1: python3 ApplicationLevelPerformanceMetricsScript.py CIVITAS HW 10 host1

SHEll2: python3 ApplicationLevelPerformanceMetricsScript.py CIVITAS HW 10 host2

EITHER: python3 ApplicationLevelPerformanceMetricsParsing.py
```

Running distributed:
```
ALL: cd PSec/PerformanceMetricsScript

HOST1: python3 ApplicationLevelPerformanceMetricsScript.py OTP HW 10 host1

HOST2: python3 ApplicationLevelPerformanceMetricsScript.py OTP HW 10 host2

HOST1: sftp shivendra@10.0.0.5:/home/shivendra/Research/PSec/PerformanceMetricsScript/BaselineCacheHost2.txt /home/shivendra/Research/PSec/PerformanceMetricsScript/BaselineCacheHost2.txt

HOST1: python3 ApplicationLevelPerformanceMetricsParsing.py
```

We include the raw results from our performance testing in the PerformanceMetricsScript/PerformanceData folder


