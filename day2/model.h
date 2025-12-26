#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string_view>

struct Range {
  long start;
  long end;

  Range(long, long);
  Range(std::string_view buf);

  bool operator==(const Range &other) const;

  long invalid_id_sum() const;
  long invalid_id_sum2() const;
};

std::ostream &operator<<(std::ostream &, Range &);

#endif
