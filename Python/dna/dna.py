import csv
import sys
from pathlib import Path

# Find the all files that are csv type and assign into a list
rootdir = Path('/home/ubuntu/pset6/dna')
# Return a list of regular files only, not directories
file_list = [f for f in rootdir.glob('**/*.csv') if f.is_file()]
#print(len(file_list))

#print content
if len(sys.argv)<3 or len(sys.argv)>3 :
    print ("Usage: python dna.py data.csv sequence.txt")
    sys.exit()
else:
    file_data=sys.argv[1]
    file_seq=sys.argv[2]
#print ("Number of arguments: "+ file_data)
#print ("The arguments are: " + file_seq)

#Read file content to a dictionary manually
def read_file(file_content):
    with open (file_content) as data :
        seq=data.readline()
        seqs=seq.strip().split(",")
        del seqs[0]
        dna={}

        for line in data:
            k=line.strip().split(",")
            ini=k[0]
            del k[0]
            dna[ini]=k
    return seqs, dna

# Iterate over each file
"""def find_seq():
   for file in file_list:
        patterns, users= read_file(file)
"""

#Count matches in a pattern and add to the list
def count_match(patterns, file_seq):
    with open (file_seq) as data :
        seq=data.readline()
        #print(patterns)
    list = []
    for pattern in patterns:
        if pattern in seq:
            list.append("" + str(countUnique(pattern, seq)))
    return list


#Count max unique repetitions in a sequence
def countUnique(pattern, seq):
    max = 0
    step = len(pattern)

    count = 0
    i = 0

    while i < len(seq):
        if seq[i:i+step] == pattern:
            count += 1
            if count >= max:
                max = count
            i = i + step
        else:

            count = 0
            i = i + 1
    return max

#find the user match with given sequence
def user_match(lis_of_seqs, list_of_users):

   # print (lis_of_seqs)
    #print(list_of_users)
    a = set(lis_of_seqs)
    for user, values in list_of_users.items():
        if lis_of_seqs == values:
            #print(values)
            print(user)
            sys.exit()
    print("No Match")


#Get the patterns and list of users
patterns, users= read_file(file_data)

#Find the user matches and with matched count
user_match(count_match(patterns, file_seq), users)

