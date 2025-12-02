#include <format>
#include <iostream>
#include <ranges>

#include "input.h"
#include "model.h"

using namespace d1;

using std::views::transform;

void part1();

int main() { part1(); }

void part1() {
  const auto inputs = read_lines("day1/input.txt");

  int dial = 50;
  int zeros = 0;

  for (Turn turn : inputs | transform([](auto s) { return Turn(s); })) {
    std::cout << std::string(turn) << std::endl;

    switch (turn.dir) {
    case Dir::Left:
      dial -= turn.mag;
      break;
    case Dir::Right:
      dial += turn.mag;
      break;
    }

    std::cout << std::format("dial: {}", dial) << std::endl;

    dial += 100;
    dial %= 100;

    std::cout << std::format("dial: {}", dial) << std::endl;

    if (dial == 0) {
      zeros++;
    }
  }

  std::cout << std::format("zeros: {}", zeros) << std::endl;
}
