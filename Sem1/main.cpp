#include <gtest/gtest.h>
#include "sem1.hpp"

// Тесты для функций
// twoSum
TEST(twoSum, Basic_case_1) {
    vector<int> input_nums{2, 7, 11, 15};
    int input_target = 9;
    vector<int> valid_output{0, 1};

    auto output = twoSum(input_nums, input_target);

    ASSERT_EQ(valid_output, output);
}

TEST(twoSum, Basic_case_2) {
    vector<int> input_nums{2, 7, 11, 15};
    int input_target = 3;
    vector<int> valid_output{};

    auto output = twoSum(input_nums, input_target);

    ASSERT_EQ(valid_output, output);
}

TEST(twoSum, empty_case) {
    vector<int> input_nums{};
    int input_target = 3;
    vector<int> valid_output{};

    auto output = twoSum(input_nums, input_target);

    ASSERT_EQ(valid_output, output);
}

// reverseArray
TEST(reverseArray, Basic_case_1) {
    vector<int> input{1, 2, 3, 4, 5, 6};
    vector<int> valid_output{6, 5, 4, 3, 2, 1};

    auto output = reverseArray(input);

    ASSERT_EQ(valid_output, output);
}

TEST(reverseArray, empty_case) {
    vector<int> input{};
    vector<int> valid_output{};

    auto output = reverseArray(input);

    ASSERT_EQ(valid_output, output);
}

// rotateArray
TEST(rotateArray, Basic_case_1) {
    vector<int> input_arr{1, 2, 3, 4, 5, 6, 7};
    int input_k = 3;
    vector<int> valid_output{5, 6, 7, 1, 2, 3, 4};

    auto output = rotateArray(input_arr, input_k);

    ASSERT_EQ(valid_output, output);
}

TEST(rotateArray, k_more_than_n_case) {
    vector<int> input_arr{1, 2, 3, 4, 5, 6, 7};
    int input_k = 10;
    vector<int> valid_output{5, 6, 7, 1, 2, 3, 4};

    auto output = rotateArray(input_arr, input_k);

    ASSERT_EQ(valid_output, output);
}

TEST(rotateArray, empty_case) {
    vector<int> input_arr{};
    int input_k = 10;
    vector<int> valid_output{};

    auto output = rotateArray(input_arr, input_k);

    ASSERT_EQ(valid_output, output);
}

// merge_sorted_arrays
TEST(merge_sorted_arrays, Basic_case_1) {
    vector<int> input_1{1, 4, 5};
    vector<int> input_2{2, 4, 12};
    vector<int> valid_output{1, 2, 4, 4, 5, 12};

    auto output = merge_sorted_arrays(input_1, input_2);

    ASSERT_EQ(valid_output, output);
}

TEST(merge_sorted_arrays, empty_case) {
    vector<int> input_1{};
    vector<int> input_2{};
    vector<int> valid_output{};

    auto output = merge_sorted_arrays(input_1, input_2);

    ASSERT_EQ(valid_output, output);
}

// merge
TEST(merge, Basic_case_1) {
    vector<int> input_1{1, 4, 5, 0, 0, 0};
    vector<int> input_2{2, 4, 12};
    vector<int> valid_output{1, 2, 4, 4, 5, 12};

    auto output = merge(input_1, input_2);

    ASSERT_EQ(valid_output, output);
}

TEST(merge, empty_case) {
    vector<int> input_1{};
    vector<int> input_2{};
    vector<int> valid_output{};

    auto output = merge(input_1, input_2);

    ASSERT_EQ(valid_output, output);
}

// sort_binary_array
TEST(sort_binary_array, Basic_case_1) {
    vector<int> input{0, 0, 1, 0, 1, 1, 0, 0, 1};
    vector<int> valid_output{0, 0, 0, 0, 0, 1, 1, 1, 1};

    auto output = sort_binary_array(input);

    ASSERT_EQ(valid_output, output);
}

TEST(sort_binary_array, empty_case) {
    vector<int> input{};
    vector<int> valid_output{};

    auto output = sort_binary_array(input);

    ASSERT_EQ(valid_output, output);
}

// sortColors
TEST(sortColors, Basic_case_1) {
    vector<int> input{0, 0, 1, 0, 2, 1, 2, 0, 1};
    vector<int> valid_output{0, 0, 0, 0, 1, 1, 1, 2, 2};

    auto output = sortColors(input);

    ASSERT_EQ(valid_output, output);
}

TEST(sortColors, empty_case) {
    vector<int> input{};
    vector<int> valid_output{};

    auto output = sortColors(input);

    ASSERT_EQ(valid_output, output);
}

// evenFirst
TEST(evenFirst, Basic_case_1) {
    vector<int> input{3, 2, 4, 1, 11, 8, 9};
    vector<int> valid_output{2, 4, 8, 1, 11, 3, 9};

    auto output = evenFirst(input);

    ASSERT_EQ(valid_output, output);
}

TEST(evenFirst, empty_case) {
    vector<int> input{};
    vector<int> valid_output{};

    auto output = evenFirst(input);

    ASSERT_EQ(valid_output, output);
}

// zeroLast
TEST(zeroLast, Basic_case_1) {
    vector<int> input{0, 0, 1, 0, 3, 12};
    vector<int> valid_output{1, 3, 12, 0, 0, 0};

    auto output = zeroLast(input);

    ASSERT_EQ(valid_output, output);
}

TEST(zeroLast, empty_case) {
    vector<int> input{};
    vector<int> valid_output{};

    auto output = zeroLast(input);

    ASSERT_EQ(valid_output, output);
}