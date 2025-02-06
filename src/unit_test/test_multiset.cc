#include <set>

#include "test.h"

/*----------------------------------------------------------------*/
/*----------------------- CREATE MULTISET ------------------------*/
/*----------------------------------------------------------------*/

TEST(CreateMultiset, CreateMultiset1) {
  s21::multiset<int> myset;
  std::multiset<int> stdset;

  ASSERT_TRUE(myset.empty() == stdset.empty());
}

TEST(CreateMultiset, CreateMultiset2) {
  s21::multiset<int> myset{1, 3, 6, 9, 1};
  std::multiset<int> stdset{1, 3, 6, 9, 1};

  ASSERT_TRUE(myset.empty() == stdset.empty());

  auto myIt = myset.begin();
  auto stdIt = stdset.begin();

  for (; myIt != myset.end() || stdIt != stdset.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMultiset, CreateMultiset3) {
  s21::multiset<int> myset1{1, 3, 6, 9, 1, 36, 1, -3, 3};
  std::multiset<int> stdset1{1, 3, 6, 9, 1, 36, 1, -3, 3};
  s21::multiset<int> myset2(myset1);
  std::multiset<int> stdset2(stdset1);

  auto myIt = myset2.begin();
  auto stdIt = stdset2.begin();

  ASSERT_TRUE(myset2.empty() == stdset2.empty());

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMultiset, CreateMultiset4) {
  s21::multiset<int> myset1{1, 3, 6, 9, 1, 36, 1, -3, 3};
  std::multiset<int> stdset1{1, 3, 6, 9, 1, 36, 1, -3, 3};

  s21::multiset<int> myset2(std::move(myset1));
  std::multiset<int> stdset2(std::move(stdset1));

  auto myIt = myset2.begin();
  auto stdIt = stdset2.begin();

  ASSERT_TRUE(myset2.empty() == stdset2.empty());

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMultiset, CreateMultiset5) {
  s21::multiset<int> myset1{1, 3, 6, 9, 1, 36, 1, -3, 3};
  std::multiset<int> stdset1{1, 3, 6, 9, 1, 36, 1, -3, 3};
  s21::multiset<int> myset2 = std::move(myset1);
  std::multiset<int> stdset2 = std::move(stdset1);

  auto myIt = myset2.begin();
  auto stdIt = stdset2.begin();

  ASSERT_TRUE(myset2.empty() == stdset2.empty());

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

/*----------------------------------------------------------------*/
/*----------------------- CAPACITY MULTISET ----------------------*/
/*----------------------------------------------------------------*/

TEST(CapacityMultiset, CapacityMultiset1) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(CapacityMultiset, CapacityMultiset2) {
  s21::multiset<int> myset1;
  std::multiset<int> stdset1;
  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(CapacityMultiset, CapacityMultiset3) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.size(), stdset1.size());
}

TEST(CapacityMultiset, CapacityMultiset4) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.max_size(), stdset1.max_size());
}

/*----------------------------------------------------------------*/
/*----------------------- MODIFIERS MULTISET ---------------------*/
/*----------------------------------------------------------------*/

TEST(ModifiersMultiset, ModifiersMultiset1) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};

  myset1.clear();
  stdset1.clear();

  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(ModifiersMultiset, ModifiersMultiset2) {
  s21::multiset<int> myset1;
  std::multiset<int> stdset1;

  myset1.clear();
  stdset1.clear();

  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(ModifiersMultiset, ModifiersMultiset3) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};

  myset1.insert(s21::multiset<int>::value_type(23));
  stdset1.insert(std::multiset<int>::value_type(23));

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMultiset, ModifiersMultiset4) {
  s21::multiset<int> myset1{15, 10, 11, 18, 23, 17, 16, 15, -10, -20};
  std::multiset<int> stdset1{15, 10, 11, 18, 23, 17, 16, 15, -10, -20};

  myset1.erase(myset1.begin());
  stdset1.erase(stdset1.begin());

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMultiset, ModifiersMultiset5) {
  s21::multiset<int> myset1{4, 1, 2, 3};
  s21::multiset<int> myset2{5, 9, 10};

  std::multiset<int> stdset1{4, 1, 2, 3};
  std::multiset<int> stdset2{5, 9, 10};

  myset1.swap(myset2);
  stdset1.swap(stdset2);

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
  myIt = myset2.begin();
  stdIt = stdset2.begin();

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMultiset, ModifiersMultiset6) {
  s21::multiset<int> myset1{4, 1, 2, 3};
  s21::multiset<int> myset2{5, 9, 2};

  std::multiset<int> stdset1{4, 1, 2, 3};
  std::multiset<int> stdset2{5, 9, 2};

  myset1.merge(myset2);
  stdset1.merge(stdset2);

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }

  ASSERT_EQ(myset2.empty(), stdset2.empty());
}

