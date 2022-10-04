#include <gtest/gtest.h>
#include <gmock/gmock.h>

template <typename Input, typename Predicate>
int plain_count_if(Input begin, Input end, Predicate p)
{
    int total = 0;
    for (Input i = begin; i < end; i++)
    {
        if (p(*i))
            total++;
    }
    return total;
}

TEST(count_if_test, plain_count_if_test)
{
    int arr[]{1, 1, 2, 3, 5, 8, 11};
    int odds = plain_count_if(
        std::begin(arr), std::end(arr),
        [](int const n)
        { return n % 2 == 1; });
    ASSERT_EQ(5, odds);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}