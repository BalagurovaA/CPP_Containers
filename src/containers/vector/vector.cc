#ifndef S21_VECTOR_TPP
#define S21_VECTOR_TPP
#include "vector.h"
using namespace std;

namespace s21 {

//         Vector Member functions          //

template <typename T>
vector<T>::vector() : p_vector(nullptr), size_(0), capacity_(0){};

template <typename T>
vector<T>::vector(size_t n) : p_vector(new T[n]{}), size_(n), capacity_(n){};

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : p_vector(new T[items.size()]{}),
      size_(items.size()),
      capacity_(items.size()) {
  int i = 0;
  for (const auto &elem : items) {
    p_vector[i] = elem;
    i++;
  }
}

template <typename T>
vector<T>::vector(const vector &v)
    : p_vector(new T[v.capacity_]), size_(v.size_), capacity_(v.capacity_) {
  for (size_t i = 0; i < size_; i++) {
    p_vector[i] = v.p_vector[i];
  }
}

template <typename T>
vector<T>::vector(vector &&v)
    : p_vector(v.p_vector), size_(v.size_), capacity_(v.capacity_) {
  v.size_ = 0;
  v.capacity_ = 0;
  v.p_vector = nullptr;
}

template <typename T>
vector<T>::~vector() {
  delete[] p_vector;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
typename vector<T>::vector &vector<T>::operator=(vector &&v) {
  if (this->p_vector != nullptr) {
    this->size_ = 0;
    this->capacity_ = 0;
    delete[](this->p_vector);
  }
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->p_vector = v.p_vector;

  v.size_ = 0;
  v.capacity_ = 0;
  v.p_vector = nullptr;
  return *this;
}

//             Vector Iterators              //
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return p_vector;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return p_vector + size_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() {
  return const_iterator(p_vector);
}

//           Vector Element access          //
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("index out of range");
  }
  return *(p_vector + pos);
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("index out of range");
  }
  return *(p_vector + pos);
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return *p_vector;
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return *(p_vector + size_ - 1);
}

template <typename T>
T *vector<T>::data() {
  return p_vector;
}

//             Vector Capacity              //

template <typename T>
bool vector<T>::empty() {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() /
         sizeof(typename vector<T>::value_type);
}

template <typename T>
void vector<T>::reserve(typename vector<T>::size_type size) {
  if (size > this->max_size()) {
    throw std::length_error("length_error");
  }
  if (size > this->capacity_) {
    vector<T> temp;
    temp.capacity_ = size;
    temp.size_ = this->size_;
    temp.p_vector = new T[size]{};
    for (size_t i = 0; i < temp.size_; i++) {
      temp.p_vector[i] = this->p_vector[i];
    }
    this->capacity_ = size;
    *this = std::move(temp);
  }
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    vector<T> temp;
    temp.capacity_ = this->size_;
    temp.size_ = this->size_;
    temp.p_vector = new T[this->size_]{};
    for (size_t i = 0; i < temp.size_; i++) {
      temp.p_vector[i] = this->p_vector[i];
    }
    *this = std::move(temp);
  }
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

//            Vector Modifiers             //

template <typename T>
void vector<T>::clear() {
  if (p_vector != nullptr) {
    size_ = 0;
  }
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(
    typename vector<T>::iterator pos,
    typename vector<T>::const_reference value) {
  if (pos < this->begin() || pos > this->end()) {
    throw std::out_of_range("Iterator out of range");
  }
  vector<T> temp(this->size_ + 1);
  vector<T>::iterator p = this->begin();
  vector<T>::iterator p1 = temp.begin();
  for (; p < pos; p++, p1++) {
    *p1 = *p;
  }
  *(p1++) = value;
  vector<T>::iterator insert_pos = p1;
  for (; p < this->end(); p++, p1++) {
    *p1 = *p;
  }
  *this = std::move(temp);
  return insert_pos;
}

template <typename T>
void vector<T>::erase(typename vector<T>::iterator pos) {
  if (pos < this->begin() || pos >= this->end()) {
    throw std::out_of_range("Iterator out of range");
  }
  vector<T> temp(this->size_ - 1);
  vector<T>::iterator p = this->begin();
  vector<T>::iterator p1 = temp.begin();
  for (; p < pos; p++, p1++) {
    *p1 = *p;
  }
  p++;
  for (; p < this->end(); p++, p1++) {
    *p1 = *p;
  }
  *this = std::move(temp);
}

template <typename T>
void vector<T>::push_back(typename vector<T>::const_reference value) {
  if (size_ < capacity_) {
    size_++;
    p_vector[size_] = value;
  } else {
    vector<T> temp(this->size_ + 1);
    for (size_t i = 0; i < this->size_; i++) {
      temp.p_vector[i] = this->p_vector[i];
    }
    temp.p_vector[this->size_] = value;
    *this = std::move(temp);
  }
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ != 0) {
    size_--;
  }
}

template <typename T>
void vector<T>::swap(vector &other) {
  vector<T> temp(this->size_);
  for (size_t i = 0; i < this->size_; i++) {
    temp.p_vector[i] = this->p_vector[i];
  }
  *this = std::move(other);
  other = std::move(temp);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  iterator it = begin() + (pos - cbegin());
  vector<value_type> temp{args...};
  for (size_t i = 0; i < temp.size(); i++) {
    it = insert(it, temp[i]);
  }
  return it;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}
}  // namespace s21

#endif