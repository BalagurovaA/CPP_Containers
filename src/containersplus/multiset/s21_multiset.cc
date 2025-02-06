#ifndef S21_MULTISET_CC
#define S21_MULTISET_CC
#include "s21_multiset.h"

namespace s21 {

/*--------------------- constructors ---------------------*/

template <typename Key>
multiset<Key>::multiset() : BinaryTree<Key, Key>(){};

template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const& items) {
  for (auto i = items.begin(); i < items.end(); i++) {
    insert(*i);
  }
}

template <typename Key>
multiset<Key>::multiset(const multiset& ms) : BinaryTree<int, int>() {
  if (ms.root != nullptr) {
    CopyTree(ms.root);
    this->count_nodes = ms.count_nodes;
  }
}

template <typename Key>
multiset<Key>::multiset(multiset&& ms) : BinaryTree<Key, Key>(std::move(ms)){};

template <typename Key>
multiset<Key>::~multiset() {
  this->clear();
}

/*---------------------- modifiers -----------------------*/

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::insert(
    const value_type& value) {
  iterator result = InsertRecurs(this->root, value);
  this->Balance();
  return result;
}

template <typename Key>
void multiset<Key>::merge(multiset<Key>& other) {
  NodeTree<Key, Key>* node = other.GetRoot();
  AddRecurs(other, node);
  other.clear();
  this->Balance();
}

template <typename Key>
template <typename... Args>
vector<std::pair<typename multiset<Key>::iterator, bool>>
multiset<Key>::insert_many(Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  for (const auto& item : {args...}) {
    result.push_back(std::make_pair(insert(item), true));
  }
  return result;
}

/*------------------------ lookup ------------------------*/

template <typename Key>
size_t multiset<Key>::count(const Key& key) {
  auto it = find(key);
  NodeTree<Key, Key>* node = it.StartNode;

  return node->countTwins + 1;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key& key) {
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

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key& key) {
  iterator first_ = find(key);
  iterator second_ = find(key);

  while (second_.StartNode->currentLoc != 0) ++second_;
  ++second_;

  std::pair<iterator, iterator> result = std::make_pair(first_, second_);

  return result;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  iterator result = find(key);
  result.StartNode->currentLoc = 0;
  return result;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  iterator result = find(key);
  NodeTree<Key, Key>* node = result.StartNode;
  node->currentLoc = node->countTwins;
  ++result;
  return result;
}

/*----------------------- support ------------------------*/

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::InsertRecurs(
    NodeTree<Key, Key>*& root, const Key& key) {
  iterator result;
  if (root == nullptr) {
    root = new NodeTree<Key, Key>(key, key);
    if (root == nullptr) throw std::bad_alloc();
    result.StartNode = root;
    this->count_nodes++;
  } else if (root->key_ > key) {
    result = InsertRecurs(root->Left, key);
    root->Left->Parent = root;
  } else if (root->key_ < key) {
    result = InsertRecurs(root->Right, key);
    root->Right->Parent = root;
  } else {
    root->countTwins++;
    this->countNotUniq++;
  }
  return result;
}

template <typename Key>
void multiset<Key>::ShowTree() {
  std::cout << "TREE\n";
  ShowTreeRecurs(*(this->root));
}

template <typename Key>
void multiset<Key>::ShowTreeRecurs(const NodeTree<Key, Key>& node) {
  if (this->root != nullptr) {
    if (node.Left != nullptr) {
      ShowTreeRecurs(*node.Left);
    }
    for (int i = 0; i <= node.countTwins; i++)
      std::cout << "KEY = " << node.key_ << " HEIGHT = " << node.height
                << std::endl;
    if (node.Right != nullptr) {
      ShowTreeRecurs(*node.Right);
    }
  } else
    std::cout << "TREE EMPTY\n";
}

template <typename Key>
void multiset<Key>::CopyTree(NodeTree<Key, Key>* node) {
  insert(node->key_);
  for (int i = 0; i < node->countTwins; i++) insert(node->key_);
  if (node->Left != nullptr) CopyTree(node->Left);
  if (node->Right != nullptr) CopyTree(node->Right);
}

template <typename Key>
void multiset<Key>::AddRecurs(multiset<Key>& other, NodeTree<Key, Key>* node) {
  if (node->Left != nullptr) AddRecurs(other, node->Left);
  if (node->Right != nullptr) AddRecurs(other, node->Right);
  insert(node->key_);
}

}  // namespace s21

#endif