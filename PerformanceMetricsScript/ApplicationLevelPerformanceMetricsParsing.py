import re
import subprocess
import time
import json
import statistics 
import time
import os
import sys

search_lst1 = ['MEASURE BASELINE START']
search_lst2 = ['MEASURE BASELINE END']
id_lst = ['MEASURE BASELINE']

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
    data_dict[id_lst[i]] = [end - start for end, start in zip(lst2, lst1)]

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