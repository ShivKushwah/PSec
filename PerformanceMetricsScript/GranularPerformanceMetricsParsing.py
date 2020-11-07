import re
import subprocess
import time
import json
import statistics 
import time
import os
import sys

search_lst1 = ['MEASURE UNTRUSTED CREATE START', 'MEASURE UNTRUSTED CREATE SSM START', 'MEASURE TRUSTED CREATE END', 'MEASURE TRUSTED SEND END', 'MEASURE TRUSTED SEND 2 END', 'MEASURE UNTRUSTED SEND START', 'MEASURE UNTRUSTED SEND 2 START', 'MEASURE UNTRUSTED USM SEND END', 'MEASURE UNTRUSTED USM SEND 2 END']
search_lst2 = ['MEASURE UNTRUSTED CREATE END', 'MEASURE UNTRUSTED CREATE SSM END', 'MEASURE TRUSTED CREATE START', 'MEASURE TRUSTED SEND START', 'MEASURE TRUSTED SEND 2 START', 'MEASURE UNTRUSTED SEND END', 'MEASURE UNTRUSTED SEND 2 END', 'MEASURE UNTRUSTED USM SEND START', 'MEASURE UNTRUSTED USM SEND 2 START']
id_lst = ['MEASURE UNTRUSTED CREATE', 'MEASURE UNTRUSTED CREATE SSM', 'MEASURE TRUSTED CREATE', 'MEASURE TRUSTED SEND', 'MEASURE TRUSTED SEND 2', 'MEASURE UNTRUSTED SEND', 'MEASURE UNTRUSTED SEND 2', 'MEASURE UNTRUSTED USM SEND', 'MEASURE UNTRUSTED USM SEND 2']

with open('BaselineCacheHost1.txt') as json_file:
    data1 = json.load(json_file)

with open('BaselineCacheHost2.txt') as json_file:
    data2 = json.load(json_file)

#merge 2 dictionaries into 1
data1.update(data2)

data_dict = {}

#Populate data_dict
for i in range(len(search_lst1)):
    lst1 = data1[search_lst1[i]]
    lst2 = data1[search_lst2[i]]
    data_dict[id_lst[i]] = [abs(end - start) for end, start in zip(lst2, lst1)]

with open('BaselineCacheFinalResults.txt', 'w') as file:
        file.write(json.dumps(data_dict)) # use `json.loads` to do the reverse

for key in data_dict.keys():
    lst = data_dict[key] 
    print(key)
    print('Mean:')
    print(float(sum(lst))/len(lst))
    print('Standard Deviation:')
    res = statistics.pstdev(lst)
    print(res) 

print(data_dict)