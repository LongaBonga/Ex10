// Copyright 2021 Longa_Bonga
#include "postfix.h"
#include <gtest/gtest.h>
#include <string>

TEST(PostfixTest, test1_1) {
  EXPECT_EQ("42.42 42 +", infix2prefix("42.42 + 42"));
}

TEST(PostfixTest, test1_2) {
  EXPECT_EQ("2 6.0 3 * 4 2 - / +", infix2prefix("2 + 6.0 * 3 / (4 - 2)"));
}

TEST(PostfixTest, test1_3) {
  MyStack<int> Mystack(1);
  Mystack.push(42);
  Mystack.pop();

  EXPECT_EQ("5.9 8 * 2 9 + * 7 5 - 8 + 9 5 5 * * - 5 + +", infix2prefix("5.9 * 8 * (2 + 9) + (7 - 5 + 8 - 9 * (5 * 5) + 5)"));
}
