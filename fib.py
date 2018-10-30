n=int(input())
a=0
b=1
if(n==1):
    print("0")
elif(n==2):
    print("0 1")
else:
    print("0 1",end=' ')
    while((n-2)>0):
        b=a+b
        a=b-a
        if(n==1):
            print(b)
        else:
            print(b,end=' ')
        n-=1
