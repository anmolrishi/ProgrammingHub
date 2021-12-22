#include <bits/stdc++.h>

using namespace std;

stack<int> s;
vector<int> arr[100];
int visited[100];
void dfs(int n){
  visited[n]=1;
  for(int i=0;i<arr[n].size();i++)
  {
    if(!visited[arr[n][i]])
    {
      dfs(arr[n][i]);
    }
  }
  s.push(n);
}
int main(void)
{
  int n,m;
  cin>>n>>m;
  int temp1,temp2;
  for(int i=1;i<=m;i++)
  {
    cin>>temp1>>temp2;
    arr[temp1].push_back(temp2);
  }
  dfs(1);
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      dfs(i);
    }
  }
  while (!s.empty()) {
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
