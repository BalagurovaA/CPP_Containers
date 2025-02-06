#ifndef S21_TREE_H
#define S21_TREE_H

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename Key, typename T>
class BinaryTree;

template <typename Key, typename T>
class NodeTree;

template <typename Key>
class multiset;

/*--------------------------------------------------*/
/*------------------- NODE TREE --------------------*/
/*--------------------------------------------------*/

template <typename Key, typename T>
class NodeTree {
  friend class BinaryTree<Key, T>;
  friend class multiset<Key>;

 private:
  NodeTree *Left;
  NodeTree *Right;
  NodeTree *Parent;
  T obj_ = 0;
  Key key_ = 0;
  int height = 0;
  int countTwins = 0;
  int currentLoc = 0;

 public:
  Key first = 0;
  T second = 0;

  NodeTree *GetLeft();
  NodeTree *GetRight();

  NodeTree(Key key, T obj);
  ~NodeTree();

  // void SetParent(NodeTree *node);
};

/*--------------------------------------------------*/
/*------------------ BINARY TREE -------------------*/
/*--------------------------------------------------*/

template <typename Key, typename T>
class BinaryTree {
 public:
  class iterator;
  class const_iterator;

  /*----- binary tree mem type ----*/

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using const_iterator = BinaryTree::const_iterator;
  using size_type = size_t;

  /*----- binary tree element -----*/

 protected:
  NodeTree<Key, T> *root;
  size_type count_nodes = 0;
  size_type countNotUniq = 0;

  /*----- binary tree iterators ----*/

 public:
  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();

  /*------- member functions -------*/

  BinaryTree();
  BinaryTree(const BinaryTree<Key, T> &other);
  BinaryTree(BinaryTree<Key, T> &&other);
  ~BinaryTree();

  /*----------- overload -----------*/

  BinaryTree &operator=(BinaryTree &&other);

  /*----------- balance ------------*/

 protected:
  int GetHeight(NodeTree<Key, T> *node);
  int UpdateHeight(NodeTree<Key, T> *node);
  void RightTurn();
  void LeftTurn();
  int BalanceHeight();
  void Balance();
  void ChangeTrio();
  void ConnectLeaf(NodeTree<Key, T> *leaf, bool isLeft);

  /*----------- capasity -----------*/

 public:
  bool empty();
  size_type size();
  size_type max_size();

  /*------ accessor & mutator ------*/

 protected:
  NodeTree<Key, T> *GetRoot();

  /*---------- modifiers -----------*/

 public:
  void clear();  // нужно переделать
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  void erase(iterator pos);
  void swap(BinaryTree<Key, T> &other);
  void merge(BinaryTree<Key, T> &other);

  /*------------ lookup ------------*/

  bool contains(const Key &key);

  /*----------- support ------------*/

  void ShowTree();

 protected:
  void ClearRecurs(NodeTree<Key, T> *node);
  void ShowTreeRecurs(const NodeTree<Key, T> &node);
  std::pair<iterator, bool> InsertRecurs(NodeTree<Key, T> *&root,
                                         const Key &key, const T &obj,
                                         bool assign);
  bool SearchKey(const Key &key, NodeTree<Key, T> *node);
  void ConnectBranch(NodeTree<Key, T> *parent, NodeTree<Key, T> *leaf,
                     NodeTree<Key, T> *node);
  void MergeBranches(NodeTree<Key, T> *node);
  void AddRecurs(BinaryTree<Key, T> &buff, BinaryTree<Key, T> &other,
                 NodeTree<Key, T> *node);
  void CopyTree(NodeTree<Key, T> *node);

  /* ====================== iterator ====================== */

 public:
  class iterator {
    friend class multiset<Key>;
    friend class BinaryTree<Key, T>;

   protected:
    NodeTree<Key, T> *StartNode;

   public:
    //--- constructors ---//

    iterator();
    iterator(const BinaryTree::iterator &other);
    iterator(NodeTree<Key, T> *start);

    //--- overload ---//

    Key operator*();
    NodeTree<Key, T> *operator->();
    iterator operator++();
    iterator operator--();
    bool operator==(const BinaryTree<Key, T>::iterator &other);
    bool operator!=(const BinaryTree<Key, T>::iterator &other);
    iterator operator=(const iterator &other);

    //--- support ---//

    Key GetMaxKey(NodeTree<Key, T> *node);

    // --- accessor & mutator ---//
    NodeTree<Key, T> *GetStartNode();
  };

  class const_iterator : public iterator {
   public:
    //--- constructors ---//

    const_iterator();
    const_iterator(const BinaryTree::const_iterator &other);
    const_iterator(NodeTree<Key, T> *start);

    //--- overload ---//

    const Key operator*();
    const NodeTree<Key, T> *operator->();
  };
};
}  // namespace s21

#include "s21_tree.cc"
#endif