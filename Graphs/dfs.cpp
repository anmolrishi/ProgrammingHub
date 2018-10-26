#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

vector<int> g[100005];

void dfs(int node , int visited[]){
	visited[node] = 1;
	cout<<node<<" ";
	int l = g[node].size();
	for(int j =0;j<l;j++){
		int v = g[node][j];
		if(visited[v] == 0)
			dfs(v , visited);
	}
}

int main(){
	int nodes , edges;
	cout<<"Enter the number of nodes"<<endl;
	cin>>nodes;
	cout<<"Enter the number of edges"<<endl;
	cin>>edges;
	cout<<"Enter the edges";
	for(int i = 0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<"DFS traversal of this graph is"<<endl;
	int visited[nodes+1];
	memset(visited , 0 , sizeof(visited));
	for(int i = 1;i<=nodes;i++){
		if(visited[i] == false)
			dfs(i , visited);
	}
}