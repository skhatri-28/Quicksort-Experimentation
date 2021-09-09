
# Assignment 4: Quicksort Experimentation

#### Name

Shefali Khatri

## Objectives

* Modifying and understanding implementation of Quicksort Algorithm
* Understanding how implementation details can impact performance of the algorithm

## Overview

This program implements four different variations of the Quicksort algorithm on random int arrays of different sizes.
This program prints reports containing the runtime of each algorithm based on array size.

## Details
This program consists of the following files:  
  + quicksort.h - A header file defining the methods to run the various quicksort algorithms  
  + quicksort.c - A file containing all of the methods to run the various quicksort algorithms
  + main.c - A file to print the reports of the runtime of each algorithm  
  + Makefile - This file contains commands for the compiler

## How to Build and Run the Code

#### Compilation
To compile, call "make quicksort." If compilation is to be done manually, "-lm" must be added after calling "gcc" and filenames as the math.h file is used.

#### Execute run
The following letters correspond to each algorithm:
  + A - Original quicksort algorithm
  + B - Shuffle array followed by Quicksort
  + C - Median Pivot Quicksort
  + D - Quicksort with Insertion Sort

There are 2 methods for executing a run: 

1. Call "make" followed by a space and lowercase letters of the algorithm you want to run or "make all" to run all algorithms
2. Call the executable, followed by "sort", a space, a dash, and lowercase letters of the algorithm you want to run. For example "./a.out sort -d". If you want to run all algorithms, replace the lowercase letters with "all." For example, "./a.out sort -all".

Both of the above methods only work for the following arrangements of letters:
  + a
  + b
  + c
  + d
  + ad
  + abc
  + abd
  + acd
  + bcd
  + all

#### Remove the executable

The executable can be removed by calling "make clean"

### Input

None.

### Output

Printed report of algorithm runtime on different array sizes.


## Summary of What I Learned

There were two overall findings from this assignment. First, I learned how quicksort performs in comparison to insertion sort and second, I learned the difference in runtime of the variations of quicksort. I found that when I ran insertion sort against quicksort, that insertion sort ran faster or at a comparable time to quicksort more than 50% of the time for arrays of size 44 or less. I identified this by conducting 10 trials comparing insertion sort and quicksort for arrays ranging from size 2 to 26 (multiples of 2), arrays ranging from size 30 to 80 (multiples of 10) and arrays size 40 to 50 (increments of 2). In the cases where insertion sort performed at the same time or better than quicksort, I noted a 1. In the cases where insertion sort performed worse, I noted a 0. I then took the probability of a 1 occurring to identify the array sizes where insertion sort performed better more than 50% of the time. I noticed that as the array size grew larger and larger, quicksort started to perform better and insertion sort started to get worse. By the time, I reached an array of size 46 or higher, insertion sort no longer performed better than quicksort and had worse performance more than 50% of the time.

Second, I learned how the runtime changed using variations of quicksort. To conduct this analysis, I ran 3 trials to ensure I had consistency across my results. I also compared the percent changes in runtime of the variations against the original quicksort algorithm, Algorithm A, which used the first element as the pivot. What I found was that Algorithm C, the algorithm which used the median as the pivot had better performance on larger datasets, especially those exceeding 10,000 in size, while Algorithms B(shuffle with quicksort) and D(quicksort with insertion sort) performed better on smaller datasets and were largely comparable with Algorithm D performing marginally better than Algorithm B. As the array size grew to 10,000, Algorithm C started to significantly outperform the other algorithms while the performance of Algorithms B and D remained stable. By the time the array size grew to 300,000, Algorithm C far outperformed the others reducing run time by 97%, on average, from the original quicksort Algorithm, Algorithm A. From this, I concluded that Algorithm C was the best to use on large quantities of data while either Algorithm B or D could be used on smaller sets, with D being the preferred choice. Both algorithms B and D were comparable up to an array size of 20,000 with Algorithm D performing slightly better, on average. However, the reduction in run time gained from Algorithms B and D greatly decreased as the array sizes grew larger. By the time array size reached 50,000, algorithms B and D had significantly deteriorated in performance. In fact as array size grew, algorithms B and D sometimes performed even worse than the original quicksort algorithm, algorithm A. This was generally seen more with Algorithm D than Algorithm B. As array size grew past 50,000, the difference in Algorithms A and B was minor enough that they could be considered comparable, with algorithm D performing slightly worse. Overall, there are significant pros to choosing algorithm C when working with big data, and algorithms B and D when working with smaller data. Algorithm A did not perform the best under any array size and would be the least preferred option. If size is unknown, Algorithm C would be the best choice to use because while it did not have the best performance on smaller datasets, the difference between Algoriths B, C, and D on smaller data was minimal. The results from the 3 trials I ran to draw my conclusions are included below:

      
|      | 1000 |  10000 | 20000 | 50000 | 100000 | 300000  |
|------|------|--------|-------|-------|--------|---------|  
|Alg A:| 314  |  6271  | 11178 | 40595 | 172445 | 1557722 | 
|Alg B:| 113  |  2384  | 7378  | 41110 | 167075 | 1641753 |   
|Alg C:| 127  |  1152  | 2330  | 6213  | 12747  | 39775   |   
|Alg D:| 111  |  2314  | 7370  | 43301 | 176756 | 1700673 |    

|      | 1000 |  10000 | 20000 | 50000 | 100000 | 300000  |     
|------|------|--------|-------|-------|--------|---------| 
|Alg A:| 337  |  6816  | 9660  | 41443 | 164032 | 1551888 |   
|Alg B:| 118  |  2328  | 7465  | 40931 | 167241 | 1565433 |   
|Alg C:| 128  |  1285  | 2570  | 6703  | 13739  | 40547   | 
|Alg D:| 110  |  2352  | 7702  | 43834 | 180363 | 1615285 |   

|      | 1000 |  10000 | 20000 | 50000 | 100000 | 300000  |   
|------|------|--------|-------|-------|--------|---------|
|Alg A:| 304  |  6452  | 11172 | 44290 | 178773 | 1704064 |   
|Alg B:| 122  |  2750  | 8148  | 44646 | 184971 | 1700427 |   
|Alg C:| 144  |  1196  | 2433  | 6252  | 13241  | 40542   | 
|Alg D:| 105  |  2312  | 7565  | 42965 | 175611 | 16495512|     


## Summary of Overall Assignment

1. Resources used: Youtube HackerRank video on Quicksort algorithm, GeekforGeeks website to understand how to shuffle elements, wikipedia to understand insertion sort, stack overflow
   for how to pass a method as a parameter

2. Time spent on the assignment: 30-40 hours

3. What was the most challenging part of this assignment? The directions were a little unclear which required me to rethink and revise my code multiple times.

4. What did you like about this assignment? It allowed me to understand how the different algorithms perform in practice instead of just thinking of big O complexity. This code also
required me to think outside the box about organization.

5. How could this assignment be improved? A bit more clarity in the assignment description 
