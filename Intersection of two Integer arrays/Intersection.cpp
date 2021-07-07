#include<iostream>
using namespace std;
int main(){
	int n1=0;
	int n2=0;
	int a1[100];
	int a2[100];
	int a3[100];
	int i=0;
	int j=0;
	int k=0;
	int cnt=0;
	cout<<"Enter the size for 1st array: ";
	cin>>n1;
	cout<<"Enter the size for 2nd array: ";
	cin>>n2;
	cout<<"Enter the elements for 1st array: ";
	for(i=0;i<n1;i++){
		cin>>a1[i];
	}
	cout<<"Enter the elements for 2nd array: ";
	for(i=0;i<n2;i++){
		cin>>a2[i];
	}
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
		if(a1[i]==a2[j]){
			a3[k]=a1[i];
			k++;
			cnt++;
		}}}
		if(cnt==0){
			cout<<"There are no common elements the two Arrays\n";
		}
		cout<<"The intersection Array of the above arrays is: ";
	for(k=0;k<cnt;k++){
		cout<<a3[k]<<"\t";
	}
}
