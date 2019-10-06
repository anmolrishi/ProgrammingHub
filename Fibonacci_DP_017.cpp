#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number :";
	cin>>n; /*position of the element starting from 0...n*/

	int Fibo[n+1],i;
	Fibo[0]=0,Fibo[1]=1;

	for(i=2;i<=n;i++)
	{
		Fibo[i]=Fibo[i-1]+Fibo[i-2];  /*It will store the sum of previous two elements */
	}
	cout<<"Number at "<<n<<"th place is "<<Fibo[n]<<endl;

	return 0;
}
