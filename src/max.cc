#include <gtest/gtest.h>

// plain max assume that the T has already implemented the operator <
// but if some T has not implemented the operator < will cause an UB
template <typename T>
T plain_max(T const a, T const b)
{
    return a > b ? a : b;
}

TEST(max_template, plain_max_test)
{
    ASSERT_EQ(double(3.12), plain_max<double>(3.0, 3.12));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
