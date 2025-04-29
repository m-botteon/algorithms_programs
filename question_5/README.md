# Floyd's Algorithm Program - Matthew Botteon - CSCE350 SP25

# File Summary
floyd.h
  Contains the declaration of ReadFile and Floyd functions.

floyd.cc
  Contains the implementation of functions. ReadFile reads a file with a distance matrix of floating point values. Floyd generates a distance matrix that contains the shortest path for each vertex represented in the matrix.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file
  ** Note on the input file - infinity values are represented by 1000 or some other large number.

   Example:
  ./floyd input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

question_5/
+-- floyd.h
+-- floyd.cc
+-- input.txt
+-- Makefile
+-- README.md
