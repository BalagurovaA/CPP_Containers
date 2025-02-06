#pragma once

#ifndef S21_LIST_H
#define S21_LIST_H

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>

template <typename T>
class Node {
 public:
  T val;
  Node* prev;
  Node* next;

  Node(T _val) : val(_val), prev(nullptr), next(nullptr) {}
};

namespace s21 {
template <typename T>
class list {
 private:
  Node<T>* head;
  Node<T>* tail;
  size_t size;

 public:
  class iterator;
  class const_iterator;

  using size_type = size_t;
  using const_reference = const T&;

  list();
  list(size_type n);
  list(std::initializer_list<T> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l) noexcept;

  const T& front() {
    if (head == nullptr) {
      throw std::out_of_range("List is empty");
    }
    return head->val;
  }

  const T& back() {
    if (tail == nullptr) {
      throw std::out_of_range("List is empty");
    }
    return tail->val;
  }

  iterator begin() { return iterator(head); }

  iterator end() { return iterator(nullptr); }

  const_iterator cbegin() const { return const_iterator(head); }

  const_iterator cend() const { return const_iterator(nullptr); }

  bool empty() const;
  size_type list_size() const;
  size_type max_size();

  void clear();

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const T& value);
  void pop_back();
  void push_front(const T& value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);

  void splice(const_iterator pos, list& other);

  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);
  template <typename... Args>
  void insert_many_front(Args&&... args);

 public:
  class iterator {
    friend class Node<T>;

   public:
    Node<T>* current;
    iterator(Node<T>* ptr = nullptr) : current(ptr) {}
    T& operator*() const { return current->val; }

    iterator& operator++() {
      if (current) {
        current = current->next;
      }
      return *this;
    }

    iterator& operator--() {
      if (current != nullptr) {
        current = current->prev;
      }
      return *this;
    }

    iterator& operator+=(int n) {
      while (n > 0) {
        ++(*this);
        --n;
      }
      while (n < 0) {
        --(*this);
        ++n;
      }
      return *this;
    }

    bool operator==(const iterator& other) const {
      return current == other.current;
    }

    bool operator!=(const iterator& other) const { return !(*this == other); }
  };

 public:
  class const_iterator : public iterator {
    friend class list;

   public:
    const_iterator(Node<T>* ptr = nullptr) : iterator(ptr) {}

    const T& operator*() const { return this->current->val; }
  };
};

}  // namespace s21

#include "s21_list.cc"
#endif
