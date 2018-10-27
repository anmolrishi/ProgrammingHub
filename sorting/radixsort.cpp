#include<iostream>
using namespace std;
void radixarr(int (&a)[8],int exp)
{
	int count[10]={};
	int output[8];
	for(int i=0;i<8;i++)
		count[(a[i]/exp)%10]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	for(int i=7;i>=0;i--)
	{
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(int i=0;i<8;i++)
		a[i]=output[i];
}
void radixsort(int (&a)[8])
{
	int max=a[0];
	for(int i=1;i<8;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	for(int exp=1;max/exp>0;exp*=10)
		radixarr(a,exp);
}
int main()
{
	int arr[8];
	cout<<"Enter the elements";
	for(int i=0;i<8;i++)
		cin>>arr[i];
	radixsort(arr);
	for(int i=0;i<8;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}
