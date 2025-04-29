# Topology Program - Matthew Botteon - CSCE350 SP25

# File Summary
topology.h
  Contains the declaration of ReadFile, CheckStar, CheckFullyConnectedMesh, CheckRing, and CheckTopology functions.

topology.cc
  Contains the implementation of functions. ReadFile reads a file with a square matrix separated by spaces, representing an adjacency matrix. CheckStar checks if there is only one central node of all 1's. CheckFullyConnectedMest checks if there are 1's everywhere but the main diagonal. CheckRing checks there are exactly two 1's in each row or column. CheckTopology calls each of these functions separately - I have sacrificed some efficiency for organization.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file

   Example:
  ./topology input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

question_1/
+-- topology.h
+-- topology.cc
+-- input.txt
+-- Makefile
+-- README.md
