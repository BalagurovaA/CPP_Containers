#ifndef S21_QUEUE_CC
#define S21_QUEUE_CC
#include "queue.h"

namespace s21 {
//-------------конструктор создает пустую очередь-------------//
template <typename T, typename Container>
queue<T, Container>::queue() : example() {}

//-------------конструктор для фигурных скобок-------------//
template <typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i < items.end(); i++) {
    push(*i);
  }
}

//-------------copy constructor-------------//
template <typename T, typename Container>
queue<T, Container>::queue(const queue &q) : example(q.example) {}

//-------------move constructor-------------//
template <typename T, typename Container>
queue<T, Container>::queue(queue &&q) : example(std::move(q.example)) {}

//-------------destructor-------------//
template <typename T, typename Container>
queue<T, Container>::~queue() {
  example.~deque();
}

//-------------опреатор =-------------//
template <typename T, typename Container>
queue<T, Container> &queue<T, Container>::operator=(queue &&q) {
  this->example = std::move(q.example);
  return *this;
}

//-------------front-------------//
template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::front() {
  if (example.empty() == true) throw std ::invalid_argument("-error-");
  return example.front();
}
//-------------back-------------//
template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::back() {
  if (example.empty() == true) throw std ::invalid_argument("-error-");
  return example.back();
}

//-------------empty-------------//
template <typename T, typename Container>
bool queue<T, Container>::empty() {
  return example.empty();
}

//-------------size-------------//
template <typename T, typename Container>
typename queue<T, Container>::size_type queue<T, Container>::size() {
  return example.size();
}

//-------------push-------------//
template <typename T, typename Container>
void queue<T, Container>::push(const_reference value) {
  example.push_back(value);
}
//-------------pop-------------//
template <typename T, typename Container>
void queue<T, Container>::pop() {
  example.pop_front();
}
//-------------swap-------------//
template <typename T, typename Container>
void queue<T, Container>::swap(queue &other) {
  example.swap(other.example);
}
//-------------PRINT DELETE IT-------------//
template <typename T, typename Container>
void queue<T, Container>::print_queue() {
  example.print_deque();
}

template <typename T, typename Container>
template <typename... Args>
void queue<T, Container>::insert_many_back(Args &&...args) {
  for (const auto &item : {args...}) push(item);
}
}  // namespace s21
#endif
