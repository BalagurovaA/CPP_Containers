#ifndef S21_TREE_CC
#define S21_TREE_CC

#include "s21_tree.h"

namespace s21 {

/*----------------------------------------------------------------*/
/*------------------------- BINARY TREE --------------------------*/
/*----------------------------------------------------------------*/

/*------------------------- constructors -------------------------*/

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree() : root(nullptr), count_nodes(0) {}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(const BinaryTree<Key, T>& other)
    : root(nullptr), count_nodes(0) {
  if (other.root != nullptr) {
    CopyTree(other.root);
    count_nodes = other.count_nodes;
  }
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(BinaryTree<Key, T>&& other) {
  root = other.root;
  count_nodes = other.count_nodes;

  other.root = nullptr;
  other.count_nodes = 0;
}

template <typename Key, typename T>
BinaryTree<Key, T>::~BinaryTree() {
  clear();
}

/*--------------------------- overload ---------------------------*/

template <typename Key, typename T>
BinaryTree<Key, T>& BinaryTree<Key, T>::operator=(BinaryTree<Key, T>&& other) {
  if (root != nullptr) clear();
  if (other.root != nullptr) {
    root = other.root;
    count_nodes = other.count_nodes;

    other.root = nullptr;
    other.count_nodes = 0;
  }
  return *this;
}

/*--------------------------- balance ----------------------------*/

template <typename Key, typename T>
int BinaryTree<Key, T>::GetHeight(NodeTree<Key, T>* node) {
  if (node == nullptr) return 0;
  int heightLeft = 0;
  int heightRight = 0;
  if (node->Left != nullptr) heightLeft = GetHeight(node->Left);
  if (node->Right != nullptr) heightRight = GetHeight(node->Right);
  int maxHeight = std::max(heightRight, heightLeft);
  return std::max(maxHeight, node->height);
}

template <typename Key, typename T>
int BinaryTree<Key, T>::BalanceHeight() {
  return GetHeight(root->Right) - GetHeight(root->Left);
}

template <typename Key, typename T>
int BinaryTree<Key, T>::UpdateHeight(NodeTree<Key, T>* node) {
  if (root == nullptr) return 0;
  if (node == root)
    node->height = 0;
  else
    node->height = node->Parent->height + 1;
  if (node->Left != nullptr) UpdateHeight(node->Left);
  if (node->Right != nullptr) UpdateHeight(node->Right);
  return 1;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::RightTurn() {
  NodeTree<Key, T>* NewRoot = root->Right;
  NodeTree<Key, T>* NodeChange = NewRoot->Left;
  NodeTree<Key, T>* OldRoot = root;
  root = NewRoot;
  NewRoot->Parent = nullptr;
  OldRoot->Parent = NewRoot;
  NewRoot->Left = OldRoot;
  if (NodeChange != nullptr) NodeChange->Parent = OldRoot;
  OldRoot->Right = NodeChange;
  UpdateHeight(root);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::LeftTurn() {
  NodeTree<Key, T>* NewRoot = root->Left;
  NodeTree<Key, T>* NodeChange = NewRoot->Right;
  NodeTree<Key, T>* OldRoot = root;
  root = NewRoot;
  NewRoot->Parent = nullptr;
  OldRoot->Parent = NewRoot;
  NewRoot->Right = OldRoot;
  if (NodeChange != nullptr) NodeChange->Parent = OldRoot;
  OldRoot->Left = NodeChange;
  UpdateHeight(root);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::Balance() {
  if (UpdateHeight(this->root)) {
    if (count_nodes == 3 && BalanceHeight() != 0)
      ChangeTrio();
    else if (BalanceHeight() > 1)
      RightTurn();
    else if (BalanceHeight() < -1)
      LeftTurn();
    UpdateHeight(root);
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::ChangeTrio() {
  NodeTree<Key, T>* NodeMax = nullptr;
  NodeTree<Key, T>* NodeMin = nullptr;
  NodeTree<Key, T>* NodeMid = nullptr;

  if (root->Right != nullptr) {
    NodeMin = root;
    NodeMid = (root->Right->Right != nullptr) ? root->Right : root->Right->Left;
    NodeMax = (NodeMid == root->Right) ? NodeMid->Right : root->Right;
  } else {
    NodeMax = root;
    NodeMid = (root->Left->Left != nullptr) ? root->Left : root->Left->Right;
    NodeMin = (NodeMid == root->Left) ? NodeMid->Left : root->Left;
  }

  root = NodeMid;
  NodeMid->Parent = nullptr;

  ConnectLeaf(NodeMax, false);
  ConnectLeaf(NodeMin, true);

  UpdateHeight(root);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::ConnectLeaf(NodeTree<Key, T>* leaf, bool isLeft) {
  if (isLeft)
    root->Left = leaf;
  else
    root->Right = leaf;
  leaf->Parent = root;
  leaf->Left = nullptr;
  leaf->Right = nullptr;
}

/*---------------------- accessor & mutator ----------------------*/

// Возвращает указатель на корень дерева
template <typename Key, typename T>
NodeTree<Key, T>* BinaryTree<Key, T>::GetRoot() {
  return root;
}

/*-------------------------- modifiers ---------------------------*/

// Очищает все дерево
template <typename Key, typename T>
void BinaryTree<Key, T>::clear() {
  ClearRecurs(root);
  count_nodes = 0;
  countNotUniq = 0;
}

// Вставляет новый элемент в дерево
template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const value_type& value) {
  std::pair<iterator, bool> code =
      InsertRecurs(root, value.first, value.second, false);
  Balance();
  return code;
}

// Вставляет новый элемент в дерево
template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const Key& key, const T& obj) {
  std::pair<iterator, bool> code = InsertRecurs(root, key, obj, false);
  UpdateHeight(this->root);
  Balance();
  return code;
}

// Стирает определенный элемент из дерева
template <typename Key, typename T>
void BinaryTree<Key, T>::erase(iterator pos) {
  if (pos.GetStartNode() == nullptr || root == nullptr)
    throw std::invalid_argument("invalid iterator or tree");

  NodeTree<Key, T>* node = pos.StartNode;

  if (node->countTwins > 0) {
    node->countTwins--;
    countNotUniq--;
  } else {
    if (!contains(node->key_)) throw std::invalid_argument("invalid iterator");
    NodeTree<Key, T>* parent = node->Parent;

    if (node->Left == nullptr && node->Right == nullptr) {
      ConnectBranch(parent, nullptr, node);
    } else if (node->Left == nullptr || node->Right == nullptr) {
      NodeTree<Key, T>* leaf =
          (node->Left != nullptr) ? node->Left : node->Right;
      ConnectBranch(parent, leaf, node);
      leaf->Parent = parent;
    } else {
      ConnectBranch(parent, node->Right, node);
      node->Right->Parent = parent;
      MergeBranches(node);
    }

    delete node;
    count_nodes--;

    Balance();
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::swap(BinaryTree<Key, T>& other) {
  std::swap(root, other.root);
  std::swap(count_nodes, other.count_nodes);
  std::swap(countNotUniq, other.countNotUniq);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::merge(BinaryTree<Key, T>& other) {
  BinaryTree<Key, T> buff;
  NodeTree<Key, T>* node = other.GetRoot();
  AddRecurs(buff, other, node);
  other = std::move(buff);

  Balance();
  other.Balance();
}

/*--------------------------- iterators --------------------------*/

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  NodeTree<Key, T>* node = root;
  while (node->Left != nullptr) node = node->Left;
  iterator result(node);

  return result;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  return iterator();
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::const_iterator BinaryTree<Key, T>::cbegin() {
  iterator it = begin();
  const_iterator result(it.StartNode);
  return result;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::const_iterator BinaryTree<Key, T>::cend() {
  return const_iterator();
}

/*--------------------------- capacity ---------------------------*/

template <typename Key, typename T>
bool BinaryTree<Key, T>::empty() {
  return root == nullptr ? true : false;
}

template <typename Key, typename T>
size_t BinaryTree<Key, T>::size() {
  return count_nodes + countNotUniq;
}

template <typename Key, typename T>
size_t BinaryTree<Key, T>::max_size() {
  return std::numeric_limits<size_type>::max() /
         sizeof(BinaryTree<Key, T>::root) / 10;
}

/*---------------------------- lookup ----------------------------*/

template <typename Key, typename T>
bool BinaryTree<Key, T>::contains(const Key& key) {
  return SearchKey(key, root);
}

/*--------------------------- support ----------------------------*/

template <typename Key, typename T>
void BinaryTree<Key, T>::ClearRecurs(NodeTree<Key, T>* node) {
  if (node != nullptr) {
    if (node->Left != nullptr) ClearRecurs(node->Left);
    if (node->Right != nullptr) ClearRecurs(node->Right);
    delete node;
  }
  root = nullptr;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::CopyTree(NodeTree<Key, T>* node) {
  insert(node->key_, node->obj_);

  if (node->Left != nullptr) {
    CopyTree(node->Left);
  }
  if (node->Right != nullptr) {
    CopyTree(node->Right);
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::ShowTree() {
  std::cout << "TREE\n";
  ShowTreeRecurs(*root);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::ShowTreeRecurs(const NodeTree<Key, T>& node) {
  if (root != nullptr) {
    if (node.Left != nullptr) {
      ShowTreeRecurs(*node.Left);
    }
    std::cout << "KEY = " << node.key_ << " OBJ = " << node.obj_
              << " HEIGHT = " << node.height << std::endl;
    if (node.Right != nullptr) {
      ShowTreeRecurs(*node.Right);
    }
  } else
    std::cout << "TREE EMPTY\n";
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::InsertRecurs(NodeTree<Key, T>*& root, const Key& key,
                                 const T& obj, bool assign) {
  std::pair<iterator, bool> code = std::make_pair(iterator(), true);
  if (root == nullptr) {
    root = new NodeTree<Key, T>(key, obj);
    if (root == nullptr) throw std::bad_alloc();
    count_nodes++;
  } else if (root->key_ > key) {
    code = InsertRecurs(root->Left, key, obj, assign);
    root->Left->Parent = root;
  } else if (root->key_ < key) {
    code = InsertRecurs(root->Right, key, obj, assign);
    root->Right->Parent = root;
  } else if (assign) {
    root->obj_ = obj;
    root->second = obj;
  } else {
    code.second = false;
  }
  code.first = iterator(root);

  return code;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::SearchKey(const Key& key, NodeTree<Key, T>* node) {
  bool result = false;
  if (key < node->key_ && node->Left != nullptr) {
    result = SearchKey(key, node->Left);
  } else if (key > node->key_ && node->Right != nullptr) {
    result = SearchKey(key, node->Right);
  } else if (key == node->key_) {
    result = true;
  }
  return result;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::AddRecurs(BinaryTree<Key, T>& buff,
                                   BinaryTree<Key, T>& other,
                                   NodeTree<Key, T>* node) {
  if (node->Left != nullptr) AddRecurs(buff, other, node->Left);
  if (node->Right != nullptr) AddRecurs(buff, other, node->Right);

  if (!contains(node->key_)) {
    insert(node->key_, node->obj_);
  } else {
    buff.insert(node->key_, node->obj_);
  }
}

template <typename Key, typename T>
void BinaryTree<Key, T>::MergeBranches(NodeTree<Key, T>* node) {
  NodeTree<Key, T>* MinRight = node->Right;
  while (MinRight->Left != nullptr) MinRight = MinRight->Left;
  MinRight->Left = node->Left;
  node->Left->Parent = MinRight;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::ConnectBranch(NodeTree<Key, T>* parent,
                                       NodeTree<Key, T>* leaf,
                                       NodeTree<Key, T>* node) {
  if (parent != nullptr)
    parent->Left == node ? parent->Left = leaf : parent->Right = leaf;
  else
    root = leaf;
}

/*----------------------------------------------------------------*/
/*--------------------------- NODE TREE --------------------------*/
/*----------------------------------------------------------------*/

/*------------------------- constructors -------------------------*/

// Параметизированный конструктор
template <typename Key, typename T>
NodeTree<Key, T>::NodeTree(Key key, T obj) {
  Left = nullptr;
  Right = nullptr;
  Parent = nullptr;
  obj_ = obj;
  key_ = key;
  first = key_;
  second = obj_;
}

// Деструктор
template <typename Key, typename T>
NodeTree<Key, T>::~NodeTree() {
  Left = nullptr;
  Right = nullptr;
  Parent = nullptr;
}

/*---------------------- accessor & mutator ----------------------*/

template <typename Key, typename T>
NodeTree<Key, T>* NodeTree<Key, T>::GetLeft() {
  return Left;
}

template <typename Key, typename T>
NodeTree<Key, T>* NodeTree<Key, T>::GetRight() {
  return Right;
}

/*----------------------------------------------------------------*/
/*--------------------------- ITERATOR ---------------------------*/
/*----------------------------------------------------------------*/

/*------------------------- constructors -------------------------*/

//Конструктор по умолчанию, создает итератор указетаель на узел дерева равный
//нуллу
template <typename Key, typename T>
BinaryTree<Key, T>::iterator::iterator() : StartNode(nullptr) {}

//Конструктор копирования
template <typename Key, typename T>
BinaryTree<Key, T>::iterator::iterator(const BinaryTree::iterator& other)
    : StartNode(other.StartNode) {}

//Конструктор
template <typename Key, typename T>
BinaryTree<Key, T>::iterator::iterator(NodeTree<Key, T>* start)
    : StartNode(start) {}

/*--------------------------- overload ---------------------------*/

template <typename Key, typename T>
Key BinaryTree<Key, T>::iterator::operator*() {
  return (StartNode == nullptr) ? Key{} : StartNode->key_;
}

template <typename Key, typename T>
NodeTree<Key, T>* BinaryTree<Key, T>::iterator::operator->() {
  return StartNode;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::operator++() {
  if (StartNode == nullptr) return *this;
  if (StartNode->countTwins > 0 &&
      StartNode->currentLoc < StartNode->countTwins) {
    StartNode->currentLoc++;
  } else if (StartNode->key_ == GetMaxKey(StartNode)) {
    StartNode = nullptr;
  } else {
    NodeTree<Key, T>* parent = StartNode->Parent;

    if (StartNode->Right != nullptr) {
      StartNode->currentLoc = 0;
      StartNode = StartNode->Right;
      while (StartNode->Left != nullptr) StartNode = StartNode->Left;
    } else if (parent->Right == StartNode) {
      StartNode->currentLoc = 0;
      StartNode = parent->Parent;
    } else if (parent != nullptr && StartNode->Right == nullptr) {
      StartNode->currentLoc = 0;
      StartNode = parent;
    }
  }
  return *this;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator
BinaryTree<Key, T>::iterator::operator--() {
  if (StartNode == nullptr)
    return *this;
  else if (StartNode->countTwins > 0 && StartNode->currentLoc > 0) {
    StartNode->currentLoc--;
  } else {
    NodeTree<Key, T>* parent = StartNode->Parent;

    if (StartNode->Left != nullptr) {
      StartNode = StartNode->Left;
      while (StartNode->Right != nullptr) StartNode = StartNode->Right;
      StartNode->currentLoc = StartNode->countTwins;
    } else if (parent->Left == StartNode) {
      StartNode = parent->Parent;
      StartNode->currentLoc = StartNode->countTwins;
    } else if (parent != nullptr && StartNode->Left == nullptr) {
      StartNode = parent;
      StartNode->currentLoc = StartNode->countTwins;
    }
  }

  return *this;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::iterator::operator==(
    const BinaryTree<Key, T>::iterator& other) {
  return StartNode == other.StartNode ? true : false;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::iterator::operator!=(
    const BinaryTree<Key, T>::iterator& other) {
  return StartNode != other.StartNode ? true : false;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::iterator::operator=(
    const iterator& other) {
  StartNode = other.StartNode;
  return *this;
}

/*--------------------------- support ----------------------------*/

template <typename Key, typename T>
Key BinaryTree<Key, T>::iterator::GetMaxKey(NodeTree<Key, T>* node) {
  NodeTree<Key, T>* parent = node;
  while (parent->Parent != nullptr) parent = parent->Parent;

  NodeTree<Key, T>* nodeMax = parent;
  while (nodeMax->Right != nullptr) nodeMax = nodeMax->Right;

  return nodeMax->key_;
}

/*---------------------- accessor & mutator ----------------------*/

template <typename Key, typename T>
NodeTree<Key, T>* BinaryTree<Key, T>::iterator::GetStartNode() {
  return StartNode;
}

/*----------------------------------------------------------------*/
/*------------------------ CONST ITERATOR ------------------------*/
/*----------------------------------------------------------------*/

/*------------------------- constructors -------------------------*/

template <typename Key, typename T>
BinaryTree<Key, T>::const_iterator::const_iterator() : iterator(){};

template <typename Key, typename T>
BinaryTree<Key, T>::const_iterator::const_iterator(
    const BinaryTree::const_iterator& other)
    : iterator(other){};

template <typename Key, typename T>
BinaryTree<Key, T>::const_iterator::const_iterator(NodeTree<Key, T>* start)
    : iterator(start){};

/*--------------------------- overload ---------------------------*/

template <typename Key, typename T>
const Key BinaryTree<Key, T>::const_iterator::operator*() {
  return (this->StartNode == nullptr) ? Key{} : this->StartNode->key_;
}

template <typename Key, typename T>
const NodeTree<Key, T>* BinaryTree<Key, T>::const_iterator::operator->() {
  return this->StartNode;
}

}  // namespace s21

#endif