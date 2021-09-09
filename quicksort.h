/**
 *  CS5008  Spr 2021
 *  Northeastern University, Seattle
 *  Assignment 4: Quicksort Experimentation
 *
 *  Author: Shefali Khatri (02/24/2021);
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef QUICKSORT_H
#define QUICKSORT_H

// swaps two elements in an array
//
// INPUT: the array in which to swap the elements
// INPUT: the index of the first element to be swapped in the array
// INPUT: the index of the second element to be swapped in the array
//
void Swap(int* array, int ind1, int ind2);

// Shuffles the elements in an array
//
// INPUT: the array in which the elements are to be shuffled
// INPUT: the length of the array in which elements are to be shuffled
//
void Shuffle(int* array, int len);

// Partitions data in an array based on the pivot. Smaller elements
// are moved to the left of the pivot and larger items to the right
// of the pivot.
//
// INPUT: the array to be partitioned
// INPUT: the smallest index of the array to be partitioned
// INPUT: the largest index of the array to be partitioned
//
// Returns the index position of the pivot
int Partition(int* data, int low, int high);

// Sorts an array of ints in ascending order using the
// quicksort algorithm
//
// INPUT: the array to be sorted
// INPUT: the smallest index of the array to be sorted
// INPUT: the largest index of the array to be sorted
//
void Quicksort(int* data, int low, int high);

// Given an array of 3 values, returns the median
//
// INPUT: the array of three ints
// INPUT: the lowest index of the array
// INPUT: the highest index of the array
//
// Returns the median of the array
//
int GetMedian(int* data, int low, int high);

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
int PartitionC(int* data, int low, int high);

// Sorts an array of ints in ascending order using the quicksort
// algorithm, selecting the median as the pivot
//
// INPUT: the array to be sorted
// INPUT: the smallest index of the array to be sorted
// INPUT: the largest index of the array to be sorted
//
void QuicksortC(int* data, int low, int high);

// Sorts array of ints in ascending order using insertion sort
// algorithm
//
// INPUT: array of ints to be sorted
// INPUT: the largest index of the array to be sorted
//
void InsertionSort(int* data, int max_index);

// Sorts an array of ints in ascending order using both
// the quicksort algorithm and insertion sort algorithm.
// Insertion sort algorithm is used on arrays of size 5 or less.
//
// INPUT: array of ints to be sorted
// INPUT: lowest index of the array to be sorted
// INPUT: highest index of the array to be sorted
//
void QuicksortD(int* data, int low, int high);

// Prints an array of ints
//
// INPUT: the array to be printed
// INPUT: the number of elements in the array
//
void PrintArray(int* array, int num_elems);

// Checks whether an array is sorted in ascending order or not
//
// INPUT: the array to check
// INPUT: the number of elements in the array to check
//
// Returns 0 if not sorted and 1 if sorted
int CheckArray(int* array, int num_elems);

// Creates an array of random integers of a given size
//
// INPUT: the number of elements the array should contain
// INPUT: a seed for random ints representing the time the program was called
//
// Returns an array of random ints
//
int* CreateArray(int num_elements, time_t seed);

// Destroys an array from the heap
//
// INPUT: the array to be destroyed
//
void DestroyArray(int* data);

#endif
