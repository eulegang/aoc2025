#include "input.h"
#include "invalid.h"
#include "model.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Day2, ExampleParse) {
  const string input =
      "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,"
      "1698522-1698528,446443-446449,38593856-38593862,565653-565659,"
      "824824821-824824827,2121212118-2121212124";

  vector parts = splitT<Range>(input, ",");

  vector expected = {
      Range(11, 22),
      Range(95, 115),
      Range(998, 1012),
      Range(1188511880, 1188511890),
      Range(222220, 222224),
      Range(1698522, 1698528),
      Range(446443, 446449),
      Range(38593856, 38593862),
      Range(565653, 565659),
      Range(824824821, 824824827),
      Range(2121212118, 2121212124),
  };

  ASSERT_EQ(parts, expected);
}

TEST(Day2, ExampleSubCounts) {
  EXPECT_EQ(Range(11, 22).invalid_id_sum(), 33);
  EXPECT_EQ(Range(95, 115).invalid_id_sum(), 99);
  EXPECT_EQ(Range(998, 1012).invalid_id_sum(), 1010);
  EXPECT_EQ(Range(1188511880, 1188511890).invalid_id_sum(), 1188511885);
  EXPECT_EQ(Range(222220, 222224).invalid_id_sum(), 222222);
  EXPECT_EQ(Range(1698522, 1698528).invalid_id_sum(), 0);
  EXPECT_EQ(Range(446443, 446449).invalid_id_sum(), 446446);
  EXPECT_EQ(Range(38593856, 38593862).invalid_id_sum(), 38593859);
  EXPECT_EQ(Range(565653, 565659).invalid_id_sum(), 0);
  EXPECT_EQ(Range(824824821, 824824827).invalid_id_sum(), 0);
  EXPECT_EQ(Range(2121212118, 2121212124).invalid_id_sum(), 0);
}

TEST(Day2, ExampleCounts) {
  GTEST_SKIP();

  const string input =
      "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,"
      "1698522-1698528,446443-446449,38593856-38593862,565653-565659,"
      "824824821-824824827,2121212118-2121212124";

  vector ranges = splitT<Range>(input, ",");

  int sum = 0;
  for (auto range : ranges) {
    sum += range.invalid_id_sum();
  }

  EXPECT_EQ(sum, 1227775554);
}

TEST(Day2Invalid, digits) {
  EXPECT_EQ(digits(0), 0);
  EXPECT_EQ(digits(9), 1);
  EXPECT_EQ(digits(10), 2);
  EXPECT_EQ(digits(99), 2);
  EXPECT_EQ(digits(100), 3);
  EXPECT_EQ(digits(999), 3);
  EXPECT_EQ(digits(1000), 4);
}

TEST(Day2Invalid, expand) {
  EXPECT_EQ(expand(0), 1);
  EXPECT_EQ(expand(1), 1);
  EXPECT_EQ(expand(2), 10);
  EXPECT_EQ(expand(3), 100);
  EXPECT_EQ(expand(4), 1000);
  EXPECT_EQ(expand(5), 10000);
}
