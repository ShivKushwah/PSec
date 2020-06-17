import re

# data_dict = {'MEASURE UNTRUSTED CREATE END' : []}
search_dict1 = ['MEASURE UNTRUSTED CREATE START', 'MEASURE UNTRUSTED CREATE SSM START', 'MEASURE TRUSTED CREATE START', 'MEASURE TRUSTED SEND START', 'MEASURE TRUSTED SEND 2 START', 'MEASURE UNTRUSTED SEND START', 'MEASURE UNTRUSTED SEND 2 START']
search_dict2 = ['MEASURE UNTRUSTED CREATE END', 'MEASURE UNTRUSTED CREATE SSM END', 'MEASURE TRUSTED CREATE END', 'MEASURE TRUSTED SEND END', 'MEASURE TRUSTED SEND 2 END', 'MEASURE UNTRUSTED SEND END', 'MEASURE UNTRUSTED SEND 2 END']
  
data = data2 = "" 
  
# Reading data from file1 
with open('build/Samples/PSecureV1/host1Output.txt') as fp: 
    data = fp.read() 
  
# Reading data from file2 
with open('build/Samples/PSecureV1/host2Output.txt') as fp: 
    data2 = fp.read() 
  
# Merging 2 files 
# To add the data of file2 
# from next line 
data += "\n"
data += data2 

for i in range(len(search_dict1)):
    match1 = re.search(search_dict1[i] + ':(\d+)', data)
    match2 = re.search(search_dict2[i] + ':(\d+)', data)
    print(search_dict1[i])
    print(int(match2.group(1)) - int(match1.group(1)))