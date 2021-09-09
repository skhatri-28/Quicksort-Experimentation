/**
 *  CS5008  Spr 2021
 *  Northeastern University, Seattle
 *  Assignment 4: Quicksort Experimentation
 *
 *  Author: Shefali Khatri (02/24/2021);
 */

#include <stdio.h>
#include "quicksort.h"
#include <stdint.h>
#include <string.h>

// Runs the quicksort algorithm on an array of ints. It uses the first element
// of the array as the pivot.
//
// INPUT: the array to be sorted
// INPUT: the lowest index of the array
// INPUT: the largest index of the array
//
void AlgorithmA(int* data, int low, int high) { Quicksort(data, low, high); }

// Shuffles an array of ints and runs the quicksort algorithm on them. It uses
// the first element of the array as the pivot.
//
// INPUT: the array to be sorted
// INPUT: the lowest index of the array
// INPUT: the largest index of the array
//
void AlgorithmB(int* data, int low, int high) {
  Shuffle(data, high + 1);
  Quicksort(data, low, high);
}

// Runs the quicksort algorithm on an array of ints. It uses the median of the
// first,
// middle, and last element of the array as the pivot.
//
// INPUT: the array to be sorted
// INPUT: the lowest index of the array
// INPUT: the largest index of the array
//
void AlgorithmC(int* data, int low, int high) { QuicksortC(data, low, high); }

// Runs the quicksort algorithm on an array of ints. If the array or sub-array
// of
// quicksort are below size 5, insertion sort is used on the array.
//
// INPUT: the array to be sorted
// INPUT: the lowest index of the array
// INPUT: the largest index of the array
//
void AlgorithmD(int* data, int low, int high) { QuicksortD(data, low, high); }

// Prints a report of the runtime on different size arrays of ints using the
// given algorithm
//
// INPUT: a method that corresponds to a specific sorting algorithm
// INPUT: a string that represents a specific algorithm
// INPUT: an array containing the lengths of the random int arrays to generate
// INPUT: the length of the array containing the lengths of the random in arrays
// to generate
// INPUT: the seed to use for generating arrays of random ints
//
void RunAlgorithm(void (*f)(int*, int, int), char* algo, int* arraySizes,
                  int len, time_t seed) {
  const kSecondsMultiplier = 1000000;
  int64_t time[6];
  struct timeval begin, end;
  int i;
  for (i = 0; i < len; i++) {
    int* integers = CreateArray(arraySizes[i], seed);
    gettimeofday(&begin, NULL);
    (*f)(integers, 0, arraySizes[i] - 1);
    gettimeofday(&end, NULL);
    int64_t seconds = (end.tv_sec - begin.tv_sec);
    int64_t micros =
        ((seconds * kSecondsMultiplier) + end.tv_usec) - (begin.tv_usec);
    DestroyArray(integers);
    // printf("micros:%d\n", micros);
    time[i] = micros;
  }
  printf("Alg %s:\t%d\t%d\t%d\t%d\t%d\t%d\n", algo, time[0], time[1], time[2],
         time[3], time[4], time[5]);
}

int main(int argc, char** argv) {
  time_t seed;
  int arraySizes[] = {1000, 10000, 20000, 50000, 100000, 300000};
  int len = 6;
  int i;
  const kExpectedArgs = 3;

  // prints header for report
  if (argc == kExpectedArgs) {
    if ((strstr(argv[1], "sort") != NULL) && (strstr(argv[2], "-") != NULL)) {
      for (i = 0; i < len; i++) {
        printf("\t%d", arraySizes[i]);
      }
      printf(
          "\n--------------------------------------------------------------\n");
    }
    if (strcmp(argv[1], "sort") == 0) {
      // runs if flag is sort -a
      if (strcmp(argv[2], "-a") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
      }
      // runs if flag is sort -b
      if (strcmp(argv[2], "-b") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmB, "B", arraySizes, len, seed);
      }
      // runs if flag is sort -c
      if (strcmp(argv[2], "-c") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmC, "C", arraySizes, len, seed);
      }
      // runs if flag is sort -d
      if (strcmp(argv[2], "-d") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
      // runs if flag is sort -abc
      if (strcmp(argv[2], "-abc") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
        RunAlgorithm(AlgorithmB, "B", arraySizes, len, seed);
        RunAlgorithm(AlgorithmC, "C", arraySizes, len, seed);
      }
      // runs if flag is sort -ad
      if (strcmp(argv[2], "-ad") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
      // runs if flag is sort -bcd
      if (strcmp(argv[2], "-bcd") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmB, "B", arraySizes, len, seed);
        RunAlgorithm(AlgorithmC, "C", arraySizes, len, seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
      // runs if flag is sort -abd
      if (strcmp(argv[2], "-abd") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
        RunAlgorithm(AlgorithmB, "B", arraySizes, len, seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
      // runs if flag is sort -acd
      if (strcmp(argv[2], "-acd") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
        RunAlgorithm(AlgorithmC, "C", arraySizes, len, seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
      // runs if flag is sort -all
      if (strcmp(argv[2], "-all") == 0) {
        time(&seed);
        RunAlgorithm(AlgorithmA, "A", arraySizes, len, seed);
        RunAlgorithm(AlgorithmB, "B", arraySizes, len, seed);
        RunAlgorithm(AlgorithmC, "C", arraySizes, len, seed);
        RunAlgorithm(AlgorithmD, "D", arraySizes, len, seed);
      }
    }
  }
  return 0;
}
