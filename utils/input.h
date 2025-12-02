#ifndef INTPUT_H
#define INTPUT_H

#include <string>
#include <vector>

std::string read_file(const std::string &filename);
std::vector<std::string> read_lines(const std::string &filename);

class bad_input : private std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "malformed input supplied";
  }
};
#endif
