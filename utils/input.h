#ifndef INTPUT_H
#define INTPUT_H

#include <string>
#include <vector>

std::string read_file(const std::string &filename);
std::vector<std::string> read_lines(const std::string &filename);

std::vector<std::string_view> split(std::string_view s,
                                    std::string_view delimiter);

void chomp(std::string &s);

class bad_input : private std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "malformed input supplied";
  }
};

template <std::constructible_from<std::string_view> T>
std::vector<T> splitT(std::string_view s, std::string_view delimiter) {
  std::vector<T> ts;
  size_t start = 0;
  size_t end = s.find(delimiter);

  while (end != std::string::npos) {
    ts.push_back(T(s.substr(start, end - start)));
    start = end + delimiter.length();
    end = s.find(delimiter, start);
  }
  ts.push_back(T(s.substr(start, s.length() - start)));
  return ts;
}

#endif
