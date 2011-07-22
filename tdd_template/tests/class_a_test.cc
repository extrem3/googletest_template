#include "gtest/gtest.h"
#include "class_a.h"

TEST(ClassA, DoesItReturnOne)
{
  ClassA class_a;
  EXPECT_EQ(1, class_a.ReturnOne());
}
