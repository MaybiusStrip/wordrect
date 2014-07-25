#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// Sorts the array of characters based on their weight, provided in two arrays,
// using quicksort.
// ie:
//     characters: [a, b, c, d]
//     weights:    [3, 1, 2, 4]
//   would update the arrays to:
//     characters: [b, c, a, d]
//     weighs:     [1, 2, 3, 4]
void sortCharactersByWeight(int weights[], char characters[], int left, int right) {
  int pivotIndex;

  if( left < right ) {
    pivotIndex = partition(weights, characters, left, right);
    sortCharactersByWeight(weights, characters, left, pivotIndex - 1);
    sortCharactersByWeight(weights, characters, pivotIndex + 1, right);
  }
}

int partition(int weights[], char characters[], int left, int right) {
  int pivot, i, j;
  pivot = weights[left];
  i = left; j = right + 1;

  while (1) {
    do ++i; while (weights[i] >= pivot && i <= right);
    do --j; while (weights[j] < pivot);
    if (i >= j) break;
    swap(weights, characters, i, j);
  }
  swap(weights, characters, left, j);
  return j;
}

void swap(int iarray[], char carray[], int i, int j) {
  int temp = iarray[i];
  iarray[i] = iarray[j];
  iarray[j] = temp;

  temp = carray[i];
  carray[i] = carray[j];
  carray[j] = temp;
}
