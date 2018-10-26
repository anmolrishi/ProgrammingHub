#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d%d",&x,&y)
#define siii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y)
#define slll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
 
#define ll long long
#define mp make_pair
#define pb push_back
#define nl printf("\n");
#define pf printf
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int>
#define tci int t;scanf("%d",&t);while(t--)
const int maxn=10e6+4;
typedef pair<int,int> vpair;
vector<pair<int,int>>g[100005];
int n;
int dist[100005];
void shortest_path(int s)
{
	rep(i,100001)
		dist[i]=INF;
	set<pair<int,int>> setds;

	setds.insert(mp(0,s));
	dist[s]=0;
	while(!setds.empty())
	{
		pair<int,int> temp;
		temp=*(setds.begin());
		setds.erase(setds.begin());

		int u=temp.second;
		vector<pair<int,int>>::iterator it;
		for(it=g[u].begin();it!=g[u].end();it++)
		{
			int v = (*it).first;
			int weight = (*it).second;
			if(dist[v] > dist[u] + weight)
			{
				if(dist[v] != INF)
					setds.erase(setds.find(mp(dist[v],v)));

				dist[v]=dist[u] + weight;
				setds.insert(mp(dist[v],v));
			}
		}
	}

	printf("Vertex   Distance from Source\n");
    for (int i = 0; i <= n ; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}

int main()
{
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }
    int m;
	sii(n,m);
    rep(i,m)
    {
    	int x,y,w;
    	siii(x,y,w);
    	g[x].pb(mp(y,w));
    	g[y].pb(mp(x,w));
    }
    shortest_path(2);

	return 0;
}
