n=int(input())
t=n
a=0
b=1
if n==1 or n==0:
  print('0')
else:
  while(t-2!=0):
    t-=1
    c=a+b
    a=b
    b=c
   
  print(c)
