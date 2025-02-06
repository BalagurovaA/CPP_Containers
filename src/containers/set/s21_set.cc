#ifndef S21_SET_CC
#define S21_SET_CC
#include "s21_set.h"

namespace s21 {

/*--------------------- constructors ---------------------*/

template <typename Key>
set<Key>::set() : BinaryTree<Key, Key>(){};

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const& items) {
  for (auto i = items.begin(); i < items.end(); i++) {
    insert(*i);
    this->Balance();
  }
}

template <typename Key>
set<Key>::set(const set& s) : BinaryTree<Key, Key>(s){};

template <typename Key>
set<Key>::set(set&& s) : BinaryTree<Key, Key>(std::move(s)){};

template <typename Key>
set<Key>::~set() {
  this->clear();
}

/*----------------------- modifiers ----------------------*/

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  std::pair<iterator, bool> code =
      this->InsertRecurs(this->root, value, value, false);
  this->Balance();
  return code;
}

template <typename Key>
template <typename... Args>
vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  for (const auto& item : {args...}) {
    result.push_back(insert(item));
  }
  return result;
}

/*------------------------ lookup ------------------------*/

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  NodeTree<Key, Key>* node = this->GetRoot();
  bool flag_exit = (node != nullptr) ? true : false;
  while (flag_exit) {
    if (key == node->first) {
      flag_exit = false;
    } else if (key < node->first) {
      node = node->GetLeft();
    } else if (key > node->first) {
      node = node->GetRight();
    }

    if (node == nullptr) flag_exit = false;
  }

  return (node == nullptr) ? this->end() : iterator(node);
}

}  // namespace s21

#endif