n1=input()
n=int(n1)
a=0
b=1
if(n==1):
    print("0")
elif(n==2):
    print("1")
else:
    while(n>2):
        b=a+b
        a=b-a
        n-=1
    print(b)
