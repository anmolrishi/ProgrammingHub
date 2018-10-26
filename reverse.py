str = "abc def"
spnum = str.count(' ') # counting the number of spaces
splitlist = []
rslist = []
splitlist = str.split(' ',spnum) # split string and save in a list
for i in range(len(splitlist)):
    rs = splitlist[i][::-1]
    rslist.append(rs) # reverse the string and save
print ' '.join(rslist) # join the list or save to a variable
