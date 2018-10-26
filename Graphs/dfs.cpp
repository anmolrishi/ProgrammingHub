#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
	stack <int> q;
	int n=9;
	int arr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	int flag[n]={};
	q.push(0);
	flag[0]=1;
	while(q.size()!=0)
	{
		if(flag[q.top()]==1)
		{
			int val=q.top();
			q.pop();
			cout<<(char)('a'+val)<<"\t";
			flag[val]=2;
			for(int j=0;j<n;j++)
			{
				if(arr[val][j]==1)
				{
					if(flag[j]==0)
					{
						q.push(j);
						flag[j]=1;
					}
					}
			}
		}
	}
	return 0;
}
