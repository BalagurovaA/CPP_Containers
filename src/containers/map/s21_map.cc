#ifndef S21_MAP_CC
#define S21_MAP_CC

#include "s21_map.h"

namespace s21 {

/*--------------------- map member functions ---------------------*/

template <typename Key, typename T>
map<Key, T>::map() : BinaryTree<Key, T>(){};

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  for (auto i = items.begin(); i < items.end(); i++) {
    this->insert(i->first, i->second);
    this->Balance();
  }
}

template <typename Key, typename T>
map<Key, T>::map(const map& m) : BinaryTree<Key, T>(m){};

template <typename Key, typename T>
map<Key, T>::map(map&& m) : BinaryTree<Key, T>(std::move(m)){};

template <typename Key, typename T>
map<Key, T>::~map() {
  this->clear();
}

/*----------------------- map modifiers ------------------------*/

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<iterator, bool> code =
      this->InsertRecurs(this->root, key, obj, true);
  return code;
}

template <typename Key, typename T>
template <typename... Args>
vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  for (const auto& item : {args...}) {
    result.push_back(this->insert(item));
  }
  return result;
}

/*--------------------- map element access ---------------------*/

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  if (!this->contains(key)) throw std::out_of_range("map::at");

  NodeTree<Key, T>* node = this->root;
  while (node->first != key) {
    if (node->first > key)
      node = node->GetLeft();
    else if (node->first < key)
      node = node->GetRight();
  }

  return node->second;
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return at(key);
}

}  // namespace s21

#endif