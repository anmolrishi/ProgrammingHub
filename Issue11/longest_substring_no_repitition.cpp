#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"String?\n";
	string s;
	cin>>s;
	int n = s.length();
	int a[26]={0},b[26]={0},cnt=0,ans=0;
	for(int i=0;i<n;i++){
		int x = s[i]-'a';
		cnt++;
		if(!a[x]){
			a[x]=1;
		}
		else if(b[x]>(i-cnt)){
			cnt=(i-b[x]);
		}
		b[x]=i;
		ans=max(ans,cnt);
	}
	cout<<"Longest substring with unique characters = "<<ans<<endl;
	return 0;
}