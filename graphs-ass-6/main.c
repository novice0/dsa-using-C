#include "graph-1.c"

int main()
{
  // Opening the text file for reading using a pointer
  FILE *f = fopen("graph-1.txt", "r");
  if (!f)
  {
    printf("Unable to open file!\n");
    return 1;
  }

  int rows, cols;
  int adjM[MAX_ROWS][MAX_COLS];

  // Reading the number of rows and columns from the text file
  fscanf(f, "%d %d", &rows, &cols);

  // Reading the matrix elements from the file
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      fscanf(f, "%d ", &adjM[i][j]);
    }
  }

  fclose(f);

  printf("\n"); // Divider

  dispGraph(rows, cols, adjM);

  printf("\n"); // Divider

  degree(rows, cols, adjM);

  printf("\n"); // Divider

  if (isConnected(rows, cols, adjM) == 1)
  {
    printf("Given graph is connected.\n");
  }
  else
    printf("Given graph is disconnected.\n");

  // This piece of code displays whether a pair of vertices is adjacent or not.
  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (i == j)
        continue;
      else if (isAdjacent(i, j, adjM) == 1)
      {
        printf("Vertices %d and %d are adjacent.\n", i, j);
      }
      else
        printf("Vertices %d and %d are not adjacent.\n", i, j);
    }
    printf("\n");
  }

  printf("\n"); // Divider

  printf("The number of components in given graph is: %d\n", numComponents(rows, cols, adjM));
  return 0;
}