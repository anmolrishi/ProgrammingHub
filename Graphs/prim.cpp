#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

vector<iPair> g[100005];

void prim(int nodes){

	//Creating a min priority queue to store vertices that are used in prim
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
	// Taking vertex 1 as source
	int src = 1; 
	int dist[nodes+1]; //to store the weight of the nodes
	int vis[nodes+1]; //Whether the vertices has included in mst or not.
	int parent[nodes+1]; //to store the parent , which represent mst.
	for(int i = 1;i<=nodes;i++){
		dist[i] = INT_MAX;
		vis[i] = 0;
		parent[i] = -1;
	}
	dist[src] = 0;

	//Insert source vertex in priority_queue
	pq.push(make_pair(0 , src));

	while(!pq.empty()){
		int tp = pq.top().second;
		vis[tp] = 1;
		pq.pop();
		int siz = g[tp].size();
		for(int j = 0;j<siz;j++){
			int v = g[tp][j].first;
			int w = g[tp][j].second;
			// check if the node is not in the mst and weight of that edge is smaller than current distance
			if(vis[v] == 0 && dist[v] > w){
				dist[v] = w;
				pq.push(make_pair(dist[v] , v));
				parent[v] = tp;
			}
		}
	}
	//printing edges of the mst
	for(int i = 2;i<=nodes;i++){
		cout<<parent[i]<<"-->"<<i<<endl;
	}
}

int main(){
	int nodes , edges;
	cout<<"Enter the number of nodes"<<endl;
	cin>>nodes;
	cout<<"Enter the number of edges"<<endl;
	cin>>edges;
	cout<<"Enter the edges and its corresponding weight";
	for(int i = 0;i<edges;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	prim(nodes);
}