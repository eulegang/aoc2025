#include <iostream>

#include "chroma.h"
#include "input.h"
#include "model.h"

using namespace std;

int main() {
  string input = read_file("day2/input.txt");
  chomp(input);

  auto ranges = splitT<Range>(input, ",");
  long sum = 0;
  for (auto &range : ranges) {
    cout << chroma::cyan << "current range: " << chroma::purple << range
         << chroma::cyan << " - " << chroma::yellow << range.end - range.start
         << chroma::clear << endl;
    sum += range.invalid_id_sum();
  }

  cout << "sum of invalid ids: " << chroma::green << sum << chroma::clear
       << endl;
}
