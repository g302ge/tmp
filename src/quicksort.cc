#include <gtest/gtest.h>
#include <gmock/gmock.h>

template <typename T>
void swap(T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// TODO: still the problem about extract the operator <
template <typename T>
int partition(T array[], int const low, int const high)
{
    T pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

template <typename T>
void quicksort(T array[], int const low, int const high)
{
    if (low < high)
    {
        int const pivot = partition(array, low, high);
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

TEST(quicksort, quicksort_test)
{
    int array[] = {3, 4, 6, 1, 2, 5, 7};
    quicksort(array, 0, 6);
    ASSERT_THAT(array, ::testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}