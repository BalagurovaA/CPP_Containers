#ifndef S21_STACK_H
#define S21_STACK_H
#include <initializer_list>
#include <iostream>

#include "../deque/deque.h"

namespace s21 {
template <typename T, typename Container = s21::deque<T>>
class stack {
 private:
  Container example;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack &operator=(stack &&s);

  void push(const_reference value);
  void print_stack();
  const_reference top();

  bool empty();
  size_type size();
  void pop();
  void swap(stack &other);

  void clear();

  template <typename... Args>
  void insert_many_front(Args &&...args);
};
}  // namespace s21
#include "stack.cc"
#endif