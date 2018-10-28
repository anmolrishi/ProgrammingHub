#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std; 

ll tot_dyck_paths(ll n) 
{ 
    ll ans = 1; 
    for (ll i = 0; i < n; ++i) 
    { 
        ans *= (2 * n - i); 
        ans /= (i + 1); 
    } 
  
    return ans / (n+1); 
} 
 
int main() 
{ 
    ll N,T;
    cin>>T;
    while(T--)
    {
    	cin>>N;
    cout << "Number of Dyck Paths are " 
         << tot_dyck_paths(N)<<endl; 
    
    }
     return 0;
} 
