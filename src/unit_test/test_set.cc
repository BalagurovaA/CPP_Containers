#include <set>

#include "test.h"

/*----------------------------------------------------------------*/
/*-------------------------- CREATE SET --------------------------*/
/*----------------------------------------------------------------*/

TEST(CreateSet, CreateSet1) {
  s21::set<int> myset;
  std::set<int> stdset;

  ASSERT_TRUE(myset.empty() == stdset.empty());
}

TEST(CreateSet, CreateSet2) {
  s21::set<int> myset{1, 3, 6, 9};
  std::set<int> stdset{1, 3, 6, 9};

  ASSERT_TRUE(myset.empty() == stdset.empty());

  auto myIt = myset.begin();
  auto stdIt = stdset.begin();

  for (; myIt != myset.end() || stdIt != stdset.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateSet, CreateSet3) {
  s21::set<int> myset1{1, 3, 6, 9};
  std::set<int> stdset1{1, 3, 6, 9};

  s21::set<int> myset2(myset1);
  std::set<int> stdset2(stdset1);

  auto myIt = myset2.begin();
  auto stdIt = stdset2.begin();

  ASSERT_TRUE(myset2.empty() == stdset2.empty());

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateSet, CreateSet4) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};

  s21::set<int> myset2(std::move(myset1));
  std::set<int> stdset2(std::move(stdset1));

  auto myIt = myset2.begin();
  auto stdIt = stdset2.begin();

  ASSERT_TRUE(myset2.empty() == stdset2.empty());

  for (; myIt != myset2.end() || stdIt != stdset2.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateSet, CreateSet5) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  s21::set<int> myset2 = std::move(myset1);
  std::set<int> stdset2 = std::move(stdset1);

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
/*------------------------- CAPACITY SET -------------------------*/
/*----------------------------------------------------------------*/

TEST(CapacitySet, CapacitySet1) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(CapacitySet, CapacitySet2) {
  s21::set<int> myset1;
  std::set<int> stdset1;
  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(CapacitySet, CapacitySet3) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.size(), stdset1.size());
}

TEST(CapacitySet, CapacitySet4) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  ASSERT_EQ(myset1.max_size(), stdset1.max_size());
}

/*----------------------------------------------------------------*/
/*------------------------- MODIFIERS SET ------------------------*/
/*----------------------------------------------------------------*/

TEST(ModifiersSet, ModifiersSet1) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};

  myset1.clear();
  stdset1.clear();

  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(ModifiersSet, ModifiersSet2) {
  s21::set<int> myset1;
  std::set<int> stdset1;

  myset1.clear();
  stdset1.clear();

  ASSERT_EQ(myset1.empty(), stdset1.empty());
}

