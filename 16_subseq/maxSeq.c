#include <stdlib.h>

size_t maxSeq(int *array, size_t n)
{
  if (n <= 0 || array == NULL)
    return 0;   
  
  int count = 1;
  for (int i = 0; i < n; i++)
  {
    int temp = 1;
    int j = i;
    while ((j < n - 1) && (array[j + 1] > array[j]))
    {
       temp++;
       j++;
    }	    
    if (temp > count)
     count = temp;
  } 
  
  return count;
}
