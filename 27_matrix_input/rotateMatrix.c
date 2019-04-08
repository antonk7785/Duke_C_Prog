#include <stdio.h>
#include <stdlib.h>

#define M_S 10

void read_matrix(FILE * f, int matrix[M_S][M_S]);

void rotate(int matrix[M_S][M_S]);

void print_matrix(int matrix[M_S][M_S]);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
      fprintf(stderr,"Usage: ./rotateMatrix sample.txt\n");
      return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL)
  {
    perror("Could not open file");
    return EXIT_FAILURE;
  }

  int  matrix[M_S][M_S]; 

  read_matrix(f, matrix);
  rotate(matrix);

  if (fclose(f) != 0)
  {
      perror("Failed to close the input file!");
      return EXIT_FAILURE;
  }

  print_matrix(matrix);

  return EXIT_SUCCESS;
}

void read_matrix(FILE * f, int matrix[M_S][M_S])
{
  int c;
  int i = 0;
  int j = 0;
  while ((c = fgetc(f)) != EOF)
  {
    if (i < M_S)
    {
      if (c != 10 && j < M_S)
      {
        //printf("%c", c);
        matrix[i][j] = c;
        j++;
      }
      else
      {
        if (j == M_S && c == 10)
        {
          i++;
          j = 0;
          //printf("\n");
        }
        else
        {   
          if (j < M_S && c == 10)
          {
            fprintf(stderr, "Invalid input: line is too short\n");
            exit(EXIT_FAILURE);
          }
          if (j >= M_S)
          {
            fprintf(stderr, "Invalid input: line is too long\n");
            exit(EXIT_FAILURE);
          }
        }
      }
    }
    else
    {
      fprintf(stderr, "Invalid input: line is too long\n");
      exit(EXIT_FAILURE);
    }
  }
  if (i <  M_S)
  { 
    fprintf(stderr, "Invalid input: line is too short\n");
    exit(EXIT_FAILURE);
  } 
}

void rotate(int matrix[M_S][M_S])
{
  int temp[M_S][M_S];
  for (int i = 0; i < M_S; i++)
    {
      for (int j = 0; j < M_S; j++)
	{
	  temp[i][j] = matrix[M_S - 1 - j][i];
	}
    }
  for (int i = 0; i < M_S; i++)
    {
      for (int j = 0; j < M_S; j++)
	{
	  matrix[i][j] = temp[i][j];
	}
    }
}

void print_matrix(int matrix[M_S][M_S])
{
  for (int i = 0; i < M_S; i++)
  {
    for (int j = 0; j < M_S; j++)
    {
      printf("%c", matrix[i][j]);
    }
    
    printf("\n");
  }
}