TEST(ModifiersMultiset, ModifiersMultiset7) {
  s21::multiset<int> set1;
  s21::multiset<int> set2;

  s21::vector<std::pair<typename s21::multiset<int>::iterator, bool>> res1;

  res1.push_back(std::make_pair(set1.insert(3), true));
  res1.push_back(std::make_pair(set1.insert(4), true));
  res1.push_back(std::make_pair(set1.insert(4), true));
  res1.push_back(std::make_pair(set1.insert(6), true));

  auto res2 = set2.insert_many(3, 4, 4, 6);

  auto it1 = res1.begin();
  auto it2 = res2.begin();

  for (; it2 != res2.end();) {
    ASSERT_EQ(*(it2->first), *(it1->first));
    ASSERT_EQ(it2->second, it1->second);
    ++it1;
    ++it2;
  }
}

/*----------------------------------------------------------------*/
/*----------------------- LOOKUP MULTISET ------------------------*/
/*----------------------------------------------------------------*/

TEST(LookupMultiset, LookupMultiset1) {
  s21::multiset<int> myset1{4, 1, -3, 2, -1, -3, -3, -3, 1, -3};
  std::multiset<int> stdset1{4, 1, -3, 2, -1, -3, -3, -3, 1, -3};

  ASSERT_EQ(myset1.count(-3), stdset1.count(-3));
}

TEST(LookupMultiset, LookupMultiset2) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3};
  std::multiset<int> stdset1{4, 1, 2, -1, -3};

  auto myIt = myset1.find(-1);
  auto stdIt = stdset1.find(-1);

  ASSERT_EQ(*myIt, *stdIt);
}

TEST(LookupMultiset, LookupMultiset3) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 100};
  std::multiset<int> stdset1{4, 1, 2, -1, -3, 100};

  auto myIt = myset1.find(100);
  auto stdIt = stdset1.find(100);

  ASSERT_EQ(*myIt, *stdIt);
}

TEST(LookupMultiset, LookupMultiset4) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 1};

  ASSERT_EQ(myset1.contains(-3), true);
}

TEST(LookupMultiset, LookupMultiset5) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 1};

  ASSERT_EQ(myset1.contains(100), false);
}

TEST(LookupMultiset, LookupMultiset6) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 2, 100};
  std::multiset<int> stdset1{4, 1, 2, -1, -3, 2, 100};

  auto myIt = myset1.equal_range(4);
  auto stdIt = stdset1.equal_range(4);

  ASSERT_EQ(*(myIt.first), *(stdIt.first));
  ASSERT_EQ(*(myIt.second), *(stdIt.second));
}

TEST(LookupMultiset, LookupMultiset7) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 2, 100};
  std::multiset<int> stdset1{4, 1, 2, -1, -3, 2, 100};

  auto myIt = myset1.lower_bound(2);
  auto stdIt = stdset1.lower_bound(2);

  ASSERT_EQ(*myIt, *stdIt);
}

TEST(LookupMultiset, LookupMultiset8) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 2, 100};
  std::multiset<int> stdset1{4, 1, 2, -1, -3, 2, 100};

  auto myIt = myset1.upper_bound(2);
  auto stdIt = stdset1.upper_bound(2);

  ASSERT_EQ(*myIt, *stdIt);
  ++myIt;
  ++stdIt;
  ASSERT_EQ(*myIt, *stdIt);
}

/*----------------------------------------------------------------*/
/*---------------------- ITERATOR MULTISET -----------------------*/
/*----------------------------------------------------------------*/

TEST(IteratorMultiset, IteratorMultiset1) {
  s21::multiset<int> myset1{4, 1, 2, -1, -3, 1};
  std::multiset<int> stdset1{4, 1, 2, -1, -3, 1};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (int i = 0; i < 4; i++) {
    ++myIt;
    ++stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }

  for (int i = 0; i < 4; i++) {
    --myIt;
    --stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }
}

TEST(IteratorMultiset, IteratorMultiset2) {
  s21::multiset<int> myset1{7, 1, 9, 9, 9, 8};
  std::multiset<int> stdset1{7, 1, 9, 9, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (int i = 0; i < 5; i++) {
    ++myIt;
    ++stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }

  for (int i = 0; i < 5; i++) {
    --myIt;
    --stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }
}

TEST(IteratorMultiset, IteratorMultiset3) {
  s21::multiset<int> myset1{7, 1, 9, 8};
  std::multiset<int> stdset1{7, 1, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  auto myIt2 = myset1.begin();
  auto stdIt2 = stdset1.begin();

  ASSERT_EQ(myIt == myIt2, stdIt == stdIt2);
}

TEST(IteratorMultiset, IteratorMultiset4) {
  s21::multiset<int> myset1{7, 1, 9, 8};
  std::multiset<int> stdset1{7, 1, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  ++myIt;
  ++stdIt;

  auto myIt2 = myset1.begin();
  auto stdIt2 = stdset1.begin();

  ASSERT_EQ(myIt != myIt2, stdIt != stdIt2);
}