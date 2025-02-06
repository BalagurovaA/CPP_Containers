#ifndef S21_VECTOR_H
#define S21_VECTOR_H
#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class vector {
 private:
  T *p_vector;
  size_t size_;
  size_t capacity_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  explicit vector();
  explicit vector(size_t n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  iterator begin();
  iterator end();
  const_iterator cbegin();

  bool empty();
  size_type size();
  size_type max_size();
  size_type capacity();
  void reserve(size_type size);
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
};
}  // namespace s21
#include "vector.cc"
#endif