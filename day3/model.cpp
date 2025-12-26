#include "model.h"
#include <algorithm>
#include <span>

using namespace day3;

std::ostream &day3::operator<<(std::ostream &os, const day3::JoltageRow &row) {
  for (const auto &ch : row.joltage) {
    os << static_cast<char>(ch + '0') << " ";
  }

  return os;
}

JoltageRow::JoltageRow(std::vector<char> joltage)
    : joltage{std::move(joltage)} {}

JoltageRow::JoltageRow(std::initializer_list<int> list) : joltage{} {
  for (auto &li : list) {
    joltage.push_back(li);
  }
}

bool JoltageRow::operator==(const JoltageRow &row) const {
  return this->joltage == row.joltage;
}

int day3::largestTwoDigitJolt(day3::JoltageRow row) {
  std::span<char> s = row.joltage;
  auto first_candidates = s.subspan(0, s.size() - 1);

  auto candidate =
      std::max_element(first_candidates.begin(), first_candidates.end());
  auto last = std::max_element(candidate + 1, s.end());

  return (10 * *candidate) + *last;
}

int day3::largest12DigitJolt(day3::JoltageRow row) { return 0; }
