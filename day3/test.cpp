#include "model.h"
#include "gtest/gtest.h"
#include <numeric>
#include <parboil.h>

TEST(Example, parse) {
  std::string buf = "987654321111111\n"
                    "811111111111119\n"
                    "234234234234278\n"
                    "818181911112111\n";

  const auto rows = parboil::parse<day3::parser>(buf);

  std::vector expected{day3::JoltageRow({
                           9,
                           8,
                           7,
                           6,
                           5,
                           4,
                           3,
                           2,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                       }),
                       day3::JoltageRow({
                           8,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           1,
                           9,
                       }),

                       day3::JoltageRow({
                           2,
                           3,
                           4,
                           2,
                           3,
                           4,
                           2,
                           3,
                           4,
                           2,
                           3,
                           4,
                           2,
                           7,
                           8,
                       }),

                       day3::JoltageRow({
                           8,
                           1,
                           8,
                           1,
                           8,
                           1,
                           9,
                           1,
                           1,
                           1,
                           1,
                           2,
                           1,
                           1,
                           1,
                       })

  };

  EXPECT_EQ(rows.size(), 4);
  EXPECT_EQ(rows, expected);
}

TEST(Example, answer) {
  std::string buf = "987654321111111\n"
                    "811111111111119\n"
                    "234234234234278\n"
                    "818181911112111\n";

  const auto rows = parboil::parse<day3::parser>(buf);

  int ans =
      std::accumulate(rows.begin(), rows.end(), 0, [](int acc, auto &row) {
        return acc + day3::largestTwoDigitJolt(row);
      });

  EXPECT_EQ(ans, 357);
}

TEST(Example, p2answer) {
  std::string buf = "987654321111111\n"
                    "811111111111119\n"
                    "234234234234278\n"
                    "818181911112111\n";

  const auto rows = parboil::parse<day3::parser>(buf);

  int ans =
      std::accumulate(rows.begin(), rows.end(), 0, [](int acc, auto &row) {
        return acc + day3::largest12DigitJolt(row);
      });

  EXPECT_EQ(ans, 3121910778619);
}
