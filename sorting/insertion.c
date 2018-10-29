//programme to sort given element using insertion sort in O(n^2) time complexity.

#include <stdio.h>
 
int main()
{
  int n,  c, d, swap;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
  int array[n];
 
  printf("Enter %d integers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && array[d-1] > array[d]) {
      swap          = array[d];
      array[d]   = array[d-1];
      array[d-1] = swap;
 
      d--;
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for (c = 0; c <= n - 1; c++) {
    printf("%d\n", array[c]);
  }
 
  return 0;
}