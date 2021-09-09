/**
 *  CS5008  Spr 2021
 *  Northeastern University, Seattle
 *  Assignment 4: Quicksort Experimentation
 *
 *  Author: Shefali Khatri (02/24/2021);
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "quicksort.h"

int num_partition_calls = 0;
int num_quicksort_calls = 0;
int num_comparisons = 0;

// swaps two elements in an array
//
// INPUT: the array in which to swap the elements
// INPUT: the index of the first element to be swapped in the array
// INPUT: the index of the second element to be swapped in the array
//
void Swap(int* array, int ind1, int ind2) {
  int tmp = array[ind1];
  array[ind1] = array[ind2];
  array[ind2] = tmp;
}

// Shuffles the elements in an array
//
// INPUT: the array in which the elements are to be shuffled
// INPUT: the length of the array in which elements are to be shuffled
//
void Shuffle(int* array, int len) {
  srand(time(NULL));
  int i;
  for (i = len - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    Swap(array, i, j);
  }
}

// Partitions data in an array based on the pivot. Smaller elements
// are moved to the left of the pivot and larger items to the right
// of the pivot.
//
// INPUT: the array to be partitioned
// INPUT: the smallest index of the array to be partitioned
// INPUT: the largest index of the array to be partitioned
//
// Returns the index position of the pivot
int Partition(int* data, int low, int high) {
  num_partition_calls++;
  int pivot = data[low];
  int leftwall = low;
  int i;
  for (i = low + 1; i <= high; i++) {
    num_comparisons++;
    if (data[i] < pivot) {
      leftwall++;
      Swap(data, i, leftwall);
    }
  }
  Swap(data, low, leftwall);
  return leftwall;
}

// Sorts an array of ints in ascending order using the
// quicksort algorithm
//
// INPUT: the array to be sorted
// INPUT: the smallest index of the array to be sorted
// INPUT: the largest index of the array to be sorted
//
void Quicksort(int* data, int low, int high) {
  num_quicksort_calls++;
  if (low < high) {
    int pivot_location = Partition(data, low, high);
    Quicksort(data, low, pivot_location);
    Quicksort(data, pivot_location + 1, high);
  }
}

// Given an array of 3 values, returns the median
//
// INPUT: the array of three ints
// INPUT: the lowest index of the array
// INPUT: the highest index of the array
//
// Returns the median of the array
//
int GetMedian(int* data, int low, int high) {
  int mid = floor((high + low) / 2);
  if (data[low] > data[mid]) {
    if (data[low] <= data[high]) {
      return data[low];
    } else if (data[mid] >= data[high]) {
      return data[mid];
    } else {
      return data[high];
    }
  } else if (data[low] < data[mid]) {
    if (data[mid] <= data[high]) {
      return data[mid];
    } else if (data[low] >= data[high]) {
      return data[low];
    } else {
      return data[high];
    }
  } else {
    return data[low];
  }
}

// Partitions an array using the median of the array as the pivot.
// Ints smaller than the median are moved to the left of the pivot and
// ints larger than the median are moved to the right of the pivot.
//
// INPUT: the array to partition
// INPUT: the lowest index of the array to partition
// INPUT: the highest index of the array to position
//
// Returns the index location of the pivot
//
int PartitionC(int* data, int low, int high) {
  num_partition_calls++;
  int pivot = GetMedian(data, low, high);
  int i;
  while (low <= high) {
    while (data[low] < pivot) {
      low++;
    }
    while (data[high] > pivot) {
      high--;
    }
    num_comparisons++;
    if (low <= high) {
      Swap(data, low, high);
      low++;
      high--;
    }
  }
  return low;
}

// Sorts an array of ints in ascending order using the quicksort
// algorithm, selecting the median as the pivot
//
// INPUT: the array to be sorted
// INPUT: the smallest index of the array to be sorted
// INPUT: the largest index of the array to be sorted
//
void QuicksortC(int* data, int low, int high) {
  num_quicksort_calls++;
  if (low < high) {
    int pivot_location = PartitionC(data, low, high);
    QuicksortC(data, low, pivot_location - 1);
    QuicksortC(data, pivot_location, high);
  }
}

// Sorts array of ints in ascending order using insertion sort
// algorithm
//
// INPUT: array of ints to be sorted
// INPUT: the largest index of the array to be sorted
//
void InsertionSort(int* data, int max_index) {
  int i;
  for (i = 1; i <= max_index; i++) {
    int j = i;
    while (j > 0 && data[j - 1] > data[j]) {
      Swap(data, j - 1, j);
      j -= 1;
    }
  }
}

// Sorts an array of ints in ascending order using both
// the quicksort algorithm and insertion sort algorithm.
// Insertion sort algorithm is used on arrays of size 5 or less.
//
// INPUT: array of ints to be sorted
// INPUT: lowest index of the array to be sorted
// INPUT: highest index of the array to be sorted
//
void QuicksortD(int* data, int low, int high) {
  const kCutoff = 45;
  num_quicksort_calls++;
  if (low < high) {
    if (high < kCutoff) {
      InsertionSort(data, high);
    } else {
      num_quicksort_calls++;
      int pivot_location = Partition(data, low, high);
      Quicksort(data, low, pivot_location);
      Quicksort(data, pivot_location + 1, high);
    }
  }
}

// Prints an array of ints
//
// INPUT: the array to be printed
// INPUT: the number of elements in the array
//
void PrintArray(int* array, int num_elems) {
  int i;
  printf("[");
  for (i = 0; i < num_elems; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

// Checks whether an array is sorted in ascending order or not
//
// INPUT: the array to check
// INPUT: the number of elements in the array to check
//
// Returns 0 if not sorted and 1 if sorted
int CheckArray(int* array, int num_elems) {
  int i;
  for (i = 1; i < num_elems; i++) {
    if (array[i] < array[i - 1]) {
      printf("NOT SORTED!!!\n");
      return 0;
    }
  }
  printf("SORTED!!\n");
  return 1;
}

// Creates an array of random integers of a given size
//
// INPUT: the number of elements the array should contain
// INPUT: a seed for random ints representing the time the program was called
//
// Returns an array of random ints
//
int* CreateArray(int num_elements, time_t seed) {
  int num_elems = num_elements;
  int* integers = (int*)malloc(sizeof(int) * num_elems);

  time_t t;
  srand(seed);  // (unsigned)time(&t));

  int i;
  for (i = 0; i < num_elems; i++) {
    integers[i] = (rand() % 90) + 10;
  }
  return integers;
}

// Destroys an array from the heap
//
// INPUT: the array to be destroyed
//
void DestroyArray(int* data) { free(data); }

