#include "gtest/gtest.h"
#include "../AnyType.cpp"

TEST(SwapTest, BoolSwapTest)
{
    AnyType anyType = 2.2;
    ASSERT_EQ(2.2,anyType.ToDouble());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}