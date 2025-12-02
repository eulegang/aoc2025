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

int d1::on_zero(const std::vector<Turn> &turns) {
  int dial = 50;
  int zeros = 0;

  for (Turn turn : turns) {
    switch (turn.dir) {
    case Dir::Left:
      dial -= turn.mag;
      break;
    case Dir::Right:
      dial += turn.mag;
      break;
    }

    dial += 100;
    dial %= 100;

    if (dial == 0) {
      zeros++;
    }
  }

  return zeros;
}

int d1::past_zero(const std::vector<Turn> &turns) {
  int dial = 50;
  int zeros = 0;

  for (Turn turn : turns) {
    const int cache = dial;
    switch (turn.dir) {
    case Dir::Left:
      dial -= turn.mag;
      break;
    case Dir::Right:
      dial += turn.mag;
      break;
    }

    int under = 0;
    if (dial < 0) {
      under = ((dial + 1) / -100);
    }

    if (dial < 0 && cache > 0) {
      under++;
    }

    int over = 0;
    if (dial > 100) {
      over = (dial - 1) / 100;
    }

    dial += 10000;
    dial %= 100;

    zeros += under;
    zeros += over;

    if (dial == 0) {
      zeros++;
    }
  }

  return zeros;
}
