#include "model.h"
#include "gtest/gtest.h"

using namespace d1;

TEST(Day1, Part1) {
  std::vector<d1::Turn> fixture{
      d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"), d1::Turn("L5"),
      d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),  d1::Turn("L99"),
      d1::Turn("R14"), d1::Turn("L82"),
  };

  auto actual = d1::on_zero(fixture);
  auto expected = 3;
  EXPECT_EQ(actual, expected);
}

TEST(Day1, Part2) {
  std::vector<d1::Turn> fixture{
      d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"), d1::Turn("L5"),
      d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),  d1::Turn("L99"),
      d1::Turn("R14"), d1::Turn("L82"),
  };

  auto actual = d1::past_zero(fixture);
  auto expected = 6;
  EXPECT_EQ(actual, expected);
}

TEST(Day1, Overflow) {
  {
    std::vector<d1::Turn> fixture{
        d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"),  d1::Turn("L5"),
        d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),   d1::Turn("L99"),
        d1::Turn("R14"), d1::Turn("L82"), d1::Turn("R100"),
    };

    auto actual = d1::past_zero(fixture);
    auto expected = 7;
    EXPECT_EQ(actual, expected) << "normal overflow";
  }

  {
    std::vector<d1::Turn> fixture{
        d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"),  d1::Turn("L5"),
        d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),   d1::Turn("L99"),
        d1::Turn("R14"), d1::Turn("L82"), d1::Turn("R168"),
    };

    auto actual = d1::past_zero(fixture);
    auto expected = 8;
    EXPECT_EQ(actual, expected);
  }
}

TEST(Day1, Underflow) {
  {
    std::vector<d1::Turn> fixture{
        d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"),  d1::Turn("L5"),
        d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),   d1::Turn("L99"),
        d1::Turn("R14"), d1::Turn("L82"), d1::Turn("L100"),
    };

    auto actual = d1::past_zero(fixture);
    auto expected = 7;
    EXPECT_EQ(actual, expected) << "normal underflow";
  }

  {
    std::vector<d1::Turn> fixture{
        d1::Turn("L68"), d1::Turn("L30"), d1::Turn("R48"),  d1::Turn("L5"),
        d1::Turn("R60"), d1::Turn("L55"), d1::Turn("L1"),   d1::Turn("L99"),
        d1::Turn("R14"), d1::Turn("L82"), d1::Turn("L132"),
    };

    auto actual = d1::past_zero(fixture);
    auto expected = 8;
    EXPECT_EQ(actual, expected) << "underflow on the dot";
  }
}
