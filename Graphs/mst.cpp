#include "bits/stdc++.h"
#define ll long long int 

using namespace std;

ll v,e,v1,v2,weight, dsu[100100], size[100100], mst=0;

struct node {
    ll u,v,w;
};

bool wsort(const node &a, const node &b){
    return (a.w<b.w);
}

ll find (ll x)
{
    // cout << "x: " << x << " dsu[x]: " << dsu[x] << endl; 
    if(dsu[x]==x)
        return x;
    else 
        return dsu[x]=find(dsu[x]);
}

bool uni(ll u, ll v, ll w)
{
    // cout << "u" << u << endl; 
    ll U=find(u);
    // cout << "v" << v << endl; 
    ll V=find(v);

    // cout << "u: " << u << " U: " << U << endl;
    // cout << "v: " << v << " V: " << V << endl;

    if (U == V) {
        return 0; 
    } else  {
        // printf("u=%lld v=%lld \n", u, v);

        if(size[U] <= size[V])
        {
            dsu[U]=V;
            size[V]+=size[U];
            mst += w;
            // printf("New %lld %lld\n", dsu[U], dsu[V]);
            return 1;
        }
        else 
        {
            dsu[V] = U;
            size[U] += size[V];
            mst += w;
            return 1;
        }
    }
}

vector <node> edges, g[100100];

int main(void)
{
    scanf("%lld%lld", &v, &e);
    for(ll i=0; i<e;i++)
    {
        scanf("%lld%lld%lld", &v1, &v2, &weight);
        node temp;
        temp.u=v1;
        temp.v=v2;
        temp.w=weight;

        edges.push_back(temp);
    }
    sort(edges.begin(), edges.end(), wsort);

    for(ll i=1; i<=v;i++)
    {
        dsu[i]=i;
        size[i]=1;
    }


    for (ll i=0; i<edges.size(); i++)
    {
        uni(edges[i].u, edges[i].v, edges[i].w);
    }

    printf("%lld\n", mst);

}

