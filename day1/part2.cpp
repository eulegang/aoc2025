#include <format>
#include <iostream>

#include "input.h"
#include "model.h"

int main() {
  const auto inputs = read_lines("day1/input.txt");
  std::vector<d1::Turn> turns;
  for (const auto &input : inputs) {
    turns.push_back(d1::Turn(input));
  }

  std::cout << std::format("zeros: {}", d1::past_zero(turns)) << std::endl;
}
