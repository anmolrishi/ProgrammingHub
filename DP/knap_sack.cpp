#include<bits/stdc++.h>
using namespace std;
#define ll long long int  
#define mod 1000000007
ll T[1000][1000];
void knapsack_generate(ll w[] ,ll n,ll sum, ll val[]){
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=sum;j++){
      if(j<w[i]){
        T[i][j] = T[i-1][j];
      }else{
        T[i][j] = max(val[i-1] + T[i-1][j-w[i-1]],T[i-1][j]);
      }
    }
  }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,l,m,n,q;
    cin>>n;
    ll a[n+11];
    for(i=0;i<n;i++){
      cin>>a[i]>>w[i];
    }
    knapsack_generate(a,n,maxi_sum);
    cin>>q;
    while(q--){
      cin>>l;
      cout<<T[n][l]<<"\n";
    }
return 0;
}