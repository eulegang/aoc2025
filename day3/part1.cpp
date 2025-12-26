
#include "input.h"
#include "model.h"
#include <format>
#include <numeric>

int main() {
  const auto input = read_file("day3/input.txt");

  const auto rows = parboil::parse<day3::parser>(input);

  int ans =
      std::accumulate(rows.begin(), rows.end(), 0, [](int acc, auto &row) {
        return acc + day3::largestTwoDigitJolt(row);
      });

  std::cout << std::format("joltages: {}", ans) << std::endl;
  return 0;
}
