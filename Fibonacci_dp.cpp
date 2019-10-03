#include<iostream.h>
using namespace std;
  
  
int main () 
{ 
   int n;
   cin>>n;
   int f[n+1];
  
  f[0] = 0; 
  f[1] = 1; 
  
  for (i = 2; i <= n; i++) 
  { 
      f[i] = f[i-1] + f[i-2]; 
  } 
  
  //To print the  Fibonacci sequence.
  for(int i=0;i<=n;i++)
   cout<<f[i]<<" ";
   cout<<endl;
   
} 
