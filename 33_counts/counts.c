#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) 
{
  counts_t * ans = malloc(sizeof(* ans));
  ans->cntArr = NULL;
  ans->len = 0;
  ans->unknow = 0;

  return ans;
}

void addCount(counts_t * c, const char * name) 
{
  if (name == NULL)
  {
    c->unknow ++;
  }
  else
  {
    int t = 0;
    for (int i = 0; i < c->len; i++)
    {
      if (!strcmp(c->cntArr[i]->key, name))
      {
        c->cntArr[i]->count ++;
        t = 1;
      }
    }
    if (t == 0)
    {
      one_count_t * temp = malloc(sizeof(* temp));
      temp->key = malloc(strlen(name) + 2);
      strcpy(temp->key, name);
      temp->count = 1;
      c->cntArr = realloc(c->cntArr, (c->len + 1) * sizeof(* c->cntArr));
      c->cntArr[c->len] = temp;
      c->len ++;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) 
{
  for (int i = 0; i < c->len; i++)
  {
    fprintf(outFile, "%s: %zd\n", c->cntArr[i]->key, c->cntArr[i]->count);
  }
  if (c->unknow != 0)
  {
    fprintf(outFile, "<unknow> : %zd\n", c->unknow);
  }
}

void freeCounts(counts_t * c) 
{
  for (int i = 0; i < c->len; i++)
  {
    free(c->cntArr[i]->key);
    free(c->cntArr[i]);
  }
  free(c->cntArr);
  free(c);
}
