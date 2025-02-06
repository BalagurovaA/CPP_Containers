#include <map>

#include "test.h"

/*----------------------------------------------------------------*/
/*-------------------------- CREATE MAP --------------------------*/
/*----------------------------------------------------------------*/

TEST(CreateMap, CreateMap1) {
  s21::map<int, int> mymap;
  std::map<int, int> stdmap;

  ASSERT_TRUE(mymap.empty() == stdmap.empty());
}

TEST(CreateMap, CreateMap2) {
  s21::map<int, int> mymap{{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap{{1, 1}, {2, 2}, {3, 3}};

  ASSERT_TRUE(mymap.empty() == stdmap.empty());

  auto myIt = mymap.begin();
  auto stdIt = stdmap.begin();

  for (; myIt != mymap.end() || stdIt != stdmap.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMap, CreateMap3) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  s21::map<int, int> mymap2(mymap1);
  std::map<int, int> stdmap2(stdmap1);

  auto myIt = mymap2.begin();
  auto stdIt = stdmap2.begin();

  ASSERT_TRUE(mymap2.empty() == stdmap2.empty());

  for (; myIt != mymap2.end() || stdIt != stdmap2.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMap, CreateMap4) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  s21::map<int, int> mymap2(std::move(mymap1));
  std::map<int, int> stdmap2(std::move(stdmap1));

  auto myIt = mymap2.begin();
  auto stdIt = stdmap2.begin();

  ASSERT_TRUE(mymap2.empty() == stdmap2.empty());

  for (; myIt != mymap2.end() || stdIt != stdmap2.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(CreateMap, CreateMap5) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  s21::map<int, int> mymap2 = std::move(mymap1);
  std::map<int, int> stdmap2 = std::move(stdmap1);

  auto myIt = mymap2.begin();
  auto stdIt = stdmap2.begin();

  ASSERT_TRUE(mymap2.empty() == stdmap2.empty());

  for (; myIt != mymap2.end() || stdIt != stdmap2.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

/*----------------------------------------------------------------*/
/*------------------------- CAPACITY MAP -------------------------*/
/*----------------------------------------------------------------*/

TEST(CapacityMap, CapacityMap1) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  ASSERT_EQ(mymap1.empty(), stdmap1.empty());
}

TEST(CapacityMap, CapacityMap2) {
  s21::map<int, int> mymap1;
  std::map<int, int> stdmap1;

  ASSERT_EQ(mymap1.empty(), stdmap1.empty());
}

TEST(CapacityMap, CapacityMap3) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  ASSERT_EQ(mymap1.size(), stdmap1.size());
}

TEST(CapacityMap, CapacityMap4) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  ASSERT_EQ(mymap1.max_size(), stdmap1.max_size());
}

/*----------------------------------------------------------------*/
/*------------------------- MODIFIERS MAP ------------------------*/
/*----------------------------------------------------------------*/

TEST(ModifiersMap, ModifiersMap1) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  mymap1.clear();
  stdmap1.clear();

  ASSERT_EQ(mymap1.empty(), stdmap1.empty());
}

TEST(ModifiersMap, ModifiersMap2) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  mymap1.clear();
  stdmap1.clear();

  ASSERT_EQ(mymap1.empty(), stdmap1.empty());
}

TEST(ModifiersMap, ModifiersMap3) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  mymap1.insert(s21::map<int, int>::value_type(6, 6));
  stdmap1.insert(std::map<int, int>::value_type(6, 6));

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap4) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  mymap1.insert_or_assign(4, 7);
  stdmap1.insert_or_assign(4, 7);

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap5) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};

  mymap1.erase(mymap1.begin());
  stdmap1.erase(stdmap1.begin());

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap6) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int>::iterator myIt;

  EXPECT_THROW(mymap1.erase(myIt), std::invalid_argument);
}

TEST(ModifiersMap, ModifiersMap7) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> mymap2{{5, 5}, {9, 9}, {10, 10}};

  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap2{{5, 5}, {9, 9}, {10, 10}};

  mymap1.swap(mymap2);
  stdmap1.swap(stdmap2);

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
  myIt = mymap2.begin();
  stdIt = stdmap2.begin();

  for (; myIt != mymap2.end() || stdIt != stdmap2.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap8) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> mymap2{{5, 5}, {9, 9}, {10, 10}};

  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> stdmap2{{5, 5}, {9, 9}, {10, 10}};

  mymap1.merge(mymap2);
  stdmap1.merge(stdmap2);

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }

  ASSERT_EQ(mymap2.empty(), stdmap2.empty());
}

