#include "heap.c"

int main()
{
  int number;
  int integer;
  Array A, B;
  initArray(&B, 100);
  initArray(&A, 100);
  printf("Enter the number of integers to be inserted!\nNumber of Integers = ");
  scanf("%d", &number);
  printf("Start entering the integers from below:\n");
  for (int i = 1; i <= number; i++)
  {
    printf("No. %d = ", i);
    scanf("%d", &integer);
    insert(&A, integer);
  }
  dispArray(&A);
  makeMaxHeap(&A);
  printf("\nMax Heap Representation\n");
  dispArray(&A);
  printf("\nMin Heap Representation\n");
  makeMinHeap(&A);
  dispArray(&A);
  heapSortAsc(&A);
  //---Added the Descending Heap Sort Functionality---
  printf("Enter number of integers to be inserted in the second array.\nNumber of Integers = ");
  scanf("%d", &number);
  printf("Start entering the integers from below:\n");
  for (int i = 1; i <= number; i++)
  {
    printf("No. %d = ", i);
    scanf("%d", &integer);
    insert(&B, integer);
  }
  dispArray(&B);
  heapSortDesc(&B);
  return 0;
}

//---Notes---
//---1. Execute the program to enter number of integers preferably less than 100
//---2. Array is formed with explicit indexing displayed below each of the integer inserted
//---3. Max Heap Representation is formed of the array
//---4. Min Heap Representation is formed from the "Max Heap" transformed array
//---5. Heap Sort is executed on the newly formed Max Heap Representation formed from the subsequent "Min Heap" transformed array
//---6. Heap Sort Function utilised the delete function which extracts the first integer from the Max Heap array and inserts in a new array B.
//---7. B is the Heap Sorted array in ascending order

//---Added Features---
//---1. Similar function utilising Min Heap in Heap Sort to receive a sorted array in descending order.

//---Features to be yet added---
//---1. Heapify function
//---2. Heap as priority queue (both min and max)
//---3. Code in a different file, a real life application of priority queue using heap.