#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../../containers/tree/s21_tree.h"
#include "../../containers/vector/vector.h"

namespace s21 {

template <typename Key>
class multiset : public BinaryTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using iterator = typename BinaryTree<Key, Key>::iterator;
  using const_iterator = typename BinaryTree<Key, Key>::const_iterator;
  using const_reference = const value_type&;
  using size_type = size_t;

  /*--------- constructors ---------*/

  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& ms);
  multiset(multiset&& ms);
  ~multiset();

  /*---------- modifiers -----------*/

  iterator insert(const value_type& value);
  void merge(multiset<Key>& other);
  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  /*------------ lookup ------------*/

  size_type count(const Key& key);
  iterator find(const Key& key);
  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);

  /*------------ support -----------*/

  void ShowTree();

 private:
  void AddRecurs(multiset<Key>& other, NodeTree<Key, Key>* node);
  iterator InsertRecurs(NodeTree<Key, Key>*& root, const Key& key);
  void CopyTree(NodeTree<Key, Key>* node);
  void ShowTreeRecurs(const NodeTree<Key, Key>& node);
};

}  // namespace s21

#include "s21_multiset.cc"

#endif