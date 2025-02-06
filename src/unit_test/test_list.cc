#include <gtest/gtest.h>

#include <list>

#include "test.h"

TEST(testPushBack, PushBack_1) {
  s21::list<int> my_list;
  my_list.push_back(42);
  my_list.push_back(17);
  my_list.push_back(89);
  my_list.push_back(123);
  my_list.push_back(55);
  my_list.push_back(72);
  my_list.push_back(33);

  EXPECT_EQ(my_list.list_size(), 7);
  EXPECT_EQ(my_list.empty(), false);
}

TEST(testPushBack, PushBack) {
  s21::list<int> my_list;
  std::list<int> std_list;

  for (int i = 0; i < 100; ++i) {
    my_list.push_back(i);
    std_list.push_back(i);
  }

  EXPECT_EQ(my_list.list_size(), std_list.size());

  auto my_it = my_list.begin();
  auto std_it = std_list.begin();

  while (my_it != my_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*my_it, *std_it);
    ++my_it;
    ++std_it;
  }
}

TEST(testPopBack, PopBack) {
  s21::list<int> my_list = {1, 2, 3};
  my_list.pop_back();

  EXPECT_EQ(my_list.list_size(), 2);

  my_list.pop_back();
  my_list.pop_back();

  EXPECT_EQ(my_list.list_size(), 0);
  EXPECT_EQ(my_list.empty(), true);
}

TEST(testPushFront, PushFront) {
  s21::list<int> my_list;
  my_list.push_front(100);
  my_list.push_front(200);
  my_list.push_front(300);

  EXPECT_EQ(my_list.list_size(), 3);
  EXPECT_EQ(my_list.empty(), false);
}

TEST(testClear, Clear) {
  s21::list<int> my_list;
  std::list<int> std_list;

  for (int i = 0; i < 100; ++i) {
    my_list.push_back(i);
    std_list.push_back(i);
  }

  EXPECT_EQ(my_list.list_size(), std_list.size());

  my_list.clear();
  std_list.clear();

  EXPECT_EQ(my_list.list_size(), std_list.size());
}

TEST(testSort, Sort) {
  s21::list<int> my_list = {3, 5, 1, 9, 8, 21, 1};
  std::list<int> sort_list = {3, 5, 1, 9, 8, 21, 1};

  my_list.sort();
  sort_list.sort();

  EXPECT_EQ(my_list.list_size(), sort_list.size());

  auto my_it = my_list.begin();
  auto std_it = sort_list.begin();

  while (my_it != my_list.end() && std_it != sort_list.end()) {
    EXPECT_EQ(*my_it, *std_it);
    ++my_it;
    ++std_it;
  }
}

TEST(testSort, SortSimple) {
  s21::list<int> myList = {42, 21};
  myList.sort();
  EXPECT_EQ(myList.front(), 21);
  EXPECT_EQ(myList.back(), 42);
}

TEST(testSort, SortSortedList) {
  s21::list<int> myList = {1, 2, 3, 4, 5};
  myList.sort();
  EXPECT_EQ(myList.front(), 1);
  EXPECT_EQ(myList.back(), 5);
}

TEST(testSort, SortReverseSortedList) {
  s21::list<int> myList = {5, 4, 3, 2, 1};
  myList.sort();
  EXPECT_EQ(myList.front(), 1);
  EXPECT_EQ(myList.back(), 5);
}

TEST(testSwap, Swap) {
  s21::list<int> list_1 = {12, 4, 21, 0, 3};
  s21::list<int> list_2 = {2, 421, 121, 42, 13};

  std::list<int> swap_1 = {2, 421, 121, 42, 13};
  std::list<int> swap_2 = {12, 4, 21, 0, 3};

  list_1.swap(list_2);

  auto my_it = list_1.begin();
  auto std_it = swap_1.begin();

  while (my_it != list_1.end() && std_it != swap_1.end()) {
    EXPECT_EQ(*my_it, *std_it);
    ++my_it;
    ++std_it;
  }

  auto my_it_2 = list_2.begin();
  auto std_it_2 = swap_2.begin();

  while (my_it_2 != list_2.end() && std_it_2 != swap_2.end()) {
    EXPECT_EQ(*my_it_2, *std_it_2);
    ++my_it_2;
    ++std_it_2;
  }
}

