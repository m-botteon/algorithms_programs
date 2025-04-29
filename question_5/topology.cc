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

std::string CheckTopology(std::vector<std::vector<int>> matrix) {
  // Ensure n > 3
  if (matrix.size < 4)
    return false;
  // Initialize ring, star, and fully connected mesh as true to begin
  bool r = true;
  bool s = true;
  bool f = true;
}

bool CheckRing(std::vector<std::vector<int>> matrix) {
  // Each vertex should have exactly two neighbors, represented by two 1's
    int neighbor_count = 0;
    for (int i = 0; i < matrix.size() ++i) {
      neighbor_count = 0;
      for (int j = 0; j < matrix.size(); ++j) {
        if (matrix[i][j] == 0) {
          ++neighbor_count;
        }
      }
      if (neighborCount != 2) {
        return false; // A node does not have exactly two neighbors
      }
    }


  std::vector<bool> visited(numNodes, false);
  int startNode = 0; // Start DFS from node 0
  int count = 0; // Count the number of visited nodes

  // DFS function to traverse the graph
  std::function<void(int, int)> dfs = 
  [&](int node, int parent) { // Added parent to avoid going back to the same node.
      visited[node] = true;
      count++;

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
      if (matrix[node][neighbor] == 1 && neighbor != parent) {
        if (!visited[neighbor]) {
          dfs(neighbor, node); // Pass the current node as parent
        }
        else if (neighbor == startNode) {
        // Check for back edge to the starting node.
        // A ring has exactly one such back edge.
          continue; // allow the one back edge.
        }
        else
          return; // Found a cycle that is not the ring.
            }
        }
    };

    dfs(startNode, -1); // Start DFS from node 0 with no parent

    // If all nodes are visited and only two neighbors for each node, it's a ring.
    return (count == numNodes);
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
  outputFile << "Checking for the topoloyg took " << time.count()
             << " ms to run." << std::endl;
  outputFile << result << std::endl;

  return 0;
}











std::string CheckTopology(std::vector<std::vector<int>> matrix) {
  // Initialize ring, star, and fully connected mesh as true to begin
  bool r = true;
  bool s = true;
  bool f = true;
  // Initialize the central node as false for the star topology
  bool central_node_found = false;
  // Declare a counter for number of zeroes in a row
  int zero_count;
  
  for (int i = 0; i < matrix.size(); ++i) {
    // Reset counter at the start of each row
    zero_count = 0;
    for (int j = 0; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 0)
        ++zero_count;
        // Fully connected mesh is impossible with a 0 anywhere but main diag
        if (i != j) {
          f = false;
      }
    }
    // Check if there are two 1's - if not, ring is impossible
    if (zero_count != matrix[0].size() - 2)
      r = false;
    // Check if there are either 1 or all but one zeroes
    if (zero_count != 1 || zero_count != matrix[0].size() - 1) {
      // Check if a row of all but one zeroes is already found
      if (central_node_found)
        // Star is impossible with two central nodes
        s = false;
      // Check if this is the first row found with all but one 1's
      if (!central_node_found && zero_count == 1)
        central_node_found = true;
    }
  }
  
  // A ring topology cannot be certain just based on two 1's in each row
  // Check for two 1's in each column to ensure
  
  // If a central node is never found, star is impossible
  if (!central_node_found)
    s = false;

  // Upon completion of the loops, if a bool remains true, the matrix fits
  if (r)
    return "Ring";
  else if (s)
    return "Star";
  else if (f)
    return "Fully Connected Mesh";
  else
    return "Matrix does not match any of ring, star, or fully connected mesh.";
}


bool CheckRing(std::vector<std::vector<int>> matrix) {
  // To store columns of vertices with connecting edges
  int vertex1;
  int vertex2;
  std::unordered_map<int, bool> visited;
  for (size_t i = 0; i < matrix.size(); ++i)
    visited[i] = false;
  
  // Iterate over rows that have not yet been visited
  for (size_t i = 0; i < matrix.size() && !visited[i]; ++i) {
    vertex1 = -1;
    vertex2 = -1;
    // Iterate over columns
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      // If a 1 is found, store the column in one of two placeholders
      if (matrix[i][j] == 1) {
        if (vertex1 == -1)
          vertex1 = j;
        else if (vertex2 == -1)
          vertex2 = j;
        // If both are full, more than two 1's have been found
        else
          return false;
      }
    }
    // If both placeholders are full, mark as visited
    if (vertex1 != -1 && vertex2 != -1) {
      visited[i] = true;
      // Check the connectivity of the two vertices
      if (matrix[vertex1][i] != 1)
        return false;
      if (matrix[vertex2][i] != 1)
        return false;
    }
  }
  // If no false was reached, the matrix is a fully connected mesh
  return true;
}

