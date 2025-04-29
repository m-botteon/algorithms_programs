// Copyright 2025 mbotteon
// Contains the algorithm to check an adjacency matrix for common topologies
// Ring, star, fully connected mesh
// Input is a txt file with the adjacency matrix
// Output is the printed name of topology and execution time

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <chrono>

// Read in an adjacency matrix from a text file
std::vector<std::vector<int>> ReadFile(std::string file_name) {
  // Read the file provided with ifstream
  std::ifstream file(file_name);
  // Create a 2D vector to store rows of ints
  std::vector<std::vector<int>> matrix;
  std::string line;

  // For each line, create a vector with the ints in that line as a row
  while (std::getline(file, line)) {
    std::vector<int> row;
    std::istringstream iss(line);
    int val;
    while (iss >> val) {
      row.push_back(val);
    }
    // Once the end of the line is reached, add that row to the 2D vector
    matrix.push_back(row);
  }
  return matrix;
}

bool CheckStar(std::vector<std::vector<int>> matrix) {
  // Declare a counter for number of zeroes in a row
  int one_count;
  // Declare a placeholder for row of all 1's
  int ones_row = -1;
  // Declare how many 1's should be present in the central node
  int central = matrix.size() - 1;
  
  // Iterate rows
  for (size_t i = 0; i < matrix.size(); ++i) {
    one_count = 0;
    // Iterate columns
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 1) {
        ++one_count;
        // No 1's allowed on diagonal
        if (i == j)
          return false;
      }
    }
    // If row is all 1's but diagonal, and its the only instance, mark it
    if (one_count == central) {
      // Mark as central node
      if (ones_row == -1)
        ones_row = i;
      // Central node already exists
      else
        return false;
    }
    // Otherwise, if number of 1's is not zero, false 
    if (one_count != 0)
      return false;
  }
  // At the conclusion of checking rows, verify the column matches
  if (ones_row != -1) {
    for (int j = 0; j < central; ++j) {
      // If there is a zero somewhere besides the main diagonal, false
      if (matrix[ones_row][j] != 1 && ones_row != j)
        return false;
    }
  }
  // If no false was reached, the matrix is a star
  return true;
}

bool CheckFullyConnectedMesh(std::vector<std::vector<int>> matrix) {
  // Iterate over rows
  for (size_t i = 0; i < matrix.size(); ++i) {
    // Iterate over columns
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      // If an element outside the main diagonal is 0, false
      if (i != j && matrix[i][j] == 0)
        return false;
      // If an element on the main diagonal is 1, false
      if (i == j && matrix[i][j] == 1)
        return false;
    }
  }
  // If no false was reached, the matrix is a fully connected mesh
  return true;
}

bool CheckRing(std::vector<std::vector<int>> matrix) {
  // To store number of 1's
  int one_count;
  
  // Iterate over rows
  for (size_t i = 0; i < matrix.size(); ++i) {
    one_count = 0;
    // Iterate over columns
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      // If a 1 is found, increment
      if (matrix[i][j] == 1) {
        ++one_count;
      }
    }
    // If there are not exactly two 1's, false
    if (one_count != 2)
      return false;
  }
  // If no false was reached, the matrix is a ring
  return true;
}

std::string CheckTopology(std::vector<std::vector<int>> matrix) {
  // No match if not a square matrix
  if (matrix.size() != matrix[0].size())
    return "Matrix does not match any of ring, star, or fully connected mesh.";

  // Call the methods for each particular topology
  if (CheckFullyConnectedMesh(matrix))
    return "Fully Connected Mesh";
  else if (CheckStar(matrix))
    return "Star";
  else if (CheckRing(matrix))
    return "Ring";
  else
    return "Matrix does not match any of ring, star, or fully connected mesh.";
}

int main(int argc, char *argv[]) {
  // Check the number of inputs
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  // Call the ReadFile function to generate the adjacency matrix 
  std::vector<std::vector<int>> matrix = ReadFile(argv[1]);
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
    
  // Display the matrix
  outputFile << "Original matrix:" << std::endl;
  for (const auto& row : matrix) {
    for (int val : row) {
      outputFile << val << ' ';
    }
    outputFile << '\n';
  }
  
  
  // Run the algorithm
  auto start = std::chrono::high_resolution_clock::now();
  std::string result = CheckTopology(matrix);
  auto end = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "Checking for the topology took " << time.count()
             << " ms to run." << std::endl;
  outputFile << result << std::endl;

  return 0;
}

