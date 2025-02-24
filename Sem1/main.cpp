#include <gtest/gtest.h>
#include "sem1.hpp"

TEST(zeroLast, Basic_1) {
    vector<int> input{0, 0, 1, 0, 3, 12};
    vector<int> valid_output{1, 3, 12, 0, 0, 0};

    auto output = zeroLast(input);

    ASSERT_EQ(valid_output, output);
}