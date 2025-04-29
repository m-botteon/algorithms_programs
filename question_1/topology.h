// Copyright 2025 mbotteon
// Contains the function declartions for common topology checks

#ifndef TOPOLOGY_H_
#define TOPOLOGY_H_

#include <vector>
#include <sstream>
#include <string>

// Read in an adjacency matrix from a text file
std::vector<std::vector<int>> ReadFile(std::string file_name);

bool CheckStar(std::vector<std::vector<int>> matrix);

bool CheckFullyConnectedMesh(std::vector<std::vector<int>> matrix);

bool CheckRing(std::vector<std::vector<int>> matrix);

std::string CheckTopology(std::vector<std::vector<int>> matrix);

#endif // TOPOLOGY_H_

