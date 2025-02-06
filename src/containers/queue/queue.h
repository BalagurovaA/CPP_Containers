#ifndef S21_QUEUE_H
#define S21_QUEUE_H
#include <initializer_list>
#include <iostream>

#include "../deque/deque.h"

namespace s21 {
template <typename T, typename Container = s21::deque<T>>
class queue {
 private:
  Container example;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue &operator=(queue &&q);

  //методы
  const_reference front();
  const_reference back();
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(queue &other);
  void print_queue();

  template <typename... Args>
  void insert_many_back(Args &&...args);
};
}  // namespace s21
#include "queue.cc"
#endif
