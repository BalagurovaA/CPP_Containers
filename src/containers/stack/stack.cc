#ifndef S21_STACK_CC
#define S21_STACK_CC
#include "stack.h"

namespace s21 {
//-------------конструктор создает пустой стек-------------//
template <typename T, typename Container>
stack<T, Container>::stack() : example(){};

//-------------конструктор для фигурных скобок-------------//
template <typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i < items.end(); i++) {
    push(*i);  //указатель на i quest
  }
}
//-------------copy constructor-------------//
template <typename T, typename Container>
stack<T, Container>::stack(const stack &s) : example(s.example){};

//-------------move constructor-------------//
template <typename T, typename Container>
stack<T, Container>::stack(stack &&s) : example(std::move(s.example)){};

//-------------destructor-------------//
template <typename T, typename Container>
stack<T, Container>::~stack() {
  example.~deque();
};

//-------------опреатор =-------------//
template <typename T, typename Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&s) {
  this->example = std::move(s.example);
  return *this;
}

//-------------top-------------//
template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() {
  if (example.empty() == true) throw std ::invalid_argument("-error-");
  return example.back();
}

//-------------проверяет пустой контейнер или нет-------------//
template <typename T, typename Container>
bool stack<T, Container>::empty() {
  return example.empty();
}

//-------------size-------------//
template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() {
  return example.size();
}

//-------------push-------------//
template <typename T, typename Container>
void stack<T, Container>::push(const_reference value) {
  example.push_back(value);
}

//-------------pop-------------//
template <typename T, typename Container>
void stack<T, Container>::pop() {
  example.pop_back();
}

//-------------swap-------------//
template <typename T, typename Container>  //
void stack<T, Container>::swap(stack &other) {
  example.swap(other.example);
}
template <typename T, typename Container>
void stack<T, Container>::clear() {
  example.clear();
}

//-------------допка push many-------------//
template <typename T, typename Container>
template <typename... Args>
void stack<T, Container>::insert_many_front(Args &&...args) {
  for (const auto &item : {args...}) push(item);
}

}  // namespace s21
#endif
