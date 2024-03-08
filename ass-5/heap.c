#include "heap.h"

void initArray(Array *arr, int size)
{
  arr->size = size;
  arr->len = 0;
  arr->elements = (Ele *)malloc(size * sizeof(Ele));
  for (int i = 0; i < size; i++)
    arr->elements[i].index = -1;
  return;
}

void insert(Array *arr, int data)
{
  arr->elements[arr->len].element = data;
  arr->elements[arr->len].index = arr->len + 1;
  arr->len++;
  return;
}

void makeMaxHeap(Array *arr)
{
  for (int j = 0; j < arr->len; j++)
  {
    int temp = arr->elements[j].element;
    while (j > 0 && temp > arr->elements[(j + 1) / 2 - 1].element)
    {
      arr->elements[j].element = arr->elements[(j + 1) / 2 - 1].element;
      j = (j + 1) / 2 - 1;
    }
    arr->elements[j].element = temp;
  }
  return;
}

void makeMinHeap(Array *arr)
{
  for (int j = 0; j < arr->len; j++)
  {
    int temp = arr->elements[j].element;
    while (j > 0 && temp < arr->elements[(j + 1) / 2 - 1].element)
    {
      arr->elements[j].element = arr->elements[(j + 1) / 2 - 1].element;
      j = (j + 1) / 2 - 1;
    }
    arr->elements[j].element = temp;
  }
  return;
}

void dispArray(Array *arr)
{
  printf("Array is: \n");
  for (int i = 0; i < arr->len; i++)
  {
    if (arr->elements[i].element <= 9)
    {
      printf("|  %d |", arr->elements[i].element);
    }
    else
    {
      printf("| %d |", arr->elements[i].element);
    }
  }
  printf("\n");
  for (int i = 0; i < arr->len; i++)
  {
    if (arr->elements[i].index <= 9)
      printf("|  %d |", arr->elements[i].index);
    else
      printf("| %d |", arr->elements[i].index);
  }
  printf("\n");
}

int deleteAsc(Array *arr)
{
  int x = arr->elements[0].element;
  arr->elements[0].element = arr->elements[arr->len - 1].element;
  int i = 0;
  int temp;
  arr->len--;
  arr->elements[arr->len].index = -1;
  while (arr->elements[2 * i + 1].index != -1)
  {
    if (arr->elements[2 * i + 1].element > arr->elements[2 * i + 2].element)
    {
      temp = arr->elements[i].element;
      arr->elements[i].element = arr->elements[2 * i + 1].element;
      arr->elements[2 * i + 1].element = temp;
      i = 2 * i + 1;
    }
    else
    {
      temp = arr->elements[i].element;
      arr->elements[i].element = arr->elements[2 * i + 2].element;
      arr->elements[2 * i + 2].element = temp;
      i = 2 * i + 2;
    }
  }
  return x;
}

int deleteDesc(Array *arr)
{
  int x = arr->elements[0].element;
  arr->elements[0].element = arr->elements[arr->len - 1].element;
  int i = 0;
  int temp;
  arr->len--;
  arr->elements[arr->len].index = -1;
  while (arr->elements[2 * i + 1].index != -1)
  {
    if (arr->elements[2 * i + 1].element < arr->elements[2 * i + 2].element)
    {
      temp = arr->elements[i].element;
      arr->elements[i].element = arr->elements[2 * i + 1].element;
      arr->elements[2 * i + 1].element = temp;
      i = 2 * i + 1;
    }
    else
    {
      temp = arr->elements[i].element;
      arr->elements[i].element = arr->elements[2 * i + 2].element;
      arr->elements[2 * i + 2].element = temp;
      i = 2 * i + 2;
    }
  }
  return x;
}

void heapSortDesc(Array *arr)
{
  printf("\nExecuting Heap Sort on the following Max Heap Representation\n");
  makeMaxHeap(arr);
  dispArray(arr);
  Array B;
  initArray(&B, 100);
  int length = arr->len;
  for (int i = 0; i < length; i++)
  {
    insert(&B, deleteAsc(arr));
  }
  printf("Sorted Array (Descending) using Heap Sort is as follows:\n");
  dispArray(&B);
  return;
}

void heapSortAsc(Array *arr)
{
  printf("\nExecuting Heap Sort on the following Min Heap Representation\n");
  makeMinHeap(arr);
  dispArray(arr);
  Array B;
  initArray(&B, 100);
  int length = arr->len;
  for (int i = 0; i < length; i++)
  {
    insert(&B, deleteDesc(arr));
  }
  printf("Sorted Array (Ascending) using Heap Sort is as follows:\n");
  dispArray(&B);
  return;
}