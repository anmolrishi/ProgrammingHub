#include <stdio.h>
#include<limits.h>
#define min INT_MIN

int segtree[101010];
int arr[100];
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
int max(int a,int b)
{
  return a>b?a:b;
}
void build(int l,int r,int i)
{
  if(l==r)
  {
    segtree[i]=arr[l];
  }
  else
  {
    build(l,(l+r)/2,2*i+1);
    build(((l+r)/2)+1,r,2*i+2);
    segtree[i]=arr[l];
    segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
  }
}

int  query(int l,int r,int low,int high,int i)
{
  if(high<l||low>r)
    return INT_MIN;
  else if(low>=l&&high<=r)
    return segtree[i];
  return max(query(l,(l+r)/2,low,high,left(i)),query((l+r)/2,r,low,high,right(i)));
}
void print(int i) {
  /* code */
  if(segtree[i]==0)
  return;
  printf("%d ",segtree[i]);
  print(left(i));
  print(right(i));
}
int main(void)
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  build(0,n-1,1);
  print(0);
  printf("\n%d\n",query(0,n-1,1,2,1));
}
