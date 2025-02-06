#include <stack>

#include "test.h"

TEST(EQTest_stack, EQTest_stack_equal__1) {
  s21::stack<int> my;
  std::stack<int> original;
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_stack, EQTest_stack_equal__2) {
  s21::stack<double> my;
  std::stack<double> original;
  my.push(2.0056);
  original.push(2.0056);
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_stack, EQTest_stack_equal__3) {
  s21::stack<char> my;
  std::stack<char> original;
  my.push('y');
  original.push('y');
  ASSERT_EQ(my.size(), original.size());
}

TEST(EQTest_stack, EQTest_stack_equal__4) {
  s21::stack<int> my{6, 8, 0, 9, 99};
  std::stack<int> original;
  original.push(6);
  original.push(8);
  original.push(0);
  original.push(9);
  original.push(99);

  ASSERT_EQ(my.size(), original.size());
  ASSERT_EQ(my.top(), original.top());
}

TEST(EQTest_stack, EQTest_stack_equal__5) {
  s21::stack<char> my1{'h', 'i'};

  s21::stack<char> my3(std::move(my1));

  std::stack<char> original1;
  original1.push('h');
  original1.push('i');

  ASSERT_EQ(my3.size(), original1.size());
}
TEST(EQTest_stack, EQTest_stack_equal__7) {
  s21::stack<int> my{7, 8, 9, 11};
  std::stack<int> original;
  original.push(7);
  original.push(8);
  original.push(9);
  original.push(11);
  ASSERT_EQ(my.top(), original.top());
}

TEST(EQTest_stack, EQTest_stack_equal__8) {
  s21::stack<int> my{7, 8, 9, 11};
  ASSERT_EQ(false, my.empty());
}
TEST(EQTest_stack, EQTest_stack_equal__9) {
  s21::stack<int> my;
  ASSERT_EQ(true, my.empty());
}

TEST(EQTest_stack, EQTest_stack_equal__10) {
  s21::stack<int> my{0, 0, 0, 0, 0, 0, 0};

  ASSERT_EQ(7, my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__11) {
  s21::stack<int> my;
  ASSERT_EQ(0, my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__12) {
  s21::stack<double> my;
  my.push(1.2);

  ASSERT_EQ(1, my.size());
  ASSERT_EQ(1.2, my.top());
}

TEST(EQTest_stack, EQTest_stack_equal__13) {
  s21::stack<double> my;
  my.push(1.2);
  my.push(0.2);
  my.pop();
  ASSERT_EQ(1.2, my.top());
  ASSERT_EQ(1, my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__14) {
  s21::stack<double> my;
  my.push(1.2);
  my.pop();
  ASSERT_EQ(0, my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__15) {
  s21::stack<int> my{1, 2, 3, 4, 5};
  s21::stack<int> my1{0, 0, 0, 0, 0};
  my.swap(my1);
  std::stack<int> original;
  original.push(0);
  original.push(0);
  original.push(0);
  original.push(0);
  original.push(0);
  original.push(0);

  int code = 0;
  if (original.top() == 0 && my.top() == 0) code = 1;
  ASSERT_EQ(5, my.size());
  ASSERT_EQ(1, code);
}

TEST(EQTest_stack, EQTest_stack_equal__16) {
  s21::stack<double> my;

  my.push(1.2);
  my.push(0.2);
  my.clear();

  std::stack<int> original;
  ASSERT_EQ(original.size(), my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__17) {
  s21::stack<double> my;
  std::stack<int> original;
  ASSERT_EQ(original.size(), my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__18) {
  s21::stack<char> my{'c', 'a', 't'};
  s21::stack<char> my1(my);
  std::stack<int> original;
  original.push('c');
  original.push('a');
  original.push('t');
  ASSERT_EQ(original.size(), my.size());
}

TEST(EQTest_stack, EQTest_stack_equal__19) {
  s21::stack<char> my;
  std::stack<int> original;

  ASSERT_EQ(original.size(), my.size());
  EXPECT_THROW(my.top(), std::invalid_argument);
}

TEST(EQTest_stack, EQTest_stack_equal__20) {
  s21::stack<char> my{'c', 'a'};
  s21::stack<char> my1;
  my1 = std::move(my);
  std::stack<int> original;
  original.push('c');
  original.push('a');
  ASSERT_EQ(original.top(), my1.top());
  ASSERT_EQ(original.size(), my1.size());
}

TEST(EQTest_stack, EQTest_stack_equal__21) {
  s21::stack<char> my;
  my.insert_many_front('c', 'a');
  std::stack<char> original;
  original.push('c');
  original.push('a');
  ASSERT_EQ(original.top(), my.top());
  ASSERT_EQ(original.size(), my.size());
}