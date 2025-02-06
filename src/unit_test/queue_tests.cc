#include <queue>

#include "test.h"

TEST(EQTest_queue, EQTest_queue_1) {
  s21::queue<int> my;
  std::queue<int> original;
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_queue, EQTest_queue_2) {
  s21::queue<double> my;
  std::queue<double> original;
  my.push(0.485);
  original.push(0.485);
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_queue, EQTest_queue_3) {
  s21::queue<int> my{1, 2, 3};
  std::queue<int> original;
  original.push(1);
  original.push(2);
  original.push(3);
  ASSERT_EQ(my.size(), original.size());
  ASSERT_EQ(my.front(), original.front());
  ASSERT_EQ(my.back(), original.back());
}

TEST(EQTest_queue, EQTest_queue_4) {
  s21::queue<char> my{'k', 'r', 'o', 'v'};
  std::queue<char> original;
  original.push('k');
  original.push('r');
  original.push('o');
  original.push('v');
  ASSERT_EQ(my.size(), original.size());
  ASSERT_EQ(my.front(), original.front());
  ASSERT_EQ(my.back(), original.back());
}

TEST(EQTest_queue, EQTest_queue_5) {
  s21::queue<char> my{'k', 'r', 'o', 'v'};
  s21::queue<char> my1(std::move(my));
  std::queue<char> original;
  original.push('k');
  original.push('r');
  original.push('o');
  original.push('v');
  ASSERT_EQ(my1.size(), original.size());
  ASSERT_EQ(my1.front(), original.front());
  ASSERT_EQ(my1.back(), original.back());
}
TEST(EQTest_queue, EQTest_queue_6) {
  s21::queue<int> my{122, 445, 323, 0};
  ASSERT_EQ(false, my.empty());
}
TEST(EQTest_queue, EQTest_queue_7) {
  s21::queue<int> my;
  ASSERT_EQ(true, my.empty());
}

TEST(EQTest_queue, EQTest_queue_8) {
  s21::queue<int> my{21, 0, 42};
  std::queue<char> original;
  original.push(21);
  original.push(0);
  original.push(42);
  ASSERT_EQ(my.front(), original.front());
}

TEST(EQTest_queue, EQTest_queue_9) {
  s21::queue<int> my;
  EXPECT_THROW(my.front(), std::invalid_argument);
}

TEST(EQTest_queue, EQTest_queue_10) {
  s21::queue<int> my{21, 0, 42};
  std::queue<char> original;
  original.push(21);
  original.push(0);
  original.push(42);
  ASSERT_EQ(my.back(), original.back());
}

TEST(EQTest_queue, EQTest_queue_11) {
  s21::queue<int> my;
  EXPECT_THROW(my.back(), std::invalid_argument);
}

TEST(EQTest_queue, EQTest_queue_12) {
  s21::queue<int> my;
  EXPECT_THROW(my.back(), std::invalid_argument);
}

TEST(EQTest_queue, EQTest_queue_13) {
  s21::queue<double> my;
  my.push(1.44);
  my.push(4.55);
  my.push(8.99);
  my.push(8.020);
  my.pop();
  std::queue<double> original;
  original.push(1.44);
  original.push(4.55);
  original.push(8.99);
  original.push(8.020);
  original.pop();

  ASSERT_EQ(my.size(), original.size());
  ASSERT_EQ(my.front(), original.front());
  ASSERT_EQ(my.back(), original.back());
}

TEST(EQTest_queue, EQTest_queue_14) {
  s21::queue<char> my{'v', 's', 'p', 'o'};
  s21::queue<char> my1{'a', 'a', 'a'};
  my.swap(my1);
  std::queue<char> original;
  original.push('a');
  original.push('a');
  original.push('a');

  ASSERT_EQ(my.size(), original.size());
  ASSERT_EQ(my.front(), original.front());
  ASSERT_EQ(my.back(), original.back());
}

TEST(EQTest_queue, EQTest_queue_15) {
  s21::queue<char> my;
  s21::queue<char> my1;
  my.swap(my1);
  std::queue<char> original;
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_queue, EQTest_queue_copy_16) {
  s21::queue<char> my{'c', 'a', 't'};
  s21::queue<char> my1(my);
  std::queue<int> original;
  original.push('c');
  original.push('a');
  original.push('t');
  ASSERT_EQ(original.size(), my.size());
}

TEST(EQTest_queue, EQTest_queue_equal_17) {
  s21::queue<char> my{'c', 'a'};
  s21::queue<char> my1;
  my1 = std::move(my);
  std::queue<int> original;
  original.push('c');
  original.push('a');
  ASSERT_EQ(original.front(), my1.front());
  ASSERT_EQ(original.back(), my1.back());
  ASSERT_EQ(original.size(), my1.size());
}

TEST(EQTest_queue, EQTest_queue_equal__18) {
  s21::queue<char> my;
  my.insert_many_back('c', 'a');
  std::queue<char> original;
  original.push('c');
  original.push('a');
  ASSERT_EQ(original.front(), my.front());
  ASSERT_EQ(original.back(), my.back());
  ASSERT_EQ(original.size(), my.size());
}
