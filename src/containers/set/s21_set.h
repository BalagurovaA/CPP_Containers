#ifndef S21_SET_H
#define S21_SET_H

#include <iostream>

#include "../tree/s21_tree.h"
#include "../vector/vector.h"

namespace s21 {

template <typename Key>
class set : public BinaryTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using iterator = typename BinaryTree<Key, Key>::iterator;
  using const_iterator = typename BinaryTree<Key, Key>::const_iterator;
  using const_reference = const value_type &;
  using size_type = size_t;

  /*--------- constructors ---------*/

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);
  ~set();

  /*---------- modifiers -----------*/

  std::pair<iterator, bool> insert(const value_type &value);
  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  /*------------ lookup ------------*/

  iterator find(const Key &key);
};
}  // namespace s21

#include "s21_set.cc"
#endif