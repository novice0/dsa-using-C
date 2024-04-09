#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

// Functions in assignment
void dispGraph(int rows, int cols, int A[MAX_ROWS][MAX_COLS]);
void degree(int rows, int cols, int A[MAX_ROWS][MAX_COLS]);
int isConnected(int rows, int cols, int A[MAX_ROWS][MAX_COLS]);
int numComponents(int rows, int cols, int A[MAX_ROWS][MAX_COLS]); // Gives the number of components if the graph is disconnected and number of vertices in each component
int isAdjacent(int u, int v, int A[MAX_ROWS][MAX_COLS]);