TEST(testUnique, unique_1) {
  s21::list<int> s21_list_2 = {1, 2, 2, 2, 3, 4, 4, 4, 5, 5};
  std::list<int> List = {1, 2, 2, 2, 3, 4, 4, 4, 5, 5};
  s21_list_2.unique();

  List.unique();

  auto it = s21_list_2.begin();

  for (auto itStd = List.begin(); itStd != List.end(); ++itStd) {
    EXPECT_EQ(*it, *itStd);
    ++it;
  }
}

TEST(testUnique, uniqueNon) {
  s21::list<int> my_list = {1, 2, 3, 4, 5};
  my_list.unique();

  EXPECT_EQ(my_list.list_size(), 5);
}

TEST(testUnique, unique_3) {
  s21::list<int> my_list = {1, 2, 2, 1, 3, 4, 4, 4};
  s21::list<int> list = {1, 2, 2, 1, 3, 4, 4, 4};
  my_list.unique();
  list.unique();

  EXPECT_EQ(my_list.list_size(), list.list_size());
}

TEST(testUnique, uniqueEmpty) {
  s21::list<int> my_list = {};
  my_list.unique();

  EXPECT_EQ(my_list.list_size(), 0);
}

TEST(testMerge, MergeTwoListsOne) {
  s21::list<int> list1 = {2, 4, 6};
  s21::list<int> list2 = {1, 3, 5};
  std::list<int> list3 = {1, 2, 3, 4, 5, 6};
  list1.merge(list2);

  auto my_it_2 = list1.begin();
  auto std_it_2 = list3.begin();

  while (my_it_2 != list1.end() && std_it_2 != list3.end()) {
    EXPECT_EQ(*my_it_2, *std_it_2);
    ++my_it_2;
    ++std_it_2;
  }

  EXPECT_EQ(list1.list_size(), 6);
}

TEST(testMerge, MergeTwoListsTwo) {
  s21::list<int> list1 = {2, 4, 6};
  s21::list<int> list2 = {3, 9, 12};
  std::list<int> list3 = {2, 3, 4, 6, 9, 12};
  list1.merge(list2);

  auto my_it_2 = list1.begin();
  auto std_it_2 = list3.begin();

  while (my_it_2 != list1.end() && std_it_2 != list3.end()) {
    EXPECT_EQ(*my_it_2, *std_it_2);
    ++my_it_2;
    ++std_it_2;
  }

  EXPECT_EQ(list1.list_size(), 6);
}

TEST(testMerge, MergeTwoEmptyLists) {
  s21::list<int> list1;
  s21::list<int> list2;
  list1.merge(list2);

  EXPECT_EQ(list1.list_size(), 0);
  EXPECT_EQ(list2.list_size(), 0);
}

TEST(testReverse, reverse) {
  s21::list<int> list1 = {1, 2, 3, 4, 5, 6};

  list1.reverse();

  EXPECT_EQ(list1.front(), 6);
  EXPECT_EQ(list1.back(), 1);
}

TEST(testReverse, reverseOne) {
  s21::list<int> list1 = {1};

  list1.reverse();

  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 1);
}

TEST(testPopFront, pop_Front) {
  s21::list<int> s21_list = {0};
  s21_list.push_front(7);
  s21_list.push_front(123);
  s21_list.push_front(88);
  s21_list.pop_front();
  int i = 3;
  EXPECT_EQ(i, s21_list.list_size());
}

TEST(testErase, Erase) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5, 6, 7};
  auto i = s21_list.begin();

  i += 2;

  s21_list.erase(i);

  EXPECT_EQ(6, s21_list.list_size());
}

