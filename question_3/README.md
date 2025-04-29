# HeapBottomUp Algorithm Program - Matthew Botteon - CSCE350 SP25

# File Summary
heap_bottom_up.h
  Contains the declaration of ReadFile, MinHeapBottomUp, and MaxHeapBottomUp functions.

heap_bottom_up.cc
  Contains the implementation of functions. ReadFile reads a file with two lines, the first being the number of elements in the heap, and the second being the elements. MaxHeapBottomUp constructs a heap rooted at the maximum element that follows parental dominance. MinHeapBottomUp constructs a heap at the minimum element that follows parental submission.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file

   Example:
  ./heap_bottom_up input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

question_3/
+-- heap_bottom_up.h
+-- heap_bottom_up.cc
+-- input.txt
+-- Makefile
+-- README.md
