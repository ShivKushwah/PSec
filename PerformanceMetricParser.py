import re

# data_dict = {'MEASURE UNTRUSTED CREATE END' : []}
search_lst1 = ['MEASURE UNTRUSTED CREATE START', 'MEASURE UNTRUSTED CREATE SSM START', 'MEASURE TRUSTED CREATE START', 'MEASURE TRUSTED SEND START', 'MEASURE TRUSTED SEND 2 START', 'MEASURE UNTRUSTED SEND START', 'MEASURE UNTRUSTED SEND 2 START']
search_lst2 = ['MEASURE UNTRUSTED CREATE END', 'MEASURE UNTRUSTED CREATE SSM END', 'MEASURE TRUSTED CREATE END', 'MEASURE TRUSTED SEND END', 'MEASURE TRUSTED SEND 2 END', 'MEASURE UNTRUSTED SEND END', 'MEASURE UNTRUSTED SEND 2 END']
id_lst = ['MEASURE UNTRUSTED CREATE', 'MEASURE UNTRUSTED CREATE SSM', 'MEASURE TRUSTED CREATE', 'MEASURE TRUSTED SEND', 'MEASURE TRUSTED SEND 2', 'MEASURE UNTRUSTED SEND', 'MEASURE UNTRUSTED SEND 2']

data_dict = {}
for item in id_lst:
    data_dict[item] = []

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

for i in range(len(search_lst1)):
    match1 = re.search(search_lst1[i] + ':(\d+)', data)
    match2 = re.search(search_lst2[i] + ':(\d+)', data)

    data_lst = data_dict[id_lst[i]]
    data_lst.append(int(match2.group(1)) - int(match1.group(1)))

    # data_dict.add(id_lst[i], data_lst)

print(data_dict)