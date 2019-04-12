#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * fullName = malloc((strlen(inputName) + 9) * sizeof(* fullName));
  strcpy(fullName, inputName);
  strcat(fullName, ".counts");
  return fullName; 
}
