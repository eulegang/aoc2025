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

void chomp(std::string &s) {
  if (!s.empty() && (s.back() == '\n' || s.back() == '\r')) {
    s.pop_back();
  }
}

std::vector<std::string_view> split(std::string_view s,
                                    std::string_view delimiter) {
  std::vector<std::string_view> tokens;
  size_t start = 0;
  size_t end = s.find(delimiter);

  while (end != std::string::npos) {
    tokens.push_back(s.substr(start, end - start));
    start = end + delimiter.length();
    end = s.find(delimiter, start);
  }
  tokens.push_back(s.substr(start, s.length() - start)); // Add the last token
  return tokens;
}
