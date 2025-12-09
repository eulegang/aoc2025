
#include "invalid.h"

int digits(long value) {
  int d = 0;
  while (value) {
    d++;
    value /= 10;
  }

  return d;
}

long expand(int i) {
  long value = 1;

  while (--i > 0) {
    value *= 10;
  }

  return value;
}

void visit_invalids(long a, long b, void (&invalid_handler)(long)) {
  int a_digits = digits(a);
  int b_digits = digits(b);
}
