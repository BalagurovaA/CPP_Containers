#include <array>

#include "test.h"

TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> arr;
  EXPECT_EQ(arr.size(), 5);
}

TEST(TestArray, InitializerArrayConstructor) {
  s21::array<unsigned, 5> arr1({1, 2, 3, 4, 5});
  EXPECT_EQ(5, arr1.size());

  auto iter = arr1.begin();
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(i + 1, *iter);
    ++iter;
  }
}

TEST(TestArray, CopyConstructor) {
  s21::array<int, 5> origin({5, 4, 3, 2, 1});
  s21::array<int, 5> cp(origin);

  EXPECT_EQ(origin.size(), cp.size());

  auto origin_iter = origin.begin();
  auto copy_iter = cp.begin();
  EXPECT_NE(origin_iter, copy_iter);
  for (; origin_iter != origin.end(); ++origin_iter, ++copy_iter) {
    EXPECT_EQ(*origin_iter, *copy_iter);
  }

  for (auto iter = cp.begin(); iter != cp.end(); ++iter) {
    *iter = 6;
  }

  for (auto iter = cp.begin(); iter != cp.end(); ++iter) {
    EXPECT_EQ(*iter, 6);
  }

  origin_iter = std::move(origin.begin());
  for (size_t i = 5; i > 0; --i, ++origin_iter) {
    EXPECT_EQ(i, *origin_iter);
  }
}

TEST(TestArray, ArrayEmpty) {
  s21::array<int, 0> emptyArray;
  s21::array<int, 5> nonEmptyArray = {1, 2, 3, 4, 5};
  EXPECT_TRUE(emptyArray.empty());
  EXPECT_FALSE(nonEmptyArray.empty());
}

TEST(TestArray, Array_At) {
  try {
    s21::array<int, 5> myArray = {1, 2, 3, 4, 5};
    int value = myArray.at(2);
    EXPECT_EQ(value, 3);
  } catch (const std::out_of_range& e) {
    EXPECT_EQ(e.what(), "array::at: __n (which is 63) >= _Nm (which is 5)");
  }
}

TEST(TestArray, ArraySwap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {10, 20, 30, 40, 50};

  s21::array<int, 5> arr1_copy = arr1;
  s21::array<int, 5> arr2_copy = arr2;

  arr1.swap(arr2);

  for (size_t i = 0; i < 5; i++) {
    EXPECT_EQ(arr1[i], arr2_copy[i]);
    EXPECT_EQ(arr2[i], arr1_copy[i]);
  }
}

TEST(TestArray, ArrayFill) {
  s21::array<int, 5> arr;

  int fillValue = 42;
  arr.fill(fillValue);

  for (size_t i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], fillValue);
  }
}

TEST(ArrayTest, FrontMethod) {
  s21::array<int, 4> arr({10, 20, 30, 40});
  EXPECT_EQ(arr.front(), 10);

  s21::array<std::string, 3> strArr({"apple", "banana", "cherry"});
  EXPECT_EQ(strArr.front(), "apple");
}

TEST(ArrayTest, BackMethod) {
  s21::array<int, 4> arr({10, 20, 30, 40});
  EXPECT_EQ(arr.back(), 40);

  s21::array<std::string, 3> strArr({"apple", "banana", "cherry"});
  EXPECT_EQ(strArr.back(), "cherry");
}

TEST(ArrayTest, DataMethod) {
  s21::array<int, 3> arr({1, 2, 3});
  s21::array<int, 3>::iterator it = arr.data();

  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(*it, arr[i]);
    ++it;
  }
}

TEST(ArrayTest, MaxSizeMethod) {
  s21::array<int, 5> arr;
  std::array<int, 5> arr2;
  EXPECT_EQ(arr.max_size(), arr2.max_size());
}

TEST(ArrayTest, MoveConstructorCallsCopyConstructor) {
  s21::array<int, 3> arr1({1, 2, 3});

  s21::array<int, 3> arr2(std::move(arr1));

  EXPECT_EQ(arr2[0], 1);
  EXPECT_EQ(arr2[1], 2);
  EXPECT_EQ(arr2[2], 3);
}
