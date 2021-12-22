#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
void print(int arr[],int brr[],int n,int m)
{
    map<int,int> mp;
    //map<int,int> ::iterator it;
    vector<int> v;
    int i,j;
    for(i=0;i<n;i++)
    {        if(mp.find(arr[i])==mp.end())
        {
            mp[arr[i]]=1;
        }
        else
            mp[arr[i]]++;
    }
    for(i=0;i<m;i++)
    {
        if(mp.find(brr[i])!=mp.end())
        {
            if(mp[brr[i]]>0)
            {
                mp[brr[i]]--;
                v.push_back(brr[i]);
                //cout<<brr[i]<<" ";
            }
        }

    }
    sort(v.begin(),v.end());
    cout<<"[";
    for(i=0;i<v.size()-1;i++)
    {
        cout<<v[i]<<", ";
    }
    cout<<v[i]<<"]";

}
int main()
{
    int arr[100],brr[100],n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    print(arr,brr,n,m);
}

