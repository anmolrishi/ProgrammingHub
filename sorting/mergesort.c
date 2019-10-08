#include<stdio.h>


int a[100], c[100], n;
void merge(int l, int r, int m)
{
  int l1=l, r1=m, l2=m+1, r2=r, i=l;

  while(l1<=r1 || l2<=r2)
  {
    if(l1>r1)
      c[i++]=a[l2++];
    else if(l2>r2)
      c[i++]=a[l1++];
    else if(a[l1]<=a[l2])
      c[i++]=a[l1++];
    else
      c[i++]=a[l2++];
  }

  for(int i=l;i<=r;i++)
    a[i]=c[i];
}

void sort(int l, int r)
{
  if(l==r)
    return;
  int mid=(l+r)/2;
  sort(l,mid);
  sort(mid+1, r);
  merge(l,r,mid);
}

int main(void)
{
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);

  sort(0,n-1);

  for(int i=0;i<n;i++)
    printf("%d ", a[i]);
  printf("\n");
}
