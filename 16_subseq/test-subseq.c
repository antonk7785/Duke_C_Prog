#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void)
{

  int arr0[] = {1,2,3,4,5,6,7,8,9,10};
  if (maxSeq(arr0, 10) != 10)
    return EXIT_FAILURE; 
  int arr1[] = {-9,-7,-3,0,5,-3,7,6,9,22};
  if (maxSeq(arr1, 10) != 5)
    return EXIT_FAILURE; 
  int arr2[] = {0,0,0,0,0,0,0,0,0,0};
  if (maxSeq(arr2, 10) != 1)
    return EXIT_FAILURE; 
  int arr3[] = {8,9,9,11,6,5,4,3,2,1};
  if (maxSeq(arr3, 10) != 2)
    return EXIT_FAILURE; 
  int arr4[] = {1,2};
  if (maxSeq(arr4, 2) != 2)
    return EXIT_FAILURE; 
  int *arr5 = NULL;
  if (maxSeq(arr5, 0) != 0)
    return EXIT_FAILURE; 
  int arr6[] = {1};
  if (maxSeq(arr6, 1) != 1)
    return EXIT_FAILURE; 
  int arr7[] = {100,2,3,300,4000,6,7,8,0,10};
  if (maxSeq(arr7, 10) != 4)
    return EXIT_FAILURE; 
  int arr8[] = {1,2,3,4,7,0,7,8,9,10};
  if (maxSeq(arr8, 10) != 5)
    return EXIT_FAILURE; 
 
  return EXIT_SUCCESS;

}
