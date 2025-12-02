#include "model.h"
#include "input.h"

#include <format>

d1::Turn::Turn(const std::string &input) {
  auto it = input.begin();
  if (it == input.end()) {
    throw bad_input();
  }

  switch (*it) {
  case 'L':
  case 'R':
    dir = static_cast<Dir>(*it);
    break;
  default:
    throw bad_input();
  }

  it++;

  mag = 0;

  while (it != input.end()) {
    if (*it < '0' || *it > '9') {
      throw bad_input();
    }

    mag *= 10;
    mag += *it - '0';

    it++;
  }
}

d1::Turn::operator std::string() {
  return std::format("{}: {}", static_cast<char>(dir), mag);
}
