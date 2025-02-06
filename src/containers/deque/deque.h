#ifndef S21_DEQUE_H
#define S21_DEQUE_H
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
struct Node {
  T data;
  Node *prev;
  Node *next;
  Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class deque {
 private:
  Node<T> *head;
  Node<T> *tail;
  size_t sizze;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  //конструкторы
  deque();
  deque(std::initializer_list<value_type> const &items);
  deque(const deque &q);
  deque(deque &&q);
  ~deque();

  //операторы
  deque &operator=(deque &&q);
  bool operator!=(const deque &q);

  //методы
  void clear();
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(deque &other);

  void print_deque();
  const_reference front();
  const_reference back();

  bool empty();
  size_type size();
};
}  // namespace s21
#include "deque.cc"
#endif