TEST(testErase, Erase_2) {
  s21::list<int> my_list = {1, 2, 3, 4, 5};
  auto it = my_list.begin();
  ++it;

  EXPECT_NO_THROW(my_list.erase(it));
  EXPECT_EQ(my_list.list_size(), 4);

  int expected_values[] = {1, 3, 4, 5};
  int index = 0;
  for (auto& elem : my_list) {
    EXPECT_EQ(elem, expected_values[index++]);
  }
}

TEST(testErase, SingleElementList) {
  s21::list<int> my_list = {42};
  auto it = my_list.begin();

  EXPECT_NO_THROW(my_list.erase(it));
  EXPECT_EQ(my_list.list_size(), 0);
}

TEST(testListSize, listSize) {
  s21::list<int> my_list = {};

  for (int i = 0; i < 100; ++i) {
    my_list.push_back(i);
  }

  EXPECT_EQ(my_list.list_size(), 100);
}

TEST(testEmpty, EmptyFalse) {
  s21::list<int> s21_list = {1, 2, 3};
  int res = s21_list.empty();
  ASSERT_EQ(0, res);
}

TEST(testEmpty, EmptyTrue) {
  s21::list<int> s21_list = {1, 2, 3};
  int res = s21_list.empty();
  ASSERT_EQ(1, !res);
}

TEST(ListOperatorAssignmentTest, MoveAssignment) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {4, 5, 6};

  list1 = std::move(list2);

  EXPECT_EQ(list1.list_size(), 3);
  EXPECT_EQ(list1.front(), 4);
  EXPECT_EQ(list1.back(), 6);

  EXPECT_EQ(list2.list_size(), 0);
  EXPECT_TRUE(list2.empty());
}

TEST(ListTest, FrontBackBeginEnd) {
  s21::list<int> myList = {1, 2, 3};

  EXPECT_EQ(myList.front(), 1);

  EXPECT_EQ(myList.back(), 3);

  auto it = myList.begin();
  EXPECT_NE(it, myList.end());

  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(it, myList.end());
}

TEST(List, Constructor_Copy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(our_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Constructor_List) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constructor_Default) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Size) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.list_size(), std_list.size());
}

TEST(ListMoveConstructorTest, MoveConstructor) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = std::move(list1);

  EXPECT_EQ(list2.list_size(), 3);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 3);

  EXPECT_TRUE(list1.empty());
}

TEST(TestList, InsertManyOnce) {
  s21::list<int> l({1, 2, 3});

  auto pos = l.begin();
  ++pos;
  pos = l.insert(pos, 4);

  EXPECT_EQ(4, *pos);

  EXPECT_EQ(4, l.list_size());

  int arr[] = {1, 4, 2, 3};
  size_t i = 0;
  for (auto iter = l.begin(); iter != l.end(); ++iter, ++i) {
    EXPECT_EQ(arr[i], *iter);
  }
}

TEST(tests_of_List, Insert) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> List = {1, 2, 3, 4, 5};
  auto it_1 = s21_list.begin();
  auto it_std = List.begin();

  auto it_2 = s21_list.insert(it_1, 0);
  auto it_std_2 = List.insert(it_std, 0);

  ASSERT_EQ(*it_std_2, *it_2);

  it_1 += 3;
  for (size_t i = 0; i < 3; i++) {
    it_std++;
  }

  it_2 = s21_list.insert(it_1, 6);
  it_std_2 = List.insert(it_std, 6);
  ASSERT_EQ(*it_std_2, *it_2);

  it_1 = s21_list.end();
  it_std = List.end();
  it_2 = s21_list.insert(it_1, 7);
  it_std_2 = List.insert(it_std, 7);
  ASSERT_EQ(*it_std_2, *it_2);
}

