
// BY hg398 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

int main() {
	boost;
	string s,str="";
	getline(cin,s);
	vector <string> v;
	FOR(i,0,s.length()-1)
	{
		if(s[i]==' ')
		{v.push_back(str);str="";}
		else
		str+=s[i];
	}
	v.push_back(str);
	for(int i=0;i<v.size();i++)
	reverse(v[i].begin(),v[i].end());
	s=v[0];
	for(int i=1;i<v.size();i++)
	{s+=" ";s+=v[i];}
	cout<<s;
	return 0;
}