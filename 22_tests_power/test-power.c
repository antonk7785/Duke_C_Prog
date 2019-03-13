#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main(void)
{
  if (power(0, 0) != 1)
    return EXIT_FAILURE;
  if (power(1, 1) != 1)
    return EXIT_FAILURE;
  if (power(2, 2) != 4)
    return EXIT_FAILURE;
  if (power(4, 10) != 1048576)
    return EXIT_FAILURE;
  if (power(-1, 10) != 1)
    return EXIT_FAILURE;




  
  
  return EXIT_SUCCESS;
}
