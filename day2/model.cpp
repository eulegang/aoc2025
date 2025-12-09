#include "model.h"
#include "input.h"
#include <cstdio>

using namespace std;

Range::Range(string_view buf) {
  start = 0;
  end = 0;

  auto state = &start;
  for (auto ch : buf) {
    if ('0' <= ch && ch <= '9') {
      *state *= 10;
      *state += ch - '0';
    } else if (ch == '-') {
      if (state == &end) {
        throw bad_input();
      }

      state = &end;
    } else {
      throw bad_input();
    }
  }
}

Range::Range(long start, long end) : start{start}, end{end} {}

bool Range::operator==(const Range &other) const {

  return this->start == other.start && this->end == other.end;
}

bool is_invalid(string_view buf) {
  if ((buf.size() & 1) != 0) {
    return false;
  }

  const auto front = buf.substr(0, buf.size() / 2);
  const auto back = buf.substr(buf.size() / 2);

  return front == back;
}

long Range::invalid_id_sum() const {
  long sum = 0;

  char buf[32];

  for (int i = start; i <= end; i++) {
    int len = snprintf(buf, sizeof(buf), "%d", i);
    string_view cur(buf, len);

    if (is_invalid(cur)) {
      sum += i;
    }
  }

  return sum;
}

std::ostream &operator<<(std::ostream &out, Range &range) {
  return out << "[" << range.start << ", " << range.end << "]";
}
