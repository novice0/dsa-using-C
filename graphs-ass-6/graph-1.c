#include "graph-1.h"

void dispGraph(int rows, int cols, int A[MAX_ROWS][MAX_COLS])
{
  // Displaying the adjacency matrix which represents the undirected weighted graph
  printf("Adjacency Matrix for the undirected weighted graph is as follows:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (A[i][j] < 10)
      {
        printf("%d  ", A[i][j]);
      }
      else
        printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

void degree(int rows, int cols, int A[MAX_ROWS][MAX_COLS])
{
  int count;
  printf("Following are the degrees of each vertex\n");
  for (int i = 1; i < rows; i++)
  {
    count = 0;
    printf("Degree of vertex %d is: ", i);
    for (int j = 1; j < cols; j++)
    {
      if (A[i][j] != 0)
        count++;
    }
    printf("%d\n", count);
  }
}

int isConnected(int rows, int cols, int A[MAX_ROWS][MAX_COLS])
{
  // If any one of the rows of the adjacency matrix is 0, then the graph is disconnected
  int count;
  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if ((A[i][j] != 0 && A[j][i] == 0)) // Sufficient condition as adjacency matrix is always square
        count++;
    }
    if (count == 0)
      return 0;
    count = 0;
  }
  return 1;
}

int numComponents(int rows, int cols, int A[MAX_ROWS][MAX_COLS])
{
  if (isConnected(rows, cols, A) == 1)
    return 1;

  int comp = 0;
  int parent[rows]; // As number of Rows and Columns are same
  for (int i = 0; i < rows; i++)
  {
    parent[i] = -1;
  }
  for (int i = 1; i < rows; i++)
  {
    for (int j = i; j < cols; j++)
    {
      if (A[i][j] != 0)
      {
        parent[j] = i;
      }
    }
  }
  for (int i = 0; i < rows; i++)
  {
    if (parent[i] == -1)
      comp++;
  }
  return comp - 1;
}

int isAdjacent(int u, int v, int A[MAX_ROWS][MAX_COLS])
{

  if (A[u][v] == 0)
    return 0;
  else
    return 1;
}