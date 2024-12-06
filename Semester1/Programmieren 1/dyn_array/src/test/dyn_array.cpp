#include <gtest/gtest.h>
#include "dyn_array.h"

class DynArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up before each test
    }

    void TearDown() override {
        // Clean up after each test
    }
};

TEST_F(DynArrayTest, CreateArray_ValidCapacity) {
    dyn_array* arr = create_array(10);
    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size(arr), 0);
    EXPECT_EQ(capacity(arr), 10);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_SUCCESS);
    destroy_array(arr);
}

TEST_F(DynArrayTest, CreateArray_ZeroCapacity) {
    dyn_array* arr = create_array(0);
    EXPECT_EQ(arr, nullptr);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_ERR_ALLOCATION);
}

TEST_F(DynArrayTest, Append_Success) {
    dyn_array* arr = create_array(2);
    ASSERT_NE(arr, nullptr);

    EXPECT_EQ(append(arr, 1), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(size(arr), 1);
    EXPECT_EQ(capacity(arr), 2);

    EXPECT_EQ(append(arr, 2), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(size(arr), 2);
    EXPECT_EQ(capacity(arr), 2);

    // Trigger reallocation
    EXPECT_EQ(append(arr, 3), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(size(arr), 3);
    EXPECT_EQ(capacity(arr), 4);

    destroy_array(arr);
}

TEST_F(DynArrayTest, Get_Success) {
    dyn_array* arr = create_array(2);
    ASSERT_NE(arr, nullptr);

    append(arr, 42);
    append(arr, 99);

    int value;
    EXPECT_EQ(get(arr, 0, &value), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(value, 42);

    EXPECT_EQ(get(arr, 1, &value), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(value, 99);

    destroy_array(arr);
}

TEST_F(DynArrayTest, Get_OutOfBounds) {
    dyn_array* arr = create_array(2);
    ASSERT_NE(arr, nullptr);

    append(arr, 42);

    int value;
    EXPECT_EQ(get(arr, 1, &value), DYN_ARRAY_ERR_OUT_OF_BOUNDS);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_ERR_OUT_OF_BOUNDS);

    destroy_array(arr);
}

TEST_F(DynArrayTest, Set_Success) {
    dyn_array* arr = create_array(2);
    ASSERT_NE(arr, nullptr);

    append(arr, 42);
    append(arr, 99);

    EXPECT_EQ(set(arr, 1, 77), DYN_ARRAY_SUCCESS);

    int value;
    get(arr, 1, &value);
    EXPECT_EQ(value, 77);

    destroy_array(arr);
}

TEST_F(DynArrayTest, Set_OutOfBounds) {
    dyn_array* arr = create_array(2);
    ASSERT_NE(arr, nullptr);

    append(arr, 42);

    EXPECT_EQ(set(arr, 1, 77), DYN_ARRAY_ERR_OUT_OF_BOUNDS);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_ERR_OUT_OF_BOUNDS);

    destroy_array(arr);
}

TEST_F(DynArrayTest, RemoveAt_Success) {
    dyn_array* arr = create_array(3);
    ASSERT_NE(arr, nullptr);

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);

    EXPECT_EQ(remove_at(arr, 1), DYN_ARRAY_SUCCESS);
    EXPECT_EQ(size(arr), 2);

    int value;
    get(arr, 1, &value);
    EXPECT_EQ(value, 30);

    destroy_array(arr);
}

TEST_F(DynArrayTest, RemoveAt_OutOfBounds) {
    dyn_array* arr = create_array(3);
    ASSERT_NE(arr, nullptr);

    append(arr, 10);

    EXPECT_EQ(remove_at(arr, 1), DYN_ARRAY_ERR_OUT_OF_BOUNDS);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_ERR_OUT_OF_BOUNDS);

    destroy_array(arr);
}

TEST_F(DynArrayTest, PrintArray) {
    dyn_array* arr = create_array(3);
    ASSERT_NE(arr, nullptr);

    append(arr, 5);
    append(arr, 10);
    append(arr, 15);

    EXPECT_EQ(print_array(arr), DYN_ARRAY_SUCCESS);

    destroy_array(arr);
}

TEST_F(DynArrayTest, DestroyArray_NullPointer) {
    destroy_array(nullptr);
    EXPECT_EQ(dyn_array_get_last_error(), DYN_ARRAY_SUCCESS);
}
