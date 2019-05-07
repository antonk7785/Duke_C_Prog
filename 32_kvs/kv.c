#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvpair_t * makePair(char * str)
{
  char * str1 = strchr(str, '=');
  *str1 = '\0';
  str1++;
  char * str2 = strchr(str1, '\n');
  if (str2 != NULL)
  {
    *str2 = '\0';
  }

  kvpair_t * pair = malloc(sizeof(* pair)); 
  pair->key = str;
  pair->value = str1;

  return pair;
}

kvarray_t * readKVs(const char * fname) 
{
  //open file
  FILE * f = fopen(fname, "r");
  if (f == NULL)
  {
    perror("Could not open file");
    return NULL;
  }
  // read the lines
  char * line = NULL;
  size_t sz = 0;

  kvpair_t * pair = NULL;

  kvarray_t * answer = malloc(sizeof(* answer));
  answer->pair = NULL;
  answer->len = 0;

  while (getline(&line, &sz, f) >= 0)
  {
    pair = makePair(line);
    answer->pair = realloc(answer->pair, (answer->len + 1) * sizeof(* answer->pair));
    answer->pair[answer->len] = pair;
    answer->len ++;
    line = NULL;
  }
  free(line);
  
  //close file
  if (fclose(f) != 0)
  {
    return NULL;
  }

  return answer;
}

void freeKVs(kvarray_t * pairs) 
{
  for (int i = 0; i < pairs->len; i++)
  {
    free(pairs->pair[i]->key);
    //free(pairs->pair[i]->value);
    free(pairs->pair[i]);
  }
  free(pairs->pair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) 
{
  for (int i = 0; i < pairs->len; i++)
  {
    printf("key = '%s' value = '%s'\n", pairs->pair[i]->key, pairs->pair[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) 
{
  for (int i = 0; i < pairs->len; i++)
  {
    if (!strcmp(pairs->pair[i]->key, key))
    {
      return pairs->pair[i]->value;
    }
  }

  return NULL;
}
