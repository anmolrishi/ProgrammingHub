#include <iostream>
using namespace std;
#define N 1000
int fibo[N];

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int n;
	cin>>n;
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<=n;i++)fibo[i]=fibo[i-1]+fibo[i-2];
	cout<<fibo[n]<<endl;
	return 0;
}