TEST(SpliceTest, EmptyList) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2;

  auto pos = list1.cbegin();
  list1.splice(pos, list2);

  EXPECT_TRUE(list1.list_size() == 3);
  EXPECT_TRUE(list2.list_size() == 0);
}

TEST(SpliceTest, SpliceNonEmptyLists) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {10, 20, 30};

  auto pos = list1.cbegin();
  list1.splice(pos, list2);

  EXPECT_TRUE(list1.list_size() == 6);
  EXPECT_TRUE(list2.list_size() == 0);
}

TEST(SpliceTest, SpliceOne) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {10, 20, 30};

  std::list<int> list3 = {1, 2, 3};
  std::list<int> list4 = {10, 20, 30};

  auto pos = list1.cbegin();
  list1.splice(pos, list2);

  auto pos_2 = list3.cbegin();
  list3.splice(pos_2, list4);

  auto it1 = list1.begin();
  auto it3 = list3.begin();
  for (; it1 != list1.end(); ++it1, ++it3) {
    EXPECT_EQ(*it1, *it3);
  }
}

TEST(SpliceTest, SpliceTwo) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {10, 20, 30};

  std::list<int> list3 = {1, 2, 3};
  std::list<int> list4 = {10, 20, 30};

  auto pos = list1.cbegin();
  ++pos;
  list1.splice(pos, list2);

  auto pos_2 = list3.cbegin();
  ++pos_2;
  list3.splice(pos_2, list4);

  auto it1 = list1.begin();
  auto it3 = list3.begin();
  for (; it1 != list1.end(); ++it1, ++it3) {
    EXPECT_EQ(*it1, *it3);
  }
}

TEST(SpliceTest, SpliceBackFron) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  auto our_it = our_list_first.cbegin();
  auto std_it = std_list_first.cbegin();
  our_list_first.splice(our_it, our_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
}

TEST(IteratorTests, IncrementOperator) {
  Node<int> node1(5);
  Node<int> node2(10);
  node1.next = &node2;
  node2.prev = &node1;
  s21::list<int>::iterator it(&node1);

  ++it;
  EXPECT_EQ(it.current->val, 10);
}

TEST(IteratorTests, DecrementOperator) {
  Node<int> node1(5);
  Node<int> node2(10);
  node1.next = &node2;
  node2.prev = &node1;
  s21::list<int>::iterator it(&node2);

  --it;
  EXPECT_EQ(it.current->val, 5);
}

TEST(IteratorTests, CompoundAssignmentOperator) {
  Node<int> node1(5);
  Node<int> node2(10);
  node1.next = &node2;
  node2.prev = &node1;
  s21::list<int>::iterator it(&node1);

  it += 1;
  EXPECT_EQ(it.current->val, 10);
}

TEST(List, Insert_Many) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::const_iterator our_it = our_list.cbegin();
  ++our_it;
  our_list.insert_many(our_it, 7, 8, 9);
  our_it = our_list.cbegin();
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

TEST(testInsertManyFront, InsertManyFront) {
  s21::list<int> my_list;

  my_list.insert_many_front(5, 4, 3, 2, 1);

  EXPECT_EQ(my_list.list_size(), 5);

  EXPECT_EQ(my_list.front(), 1);
  EXPECT_EQ(my_list.back(), 5);
}

TEST(testInsertManyBack, InsertManyBack) {
  s21::list<int> my_list;

  my_list.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(my_list.list_size(), 5);
  EXPECT_EQ(my_list.front(), 1);
  EXPECT_EQ(my_list.back(), 5);
}

TEST(testInsertMany, InsertMany) {
  s21::list<int> my_list = {1, 2, 3, 7};

  auto it = my_list.cbegin();
  ++it;
  my_list.insert_many(it, 4, 5, 6);

  int expected[] = {1, 4, 5, 6, 2, 3, 7};

  int i = 0;
  for (const auto& item : my_list) {
    EXPECT_EQ(item, expected[i]);
    ++i;
  }
  EXPECT_EQ(my_list.list_size(), 7);
}