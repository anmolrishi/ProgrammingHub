str = "abc def"
spnum = str.count(' ') #count the number of spaces
splitlist = []
rslist = []
splitlist = str.split(' ',spnum) #split the string
for i in range(len(splitlist)):
    rs = splitlist[i][::-1]
    rslist.append(rs) # reverse and to the list
print ' '.join(rslist) # join and print the output or can save into one variables
