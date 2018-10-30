#include<iostream>
using namespace std;
int  func(int n){
long double f=0;
long double s=1;
  cout<<f<<" "<<s;  
  if(n>2){  
	long double t;
	for(int i=3;i<=n;i++){
      t=f+s;
      cout<<" "<<t;
      f=s;
      s=t;
    }
  }
  return 0;
}
int main(){
  int x;
  cin>>x;
  func(x);
  return 0;
}
