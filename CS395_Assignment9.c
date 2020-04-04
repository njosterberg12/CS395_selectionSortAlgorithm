/******************************************************************************************************
 * Id: oste1799
 * Purpose:
 *  This following program implements an algorithm that does a selection sort
 * Input:
 *  ./assignment9
 * Output:
 *  ex.
 * Compile:
 *  ex. gcc -Wall -o assignment9 assignment9.c
 *
 ****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void selectionSort(int *, int);
void printArray(int *, int);
int main(int argc, char *argv[]){
   int size = argc-1;
   int i;
   if (argc < 2)
   {
      printf("Not enough values to sort. Please enter more values.");
      return 0;
   }
   int *arr = malloc(sizeof(int)*size); // dynamic memory allocation for integer array of size argc-1
   for(i = 0; i < size; i++)
   {
      arr[i] = atoi(argv[i+1]);
   }
   printArray(arr, size);
   selectionSort(arr, size);
   free(arr);
   return 0;
}
// this function prints the array
void printArray(int *arr, int size){
   int i;
   for(i = 0; i < size; i++)
   {
      printf("%i ", arr[i]); // prints array element at i position in the array
   }
   printf("\n");
}
// this function does a selection sort of the values in the array
void selectionSort(int *arr, int size){
   int i, j;
   int temp;
   for(i = 0; i < size-1; i++)
   {
      int minVal = i; // min val set equal to first array val
      arr[minVal] = arr[i];
      for(j = i+1; j < size; j++)
      {
         if(arr[j] < arr[minVal]) // compares minval to next element which is at the jth position
         {
            minVal = j; // if arr[j] is less than arr[minVal], minVal is set to j value
         }
      }
      temp = arr[i]; // temp variable set to hold current array val at position i so swap can happen
      arr[i] = arr[minVal]; // arr[i] is set to arr[minVal]
      arr[minVal] = temp; // minVal becomes the saved temp Val
      printArray(arr, size);
   }
   printArray(arr, size);
}
