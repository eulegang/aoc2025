#include <iostream>
#include <thread>

#include "input.h"
#include "model.h"

using namespace std;

void do_work(vector<Range> ranges, atomic<long> *result) {
  long sum = 0;
  for (auto range : ranges) {
    cout << "current range: " << range << " - " << range.end - range.start
         << endl;
    sum += range.invalid_id_sum();
  }

  cout << "subsum of invalid ids: " << sum << endl;
  *result += sum;
}

int main() {
  string input = read_file("day2/input.txt");
  chomp(input);

  auto ranges = splitT<Range>(input, ",");

  vector<Range> inputs[4];
  int i = 0;
  for (auto range : ranges) {
    inputs[i++].push_back(range);
    i %= 4;
  }

  vector<std::thread> threads;
  atomic<long> result;
  i = 0;

  for (auto input : inputs) {
    threads.push_back(std::thread(do_work, inputs[i++], &result));
  }

  for (auto &thread : threads) {
    thread.join();
  }

  cout << "sum of invalid ids: " << result << endl;
}
