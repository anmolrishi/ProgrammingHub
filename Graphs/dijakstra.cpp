#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n];
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }


    bool visited[n];
    memset(visited,0,sizeof(visited));

    int dist[n];

    for(int i = 0;i<n;i++)
        dist[i] = INT_MAX;

    set<pair<int,int>> s;

    s.insert({0,0});

    dist[0] = 0;

    while(!s.empty()){

        pair<int,int> p = *s.begin();
        s.erase(s.begin());

        int u = p.second;
        int d = p.first;

        if(visited[u])
            continue;

        dist[u] = d;
        visited[u] = 1;

        for(auto it = adj[u].begin();it!= adj[u].end();it++){
            int v = it->first;
            int w = it->second;

            if(!visited[v] && (dist[v] == INT_MAX || dist[v] > dist[u] + w)){
                dist[v] = dist[u] + w;
                s.insert({dist[v],v});
            }

        }

    }

    for(int i = 0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

/*
5 6
0 1 5
1 2 2
0 2 10
0 3 1
1 4 1
3 4 2


*/

