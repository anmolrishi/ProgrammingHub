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


    set<pair<int,int>> s;
    bool visited[n];
    memset(visited,0,sizeof(visited));

    int distance = 0;
    int par[n];
    par[0] = 0;
    s.insert({0,0});
    int dist[n];
    for(int i = 0;i<n;i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    while(!s.empty()){

        pair<int,int> p = *s.begin();
        s.erase(s.begin());

        int w = p.first;
        int u = p.second;

        if(visited[u])
            continue;

        visited[u] = 1;
        distance += w;

        for(auto it = adj[u].begin();it!=adj[u].end();it++){

            int v = it->first;
            int weigh = it->second;

            if(dist[v] == INT_MAX || dist[v] > weigh){
                dist[v] = weigh;
                par[v] = u;
                s.insert({weigh,v});
            }


        }


    }

        cout<<distance<<endl;
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<i<<" : "<<par[i]<<endl;
        }

}
/*
4 5
0 1 1
1 2 4
2 3 1
1 3 2
0 3 1
*/
