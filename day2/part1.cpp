#include <iostream>

#include "input.h"
#include "model.h"

using namespace std;

int main() {
  string input = read_file("day2/input.txt");
  chomp(input);

  auto ranges = splitT<Range>(input, ",");
  int sum = 0;
  for (auto range : ranges) {
    sum += range.invalid_id_sum();
  }

  cout << "sum of invalid ids: " << sum << endl;
}
