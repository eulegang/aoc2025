#ifndef _DAY3_MODEL_H
#define _DAY3_MODEL_H

#include <initializer_list>
#include <ostream>
#include <parboil.h>
#include <vector>

namespace day3 {

struct JoltageRow {
  std::vector<char> joltage;

  JoltageRow(std::vector<char>);
  JoltageRow(std::initializer_list<int>);
  bool operator==(const JoltageRow &row) const;
};

struct row_parser {
  using Value = JoltageRow;

  static parboil::result<Value> parse(parboil::buffer &buf) {
    if (!buf) {
      return std::unexpected(buf.make_error(parboil::code_t::oom));
    }

    std::vector<char> buffer;

    while (buf && '0' <= *buf && *buf <= '9') {
      buffer.push_back(*buf - '0');
      buf++;
    }

    if (buf && *buf == '\n') {
      buf++;
    }

    return JoltageRow(buffer);
  }
};

std::ostream &operator<<(std::ostream &, const JoltageRow &);

using parser = parboil::repeat<row_parser>;

int largestTwoDigitJolt(const JoltageRow row);
int largest12DigitJolt(const JoltageRow row);

} // namespace day3

#endif
