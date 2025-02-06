#ifndef S21_DEQUE_CC
#define S21_DEQUE_CC
#include "deque.h"

namespace s21 {
template <typename T>
deque<T>::deque() : head(nullptr), tail(nullptr), sizze(0){};

template <typename T>
deque<T>::deque(std::initializer_list<value_type> const &items)
    : head(nullptr), tail(nullptr), sizze(0) {
  for (auto i = items.begin(); i < items.end(); i++) {
    push_back(*i);
  }
};

template <typename T>
deque<T>::deque(const deque &q) : head(nullptr), tail(nullptr), sizze(0) {
  Node<T> *curr = q.head;
  while (curr) {
    push_back(curr->data);
    curr = curr->next;
  }
};

template <typename T>
deque<T>::deque(deque &&q) : head(q.head), tail(q.tail), sizze(q.sizze) {
  q.head = nullptr;
  q.tail = nullptr;
  q.sizze = 0;
};

template <typename T>
deque<T>::~deque() {
  while (tail != nullptr) {
    this->pop_back();
  }
  head = nullptr;
  sizze = 0;
}

template <typename T>
deque<T> &s21::deque<T>::operator=(deque &&q) {
  if (this != &q) {
    clear();
    head = q.head;
    tail = q.tail;
    sizze = q.sizze;

    q.sizze = 0;
    q.tail = nullptr;
    q.head = nullptr;
  }
  return *this;
}

template <typename T>
bool deque<T>::operator!=(const deque &q) {
  return (head != q.head && tail != q.tail && sizze != q.sizze);
}

template <typename T>
void deque<T>::clear() {
  while (head != nullptr) {
    Node<T> *curr = head;
    head = head->next;
    delete curr;
  }
  tail = nullptr;
  sizze = 0;
}

template <typename T>
typename deque<T>::const_reference deque<T>::front() {
  if (head == nullptr) throw std ::invalid_argument("-error-");
  Node<T> *front_head = head;
  return front_head->data;
}

template <typename T>
typename deque<T>::const_reference deque<T>::back() {
  if (head == nullptr) throw std ::invalid_argument("-error-");
  return tail->data;
}

template <typename T>
bool deque<T>::empty() {
  int code = true;
  if (head != nullptr) {
    code = false;
  } else
    code = true;
  return code;
}

template <typename T>
void deque<T>::push_back(const_reference value) {
  Node<T> *new_node = new Node<T>(value);
  if (head == nullptr) {
    head = tail = new_node;
  } else {
    Node<T> *copy_tail = tail;
    tail->next = new_node;
    tail = new_node;
    tail->prev = copy_tail;
  }
  sizze++;
}

template <typename T>
void deque<T>::pop_back() {
  if (tail == nullptr)
    head = tail = nullptr;
  else if (head == tail) {
    delete tail;
    head = tail = nullptr;
  } else {
    Node<T> *curr = tail->prev;
    delete tail;
    tail = curr;
    tail->next = nullptr;
  }
  sizze--;
}

template <typename T>
void deque<T>::pop_front() {
  if (head == nullptr) {
    head = tail = nullptr;
  } else if (head == tail) {
    delete head;
    head = tail = nullptr;
  } else {
    Node<T> *curr = head->next;
    delete head;
    head = curr;
    head->prev = nullptr;
  }
  sizze--;
}

template <typename T>
void deque<T>::push_front(const_reference value) {
  Node<T> new_node = new Node<T>(value);
  if (tail == nullptr) {
    tail == head == nullptr;
  } else {
    Node<T> *copyhead = head;
    head->next = new_node;
    head = new_node;
    head->prev = copyhead;
  }
  size++;
}

template <typename T>
void deque<T>::swap(deque &other) {
  std::swap(head, other.head);
  std::swap(sizze, other.sizze);
  std::swap(tail, other.tail);
}

template <typename T>
typename deque<T>::size_type deque<T>::size() {
  size_t sizee = this->sizze;
  return sizee;
}

template <typename T>
void s21::deque<T>::print_deque() {
  if (head == nullptr)
    std::cout << "Empty";
  else {
    Node<T> *print = head;

    while (print) {
      std::cout << print->data;
      print = print->next;
    }
    std::cout << std::endl;
  }
}
}  // namespace s21
#endif