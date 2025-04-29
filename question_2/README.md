# MergeSort and QuickSort Program - Matthew Botteon - CSCE350 SP25

# File Summary
sort.h
  Contains the declaration of ReadFile, Merge, MergeSort, Partition, and QuickSort functions.

sort.cc
  Contains the implementation of functions. ReadFile reads a file with a line of floating point numbers. Merge is called in MergeSort to combine the array back together. MergeSort recursively splits the array into subarrays to be compared in Merge. Partition is called in QuickSort to determine the correct placement of the pivot element. QuickSort is recursively called until the array is sorted.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file

   Example:
  ./sort input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

question_2/
+-- sort.h
+-- sort.cc
+-- input.txt
+-- Makefile
+-- README.md
