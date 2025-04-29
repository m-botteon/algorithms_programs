# Horspool's Algorithm Program - Matthew Botteon - CSCE350 SP25

# File Summary
horspool.h
  Contains the declaration of ReadFile, ShiftTable, and HorspoolSearch functions.

horspool.cc
  Contains the implementation of functions. ReadFile reads a file with two lines, the first being the pattern to search for, and the second being the text to search in. ShiftTable generates a map of shift values for each character. HorspoolSearch utilizes the shift table to quickly parse the text for the pattern.

# Execution Instructions
To run the program:
  Call 'make' to build the executable
  Requires the executable and the input file
  ** Note on input file - the 26 characters of the alphabet should be uppercase.

   Example:
  ./horspool input.txt
  
Upon completion, an output.txt file will be created containing the results of the algorithm.

# File Directory Structure

question_4/
+-- horspool.h
+-- horspool.cc
+-- input.txt
+-- Makefile
+-- README.md
