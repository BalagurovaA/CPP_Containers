#ifndef S21_LIST_TPP
#define S21_LIST_TPP

#include "s21_list.h"

template <typename T>
s21::list<T>::list() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
s21::list<T>::list(size_t n) : head(nullptr), tail(nullptr), size(0) {
  for (size_t i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <typename T>
s21::list<T>::list(std::initializer_list<T> const& items)
    : head(nullptr), tail(nullptr), size(0) {
  for (auto item : items) {
    push_back(item);
  }
}

template <typename T>
s21::list<T>::list(const list<T>& other)
    : head(nullptr), tail(nullptr), size(0) {
  Node<T>* current = other.head;
  while (current) {
    push_back(current->val);
    current = current->next;
  }
}

template <typename T>
s21::list<T>& s21::list<T>::operator=(list&& l) noexcept {
  if (this != &l) {
    clear();

    head = l.head;
    tail = l.tail;
    size = l.size;

    l.head = nullptr;
    l.tail = nullptr;
    l.size = 0;
  }
  return *this;
}

template <typename T>
s21::list<T>::list(list&& l) : head(l.head), tail(l.tail), size(l.size) {
  l.head = nullptr;
  l.tail = nullptr;
  l.size = 0;
}

template <typename T>
s21::list<T>::~list() {
  this->clear();
}

template <typename T>
void s21::list<T>::clear() {
  Node<T>* current = head;
  while (current) {
    Node<T>* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T>
void s21::list<T>::push_back(const T& value) {
  Node<T>* newNode = new Node<T>(value);
  if (newNode == nullptr) throw std::bad_alloc();

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

template <typename T>
void s21::list<T>::push_front(const T& value) {
  Node<T>* newNode = new Node<T>(value);
  if (newNode == nullptr) throw std::bad_alloc();

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
  size++;
}

template <typename T>
void s21::list<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  if (head == tail) {
    delete head;
    head = tail = nullptr;
  } else {
    Node<T>* current = head;
    while (current->next != tail) {
      current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
  }
  size--;
}

template <typename T>
void s21::list<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  Node<T>* temp = head;
  head = head->next;
  delete temp;
  if (!head) {
    tail = nullptr;
  }
  size--;
}

template <typename T>
void s21::list<T>::reverse() {
  Node<T>* prhead_next = nullptr;
  Node<T>* phead = head;

  while (phead != nullptr) {
    Node<T>* p = phead->next;  // ссылка на след элемент.
    phead->next = prhead_next;  // Разворачиваем связь текущего элемента.
    prhead_next = phead;  // Сдвигаем указатель на голову перевёрнутого списка.
    phead = p;
  }

  head = prhead_next;

  Node<T>* newTail = head;
  while (newTail->next != nullptr) {
    newTail = newTail->next;
  }

  tail = newTail;
}

template <typename T>
size_t s21::list<T>::list_size() const {
  return size;
}

template <typename T>
bool s21::list<T>::empty() const {
  return size == 0;
}

template <typename T>
void s21::list<T>::swap(list<T>& other) {
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(size, other.size);
}

template <typename T>
void s21::list<T>::sort() {
  if (size <= 1) {
    return;
  }

  Node<T>* sorted = nullptr;
  Node<T>* current = head;
  tail =
      nullptr;  // Обнуляем tail перед сортировкой, чтобы обновить его правильно

  while (current) {
    Node<T>* next = current->next;

    if (sorted == nullptr || current->val < sorted->val) {
      current->next = sorted;
      sorted = current;
    } else {
      Node<T>* search = sorted;
      while (search->next && search->next->val < current->val) {
        search = search->next;
      }
      current->next = search->next;
      search->next = current;
    }

    if (current->next == nullptr) {
      tail = current;  // Если достигли конца списка, обновляем tail
    }

    current = next;
  }

  head = sorted;
}

template <typename T>
void s21::list<T>::unique() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* runner = current;
    while (runner->next != nullptr) {
      if (runner->next->val == current->val) {
        Node<T>* temp = runner->next;
        runner->next = runner->next->next;
        delete temp;
        size--;
      } else {
        runner = runner->next;
      }
    }
    current = current->next;
  }
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::max_size() {
  return std::numeric_limits<size_type>::max();
}

template <typename T>
void s21::list<T>::erase(iterator pos) {
  if (pos.current == nullptr) {
    return;
  }

  Node<T>* curr = head;
  Node<T>* prev = nullptr;

  while (curr != nullptr && pos.current != curr) {
    prev = curr;
    curr = curr->next;
  }

  if (prev != nullptr) {
    prev->next = curr->next;
  } else {
    head = curr->next;
  }

  if (curr == tail) {
    tail = prev;
  }

  delete curr;
  --size;
}

template <typename T>
void s21::list<T>::merge(list& other) {
  if (other.empty()) {
    return;
  }
  Node<T>* temp1 = head;
  Node<T>* temp2 = other.head;
  Node<T>* newHead = nullptr;
  Node<T>* newTail = nullptr;

  while (temp1 && temp2) {
    if (temp1->val <= temp2->val) {
      if (!newHead) {
        newHead = temp1;
        newTail = temp1;

      } else {
        newTail->next = temp1;
        newTail = temp1;
      }
      temp1 = temp1->next;
    } else {
      if (!newHead) {
        newHead = temp2;
        newTail = temp2;

      } else {
        newTail->next = temp2;
        newTail = temp2;
      }
      temp2 = temp2->next;
    }
  }
  while (temp1) {
    newTail->next = temp1;
    newTail = temp1;
    temp1 = temp1->next;
  }
  while (temp2) {
    newTail->next = temp2;
    newTail = temp2;
    temp2 = temp2->next;
  }

  head = newHead;
  tail = newTail;
  other.head = nullptr;
  other.tail = nullptr;
  size += other.size;
  other.size = 0;
}

template <typename T>
void s21::list<T>::splice(const_iterator pos, list& other) {
  if (!other.empty()) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      insert(pos, *it);
    }
  }
  other.clear();
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  Node<T>* new_node = new Node<T>(value);
  if (new_node == nullptr) throw std::bad_alloc();

  Node<T>* curr = head;
  Node<T>* prev = nullptr;

  while (curr && curr != pos.current) {
    prev = curr;
    curr = curr->next;
  }

  new_node->next = curr;
  if (prev) {
    prev->next = new_node;
  } else {
    head = new_node;
  }

  if (curr == head) {
    head = new_node;
  }

  size++;

  return iterator(new_node);
}

template <typename T>
template <typename... Args>
void s21::list<T>::insert_many_back(Args&&... args) {
  for (const auto& item : {args...}) {
    push_back(item);
  }
}

template <typename T>
template <typename... Args>
void s21::list<T>::insert_many_front(Args&&... args) {
  for (const auto& item : {args...}) {
    push_front(item);
  }
}

template <typename T>
template <typename... Args>
typename s21::list<T>::iterator s21::list<T>::insert_many(const_iterator pos,
                                                          Args&&... args) {
  for (const auto& item : {args...}) {
    insert(pos, item);
  }
  return pos;
}

#endif