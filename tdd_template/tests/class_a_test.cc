#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "class_a.h"

using ::testing::AtLeast;

class MockClassA : public ClassA
{
 public:
  MOCK_METHOD0(ReturnOne, int());
  MOCK_METHOD0(IsCalled, int());
};

TEST(ClassA, DoesItReturnOne)
{
  ClassA class_a;
  EXPECT_EQ(1, class_a.ReturnOne());
}

TEST(ClassA, DoesItCallTheFunction)
{
  MockClassA class_a;
  EXPECT_CALL(class_a, IsCalled())
      .Times(AtLeast(1));

  class_a.IsCalled();
}
