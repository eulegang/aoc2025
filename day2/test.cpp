#include "input.h"
#include "model.h"
#include "gtest/gtest.h"
#include <chroma.h>

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

#define ANNOUNCE(t)                                                            \
  std::cout << chroma::green << #t << chroma::clear << std::endl;              \
  t

TEST(Day2, ExampleSubCounts) {
  ANNOUNCE(EXPECT_EQ(Range(11, 22).invalid_id_sum(), 33));
  ANNOUNCE(EXPECT_EQ(Range(95, 115).invalid_id_sum(), 99));
  ANNOUNCE(EXPECT_EQ(Range(998, 1012).invalid_id_sum(), 1010));
  ANNOUNCE(
      EXPECT_EQ(Range(1188511880, 1188511890).invalid_id_sum(), 1188511885));
  ANNOUNCE(EXPECT_EQ(Range(222220, 222224).invalid_id_sum(), 222222));
  ANNOUNCE(EXPECT_EQ(Range(1698522, 1698528).invalid_id_sum(), 0));
  ANNOUNCE(EXPECT_EQ(Range(446443, 446449).invalid_id_sum(), 446446));
  ANNOUNCE(EXPECT_EQ(Range(38593856, 38593862).invalid_id_sum(), 38593859));
  ANNOUNCE(EXPECT_EQ(Range(565653, 565659).invalid_id_sum(), 0));
  ANNOUNCE(EXPECT_EQ(Range(824824821, 824824827).invalid_id_sum(), 0));
  ANNOUNCE(EXPECT_EQ(Range(2121212118, 2121212124).invalid_id_sum(), 0));
}

TEST(Day2, ExampleCounts) {
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

TEST(Day2, PARTS) {
  // ANNOUNCE(EXPECT_EQ(Range(975119, 1004307).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(35171358, 35313940).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(6258659887, 6258804661).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(737649, 837633).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(85745820, 85956280).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(9627354, 9679470).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(2327309144, 2327509647).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(301168, 351545).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(537261, 631588).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(364281214, 364453549).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(9563727253, 9563879587).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(3680, 9127).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(388369417, 388406569).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(6677501, 6752949).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(650804, 678722).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(3314531, 3365076).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(1052, 2547).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(24134, 68316).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(8888820274, 8888998305).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(82614, 107458).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(456819, 529037).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(358216, 389777).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(24222539, 24266446).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(874565, 916752).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(3886244, 3960191).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(25, 110).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(9696951376, 9696996784).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(171, 671).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(5656545867, 5656605587).invalid_id_sum(), 0));
  // ANNOUNCE(EXPECT_EQ(Range(75795017, 75865731).invalid_id_sum(), 0));
  ANNOUNCE(EXPECT_EQ(Range(1, 16).invalid_id_sum(), 11));
  // ANNOUNCE(EXPECT_EQ(Range(181025, 232078).invalid_id_sum(), 0));
}
