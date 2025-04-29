// Copyright 2025 mbotteon
// Contains source code for Floyd's Algorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

#include "floyd.h"

// Read in a distance matrix from a text file
std::vector<std::vector<float>> ReadFile(std::string file_name) {
  // Read the file provided with ifstream
  std::ifstream file(file_name);
  // Create a 2D vector to store rows of floats
  std::vector<std::vector<float>> matrix;
  std::string line;

  // For each line, create a vector with the floats in that line as a row
  while (std::getline(file, line)) {
    std::vector<float> row;
    std::istringstream iss(line);
    float val;
    while (iss >> val) {
      row.push_back(val);
    }
    // Once the end of the line is reached, add that row to the 2D vector
    matrix.push_back(row);
  }
  return matrix;
}

std::vector<std::vector<float>> Floyd(const std::vector<std::vector<float>> 
                                      weights) {
  // Make a copy of the distance array to be overwritten
  std::vector<std::vector<float>> dist = weights;
  int n = weights.size();
  
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int main(int argc, char *argv[]) {
  // Check the number of inputs
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  // Call the ReadFile function to read the pattern and text
  std::vector<std::vector<float>> matrix = ReadFile(argv[1]);
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
  
  // Display the original matrix
  outputFile << "Original matrix:" << std::endl;
  for (const auto& row : matrix) {
    for (float val : row) {
      outputFile << val << ' ';
    }
    outputFile << '\n';
  }
  outputFile << std::endl;
  
  // Run the algorithm
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<float>> distance = Floyd(matrix);
  auto end = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "Floyd's Algorithm took " << time.count()
             << " ms to run.\n" << std::endl;
  
  // Display the resulting matrix
  outputFile << "Resulting matrix:" << std::endl;
  for (const auto& row : distance) {
    for (float val : row) {
      outputFile << val << ' ';
    }
    outputFile << '\n';
  }
  outputFile << std::endl;

  return 0;
}
 
