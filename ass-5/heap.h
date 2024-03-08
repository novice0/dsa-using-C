#include <stdio.h>
#include <stdlib.h>

//---Creating Heap Using Explicit Indexing--

//---Explicit Indexing:---
//---1. LC = 2*i
//---2. RC = 2*i+1

//---A single element of array---
typedef struct Ele
{
  int element;
  int index;
} Ele;

//---Array of type Ele---
//---This array of structure will represent heap---
typedef struct Array
{
  int size;
  int len;
  Ele *elements;
} Array;

//---Functions---
void initArray(Array *arr, int size); //---Initializes the Array---
void insert(Array *arr, int data);    //---Inserting elements in the array with explicit indexing---
void makeMaxHeap(Array *arr);         //---Generating Max Heap from the array of structure formed---
void makeMinHeap(Array *arr);         //---Generating Min Heap from the array of structure formed---
void dispArray(Array *arr);           //---Displaying the elements
int deleteAsc(Array *arr);            //---Deleting the root node for Ascending Heap Sort
int deleteDesc(Array *arr);           //---Deleting the root node for Descending Heap Sort
void heapSortAsc(Array *arr);         //---Extension of the delete function on Max Heap---
void heapSortDesc(Array *arr);        //---Extension of the delete function on Min Heap---