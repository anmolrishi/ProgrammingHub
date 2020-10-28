#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> adj[10001];
ll low[10001],disc[10001],child[10001],cnt;
bool vis[10001];
void dfs(ll node,ll tim,ll par)
{
	ll i,j,k,flag=0;
	//cout<<node<<" ";
	vis[node]=true;
	disc[node]=tim;
	low[node]=tim;
	for(i=0;i<adj[node].size();i++)
	{
		ll x=adj[node][i];
		if(!vis[x])
		{
			vis[x]=true;
			child[node]++;
			dfs(x,tim+1,node);
			low[node]=min(low[node],low[x]);
			if(node==par&&child[node]>1)
				flag=1;
			if(node!=par&&low[x]>=disc[node])
			{
				flag=1;
			}
		}
		else if(x!=par){
			low[node]=min(low[node],disc[x]);
		}
	}
	//cout<<node<<"-"<<flag<<endl;
	cnt=cnt+flag;
}
int main() {
	// your code goes here
	ll n,m;
	cin>>n>>m;
	while(n)
	{
		ll u,v,i,j,k;
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cnt=0;
		dfs(1,0,1);
 
		cout<<cnt<<endl;
		for(i=0;i<=n;i++)
		{
			vis[i]=false;	
			adj[i].clear();
			child[i]=0;
		}
 
		cin>>n>>m;
	}
	return 0;
}
