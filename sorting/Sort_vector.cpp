//sorting of n integers using vector
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Read input from STDIN. Print output to STDOUT */
    int n,x;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; ++i)
     {   cin>>x;
        v.push_back(x);
     }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
        cout<<v[i]<<" ";

    return 0;
}
