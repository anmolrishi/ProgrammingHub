str = "abc def"
spnum = str.count(' ')
splitlist = []
rslist = []
splitlist = str.split(' ',spnum)
for i in range(len(splitlist)):
    rs = splitlist[i][::-1]
    rslist.append(rs)
print ' '.join(rslist)
