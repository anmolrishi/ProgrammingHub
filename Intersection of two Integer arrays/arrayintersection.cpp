#include <vector>

//approach with O(n2) time complexity
std::vector<int> ArrayIntersections(int * arr1, int arr1_size, int * arr2, int arr2_size)
{
  std::vector<int> vIntersections;
  for(int i = 0; i<arr1_size; i++)
  {
    for(int j = 0; i<arr2_size; i++)
    {
      if(arr1[i] ^ arr2[j])
      {
        continue;
      }
      else
      {
        //both are equal
        vIntersections.push_back(arr1[i]);
        break;
      }
    }
  }
  return vIntersections;
}
