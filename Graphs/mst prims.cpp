#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pr pair<ll,ll>
int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,i,j,k,u,v;
		cin>>n;
		map<string,ll>mp;
		vector<ll> adj[10001],cost[10001];
		ll val[10001];
		bool vis[10001];
		for(i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			//mp[s]=i;
			val[i]=INT_MAX;
			vis[i]=false;
			cin>>m;
			for(j=0;j<m;j++)
			{
				cin>>u>>v;
				adj[i].push_back(u);
				adj[u].push_back(i);
				cost[i].push_back(v);
				cost[u].push_back(v);
			}
		}
		priority_queue<pr,vector<pr>,greater<pr>>q;
		q.push({0,1});
		val[1]=0;
		while(!q.empty())
		{
			pr node=q.top();
			//cout<<node.second
			q.pop();
			if(vis[node.second])
				continue;
			vis[node.second]=true;
			//cout<<node.second<<"-"<<node.first<<" ";
			for(i=0;i<adj[node.second].size();i++)
			{
				ll x=adj[node.second][i];
				ll y=cost[node.second][i];
				if(vis[x]==false&&val[x]>y)
				{
					val[x]=y;
					q.push({y,x});
				}
			}
		}
		ll sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=val[i];	
		}
		cout<<sum<<endl;
	}
	return 0;
}
