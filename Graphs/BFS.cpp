#include <iostream>
#include <queue>
using namespace std;

void bfs(int edges[][100], int n, int sv, bool* visited){
  queue<int> pending;
  pending.push(sv);
  visited[sv]=true;
  while(pending.size() != 0){
    int front = pending.front();
    cout<<front<<" ";

    pending.pop();

    for(int i=0;i<n;i++){
      if(front==i){
        continue;
      }
      if(edges[front][i]==1){
        if(visited[i]==true)
          continue;


        pending.push(i);
        visited[i]=true;
      }

    }

  }
}

void dfs(int edges[][100], int n, int sv, bool *visited){
    if(visited[sv]==true){
        return;
    }

    cout<<sv<<' ';
    visited[sv]=true;

    for(int i=0;i<n;i++){
        if(sv==i){
            continue;
        }

        if(edges[sv][i]==1){
            dfs(edges,n,i,visited);
        }
    }

}

// 5 4 0 1 0 4 2 3 1 2

int main() {
    int V, E;
    cin >> V >> E;
    int edges[V][100] =  {{0}};

    int f,s;
    for(int i=0;i<E;i++){
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bool visited[V];

    cout<<"\nBreadth First Traversal \n";
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    bfs(edges,V,0,visited);
    cout<<"\n";

    cout<<"\nDepth First Traversal \n";
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    dfs(edges,V,0,visited);
    cout<<"\n";

    return 0;
}
