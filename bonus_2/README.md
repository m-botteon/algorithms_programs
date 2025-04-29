# HeapSort Program - Matthew Botteon - CSCE350 SP25

# File Summary
heapsort.h
  Contains the declaration of ReadFile, CheckStar, CheckFullyConnectedMesh, CheckRing, and CheckTopology functions.

heapsort.cc
  Contains the implementation of functions. ReadFile reads a file with two lines, the first being the number of elements in the heap, and the second being the elements. Heapify ensures the data is arranged in a heap so the element removed is the max. HeapSort calls heapify with the unsorted portion of the array to remove the next smallest element.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file

   Example:
  ./heapsort input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

bonus_2/
+-- heapsort.h
+-- heapsort.cc
+-- input.txt
+-- Makefile
+-- README.md
