#ifndef S21_ARRAY_TPP
#define S21_ARRAY_TPP
#include "array.h"
using namespace std;

namespace s21 {
template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : size_(N) {
  int i = 0;
  for (const auto &item : items) {
    array_[i] = item;
    i++;
  }
}

template <typename T, std::size_t N>
array<T, N>::array(const array &a) : size_(a.size_) {
  for (size_t i = 0; i < size_; i++) {
    this->array_[i] = a.array_[i];
  }
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) : array(a) {}

template <typename T, std::size_t N>
array<T, N>::~array() {}

template <typename T, std::size_t N>
typename array<T, N>::array &array<T, N>::operator=(array<T, N> &&a) {
  if (this != &a) {
    for (size_t i = 0; i < size_; ++i) {
      array_[i] = a.array_[i];
    }
  }
  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out range");
  }
  return array_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return at(pos);
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return array_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return array_[size_ - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return array_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return &array_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return &array_[size_ - 1];
}

template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return size_ == 0;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return size();
}

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) {
  if (this != &other) {
    array<T, N> temp(*this);
    *this = std::move(other);
    other = std::move(temp);
  }
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < size_; i++) {
    array_[i] = value;
  }
}

template <typename T, std::size_t N>
void array<T, N>::PrintArray() {
  for (size_t i = 0; i < size_; i++) {
    cout << array_[i] << "  ";
  }
  cout << endl;
}
}  // namespace s21

#endif