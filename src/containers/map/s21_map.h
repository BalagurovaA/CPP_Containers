#ifndef S21_MAP_H
#define S21_MAP_H

#include <iostream>

#include "../tree/s21_tree.h"
#include "../vector/vector.h"

namespace s21 {

template <typename Key, typename T>
class map : public BinaryTree<Key, T> {
 public:
  /*------------ map member type -----------*/

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename BinaryTree<Key, T>::iterator;
  using const_iterator = typename BinaryTree<Key, T>::const_iterator;
  using size_type = size_t;

  /*--------- map member functions ---------*/

  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map();

  /*--------- map member functions ---------*/

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  /*---------- map element access ----------*/

  T& at(const Key& key);
  T& operator[](const Key& key);

  /*---------- map element access ----------*/

  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
};
}  // namespace s21

#include "s21_map.cc"

#endif