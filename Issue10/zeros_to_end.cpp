#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<" Number of Integers?\n";
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int i=n-1,j=n-1;
	while(j>=0){
		if(a[j]==0){
			int tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
			i--;
		}
		j--;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}