TEST(ModifiersSet, ModifiersSet3) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};

  myset1.insert(s21::set<int>::value_type(6));
  stdset1.insert(std::set<int>::value_type(6));

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersSet, ModifiersSet4) {
  s21::set<int> myset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
  std::set<int> stdset1{15, 10, 11, 18, 23, 17, 16, -10, -20};
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

TEST(ModifiersSet, ModifiersSet5) {
  s21::set<int> myset1{4, 1, 2, 3};
  std::set<int> stdset1{4, 1, 2, 3};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (int i = 0; i < 3; i++) {
    ++myIt;
    ++stdIt;
  }

  myset1.erase(myIt);
  stdset1.erase(stdIt);

  myIt = myset1.begin();
  stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersSet, ModifiersSet6) {
  s21::set<int> myset1{4, 1, 2, 3};
  std::set<int> stdset1{4, 1, 2, 3};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  ++myIt;
  ++stdIt;

  myset1.erase(myIt);
  stdset1.erase(stdIt);

  myIt = myset1.begin();
  stdIt = stdset1.begin();

  for (; myIt != myset1.end() || stdIt != stdset1.end();) {
    ASSERT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersSet, ModifiersSet7) {
  s21::set<int> myset1{4, 1, 2, 3};
  s21::set<int>::iterator myIt;

  EXPECT_THROW(myset1.erase(myIt), std::invalid_argument);
}

TEST(ModifiersSet, ModifiersSet8) {
  s21::set<int> myset1{4, 1, 2, 3};
  s21::set<int> myset2{5, 9, 10};

  std::set<int> stdset1{4, 1, 2, 3};
  std::set<int> stdset2{5, 9, 10};

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

TEST(ModifiersSet, ModifiersSet9) {
  s21::set<int> myset1{4, 1, 2, 3};
  s21::set<int> myset2{5, 9, 10};

  std::set<int> stdset1{4, 1, 2, 3};
  std::set<int> stdset2{5, 9, 10};

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

TEST(ModifiersSet, ModifiersSet10) {
  s21::set<int> myset1{4, 1, 2, -1, -3};
  s21::set<int> myset2{5, 2, 10};

  std::set<int> stdset1{4, 1, 2, -1, -3};
  std::set<int> stdset2{5, 2, 10};

  myset1.merge(myset2);
  stdset1.merge(stdset2);

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

TEST(ModifiersSet, ModifiersSet11) {
  s21::set<int> set1;
  s21::set<int> set2;

  s21::vector<std::pair<typename s21::set<int>::iterator, bool>> res1;

  res1.push_back(set1.insert(3));
  res1.push_back(set1.insert(4));
  res1.push_back(set1.insert(4));
  res1.push_back(set1.insert(6));

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
/*-------------------------- LOOKUP SET --------------------------*/
/*----------------------------------------------------------------*/

TEST(LookupSet, LookupSet1) {
  s21::set<int> myset1{4, 1, 2, -1, -3, 1};

  ASSERT_EQ(myset1.contains(-3), true);
}

TEST(LookupSet, LookupSet2) {
  s21::set<int> myset1{4, 1, 2, -1, -3, 1};

  ASSERT_EQ(myset1.contains(100), false);
}

TEST(LookupSet, LookupSet3) {
  s21::set<int> myset1{4, 1, 2, -1, -3};
  std::set<int> stdset1{4, 1, 2, -1, -3};

  auto myIt = myset1.find(-1);
  auto stdIt = stdset1.find(-1);

  ASSERT_EQ(*myIt, *stdIt);
}

TEST(LookupSet, LookupSet4) {
  s21::set<int> myset1{4, 1, 2, -1, -3, 100};
  std::set<int> stdset1{4, 1, 2, -1, -3, 100};

  auto myIt = myset1.find(100);
  auto stdIt = stdset1.find(100);

  ASSERT_EQ(*myIt, *stdIt);
}

TEST(LookupSet, LookupSet5) {
  s21::set<int> myset1{4, 1, 2, -1, -3, 100};
  auto myIt = myset1.find(-100);

  ASSERT_EQ(myIt.GetStartNode(), nullptr);
}

/*----------------------------------------------------------------*/
/*------------------------- ITERATOR SET -------------------------*/
/*----------------------------------------------------------------*/

TEST(IteratorSet, IteratorSet1) {
  s21::set<int> myset1{4, 1, 2, -1, -3, 1};
  std::set<int> stdset1{4, 1, 2, -1, -3, 1};

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

TEST(IteratorSet, IteratorSet2) {
  s21::set<int> myset1{7, 1, 9, 8};
  std::set<int> stdset1{7, 1, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  for (int i = 0; i < 3; i++) {
    ++myIt;
    ++stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }

  for (int i = 0; i < 3; i++) {
    --myIt;
    --stdIt;

    ASSERT_EQ(*myIt, *stdIt);
  }
}

TEST(IteratorSet, IteratorSet3) {
  s21::set<int> myset1{7, 1, 9, 8};
  std::set<int> stdset1{7, 1, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  auto myIt2 = myset1.begin();
  auto stdIt2 = stdset1.begin();

  ASSERT_EQ(myIt == myIt2, stdIt == stdIt2);
}

TEST(IteratorSet, IteratorSet4) {
  s21::set<int> myset1{7, 1, 9, 8};
  std::set<int> stdset1{7, 1, 9, 8};

  auto myIt = myset1.begin();
  auto stdIt = stdset1.begin();

  ++myIt;
  ++stdIt;

  auto myIt2 = myset1.begin();
  auto stdIt2 = stdset1.begin();

  ASSERT_EQ(myIt != myIt2, stdIt != stdIt2);
}

TEST(IteratorSet, IteratorSet5) {
  s21::set<int> mymap1{4, 1, 2, -1, -3};
  std::set<int> stdmap1{4, 1, 2, -1, -3};

  auto myIt = mymap1.cbegin();
  auto stdIt = stdmap1.cbegin();

  for (; myIt != mymap1.cend();) {
    ASSERT_EQ(*myIt, *stdIt);

    ++myIt;
    ++stdIt;
  }
}