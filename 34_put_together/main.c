#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) 
{
  counts_t * answer = createCounts();
  FILE * f = fopen(filename, "r");
  if (f == NULL)
  {
    return NULL;
  }

  char * line = NULL;
  size_t sz = 0;
  while (getline(&line, &sz, f) >= 0)
  {
    char * str = strchr(line, '\n');
    if (str != NULL)
    {
      *str = '\0';
    }

    char * x = lookupValue(kvPairs, line);
    addCount(answer,x);
  }
  free(line);
  if (fclose(f) != 0)
  {
    return NULL;
  }

  return answer;
}

int main(int argc, char ** argv) 
{
  if(argc < 2)
  {
    fprintf(stderr, "no enough arguments");
    return EXIT_FAILURE;
  }

  kvarray_t * kv = readKVs(argv[1]);

  for(int i = 2; i < argc; i++)
  {
    counts_t * c = countFile(argv[i], kv);
    if(c == NULL) 
    {
      return EXIT_FAILURE;
    }
    char * outName = computeOutputFileName(argv[i]);

    FILE * f = fopen(outName, "w");

    printCounts(c, f);
    if (fclose(f) != 0 ) 
    {  
      return EXIT_FAILURE ;
    }
    free(outName);
    freeCounts(c);
  }
  
  freeKVs(kv);

  return EXIT_SUCCESS;
}

