#include "model.h"
#include "input.h"
#include <chroma.h>
#include <cmath>
#include <cstdio>
#include <iostream>

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

struct St {
  long value;
  long digits;

  St(long value) {
    const unsigned digits = ceil(log10(value));
    this->digits = ceil(log10(value) / 2);
    this->value = value / pow(10, this->digits);
  }

  long get() const { return value * pow(10, digits) + value; }
  void next() {
    value++;

    if (log10(value) >= digits) {
      digits++;
      value = pow(10, digits - 1);
    }
  }
};

ostream &operator<<(ostream &os, const St &st) {
  return os << st.value << "%" << st.digits;
}

long Range::invalid_id_sum() const {
  long sum = 0;

  St st(start);

  long cur = st.get();
  while (cur <= end) {
    const bool even_digits = ((long)ceil(log10(cur)) & 1) == 0;

    if ((start <= cur && cur <= end) && even_digits) {
      sum += cur;
    }

    st.next();
    cur = st.get();
  }

  return sum;
}

std::ostream &operator<<(std::ostream &out, Range &range) {
  return out << "[" << range.start << ", " << range.end << "]";
}

struct St2 {
  long value;
  long digits;

  St2(long value) {
    const unsigned digits = ceil(log10(value));
    this->digits = ceil(log10(value) / 2);
    this->value = value / pow(10, this->digits);
  }

  long get() const { return value * pow(10, digits) + value; }
  void next() {
    value++;

    if (log10(value) >= digits) {
      digits++;
      value = pow(10, digits - 1);
    }
  }
};

long Range::invalid_id_sum2() const {
  long sum = 0;

  St2 st(start);

  long cur = st.get();
  while (cur <= end) {
    // const bool even_digits = ((long)ceil(log10(cur)) & 1) == 0;

    if ((start <= cur && cur <= end)) {
      sum += cur;
    }

    st.next();
    cur = st.get();
  }

  return sum;
}
