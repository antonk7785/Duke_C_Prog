#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) 
{
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) 
{
  qsort(data, count, sizeof(char *), stringOrder);
}

char ** read_file(FILE *f, size_t *size)
{
  char **array = NULL;
  char *line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f) >= 0)
  {
    array = realloc(array, (*size + 1) * sizeof(*array));
    array[*size] = malloc((strlen(line) + 1) * sizeof(array[*size]));
    strcpy(array[*size], line);
    free(line);
    line = NULL;
    *size = *size + 1;
  }
  free(line);
  return array;
}

void print_and_free(char **array, size_t index)
{
  size_t i = 0;
  while(i < index)
  {
    fprintf(stdout,"%s",array[i]);
    free(array[i]);
    i++;
  }
  free(array);
}

int main(int argc, char ** argv) 
{
  
  //WRITE YOUR CODE HERE!
  size_t size = 0;
  char **array = NULL;
  if(argc == 1)
  {
    array = read_file(stdin, &size);
    sortData(array, size);
    print_and_free(array, size);
    array = NULL;
  }
  else
  {
    for(size_t i = 1; i < argc; i++)
    {
      FILE *input = fopen(argv[i], "r");
      if(input == NULL)
      {
	fprintf(stderr, "Couldn't open %s file\n", argv[i]);
	return EXIT_FAILURE;
      }
      size = 0;
      array = read_file(input, &size);
      sortData(array, size);
      print_and_free(array, size);
      array = NULL;
      if(fclose(input) != 0)
      {
	fprintf(stderr, "Couldn't close %s file\n", argv[i]);
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}

