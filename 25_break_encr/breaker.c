#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int freq_counter(FILE * f) 
{    
  int c;
  int freq_arr[26] = {0};    
  while ((c = fgetc(f)) != EOF) 
  {        
    if (isalpha(c)) 
    {            
      c = tolower(c);            
      c -= 'a';            
      freq_arr[c]++;            
    }        
  }
  
  int max = freq_arr[0];
  c = 'a';
  for (int i = 0; i < 26; i++)
  {
    if (freq_arr[i] > max)
    {
      max = freq_arr[i];
      c = i + 'a';
    }
  }

  return c;
}

void decrypt(int c)
{
  unsigned key = 0; 
  if (c < 101)
  {
    key = 26 - (101 - c);
  }
  else
  {
    key = c - 101;
  }

  printf("%d\n", key);

}

int main(int argc, char ** argv) {  
  if (argc != 2) 
  {    
    fprintf(stderr,"Usage: ./breaker input.txt\n");    
    return EXIT_FAILURE;  
  }  
    
  FILE * f = fopen(argv[1], "r");  
  if (f == NULL) 
  {    
    perror("Could not open file");    
    return EXIT_FAILURE;  
  }  
  
  decrypt(freq_counter(f));  
  if (fclose(f) != 0) 
  {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE;  
  }  
  
  return EXIT_SUCCESS;
}

