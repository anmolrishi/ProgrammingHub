#include<bits/stdc++.h>
using namespace std;
int main()
{ int m,n,i,s,k=0;
   scanf("%d%d",&m,&n);//m for first array, n for second array
   if(m<n)
   s=m;
   else s=n;
    int A[m],B[n],j,C[s];
    for(i=0;i<m;i++)
    scanf("%d",&A[i]);
    for(i=0;i<n;i++)
    scanf("%d",&B[i]);
    i=0;j=0;
  for(i=0;i<m;i++)
  for(j=0;j<n;j++)
  {if(A[i]==B[j])
	 { C[k]=A[i];k++;
     }
  }
  printf("\nIntersection contains-\n");
  for(i=0;i<s;i++)
  printf("%d ",C[i]);	  
return 0;
}
