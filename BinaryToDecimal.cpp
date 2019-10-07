#include<iostream>
#include<cmath>
using namespace std;
int main(){
int i=0,sum=0,r,n;
cin>>n;
while(n>0)
{

    r=n%10;
    sum=sum+r*pow(2,i);
    n=n/10;
    i++;
}
cout<<sum;
return 0;
}
