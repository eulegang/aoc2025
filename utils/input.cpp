#include "input.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::string read_file(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("unable to open file");
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();

  return buffer.str();
}

std::vector<std::string> read_lines(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("unable to open file");
  }
  auto result = std::vector<std::string>{};

  for (std::string line; std::getline(file, line, '\n');) {
    result.push_back(line);
  }

  return result;
}
