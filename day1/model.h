#ifndef MODEL_H
#define MODEL_H

#include <cstddef>
#include <string>
namespace d1 {
enum class Dir : char {
  Left = 'L',
  Right = 'R',
};

struct Turn {
  Dir dir;
  std::size_t mag;
  Turn(const std::string &input);
  operator std::string();
};
} // namespace d1

#endif