TEST(ModifiersMap, ModifiersMap9) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};
  s21::map<int, int> mymap2{{5, 5}, {2, 2}, {10, 10}};

  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};
  std::map<int, int> stdmap2{{5, 5}, {2, 2}, {10, 10}};

  mymap1.merge(mymap2);
  stdmap1.merge(stdmap2);

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }

  myIt = mymap2.begin();
  stdIt = stdmap2.begin();

  for (; myIt != mymap2.end() || stdIt != stdmap2.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap10) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}};

  mymap1.insert_or_assign(4, 100);
  stdmap1.insert_or_assign(4, 100);

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (; myIt != mymap1.end() || stdIt != stdmap1.end();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
    ++myIt;
    ++stdIt;
  }
}

TEST(ModifiersMap, ModifiersMap11) {
  s21::map<int, int> map1;
  s21::map<int, int> map2;

  s21::vector<std::pair<typename s21::map<int, int>::iterator, bool>> res1;

  res1.push_back(map1.insert({3, 3}));
  res1.push_back(map1.insert({4, 4}));
  res1.push_back(map1.insert({4, 4}));
  res1.push_back(map1.insert({6, 6}));

  using value_type = s21::map<int, int>::value_type;
  auto res2 = map2.insert_many(value_type(3, 3), value_type(4, 4),
                               value_type(4, 4), value_type(6, 6));

  auto it1 = res1.begin();
  auto it2 = res2.begin();

  for (; it2 != res2.end();) {
    ASSERT_EQ(it2->first->first, it1->first->first);
    ASSERT_EQ(it2->first->second, it1->first->second);
    ASSERT_EQ(it2->second, it1->second);

    ++it1;
    ++it2;
  }
}

/*----------------------------------------------------------------*/
/*-------------------------- LOOKUP MAP --------------------------*/
/*----------------------------------------------------------------*/

TEST(LookupMap, LookupMap1) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}, {1, 1}};

  ASSERT_EQ(mymap1.contains(-3), true);
}

TEST(MLookupMap, LookupMap2) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}, {1, 1}};

  ASSERT_EQ(mymap1.contains(100), false);
}

/*----------------------------------------------------------------*/
/*---------------------- ELEMENT ACCESS MAP ----------------------*/
/*----------------------------------------------------------------*/

TEST(ElementAccessMap, ElementAccessMap1) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}};

  ASSERT_EQ(mymap1.at(4), stdmap1.at(4));
}

TEST(ElementAccessMap, ElementAccessMap2) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {100, 100}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {100, 100}};

  ASSERT_EQ(mymap1[1], stdmap1[1]);
}

/*----------------------------------------------------------------*/
/*------------------------- ITERATOR MAP -------------------------*/
/*----------------------------------------------------------------*/

TEST(IteratorMap, IteratorMap1) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (int i = 0; i < 4; i++) {
    ++myIt;
    ++stdIt;

    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
  }

  for (int i = 0; i < 4; i++) {
    --myIt;
    --stdIt;

    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
  }
}

TEST(IteratorMap, IteratorMap2) {
  s21::map<int, int> mymap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};
  std::map<int, int> stdmap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  for (int i = 0; i < 3; i++) {
    ++myIt;
    ++stdIt;

    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
  }

  for (int i = 0; i < 3; i++) {
    --myIt;
    --stdIt;

    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);
  }
}

TEST(IteratorMap, IteratorMap3) {
  s21::map<int, int> mymap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};
  std::map<int, int> stdmap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  auto myIt2 = mymap1.begin();
  auto stdIt2 = stdmap1.begin();

  ASSERT_EQ(myIt == myIt2, stdIt == stdIt2);
}

TEST(IteratorMap, IteratorMap4) {
  s21::map<int, int> mymap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};
  std::map<int, int> stdmap1{{7, 7}, {1, 1}, {9, 9}, {8, 8}};

  auto myIt = mymap1.begin();
  auto stdIt = stdmap1.begin();

  ++myIt;
  ++stdIt;

  auto myIt2 = mymap1.begin();
  auto stdIt2 = stdmap1.begin();

  ASSERT_EQ(myIt != myIt2, stdIt != stdIt2);
}

TEST(IteratorMap, IteratorMap5) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};
  s21::map<int, int>::iterator myIt;

  ++myIt;
  ASSERT_EQ(myIt.GetStartNode(), nullptr);

  --myIt;
  ASSERT_EQ(myIt.GetStartNode(), nullptr);
}

TEST(IteratorMap, IteratorMap6) {
  s21::map<int, int> mymap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};
  std::map<int, int> stdmap1{{4, 4}, {1, 1}, {2, 2}, {-1, -1}, {-3, -3}};

  auto myIt = mymap1.cbegin();
  auto stdIt = stdmap1.cbegin();

  for (; myIt != mymap1.cend();) {
    ASSERT_EQ(myIt->first, stdIt->first);
    ASSERT_EQ(myIt->second, stdIt->second);

    ++myIt;
    ++stdIt;
  }
}