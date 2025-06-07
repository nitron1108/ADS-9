// Copyright 2022 NNTU-CS
#include "tree.h" 
#include <gtest/gtest.h>  
#include <vector> 

TEST(PMTreeTest, GetPerm1Basic) {
  PMTree tree({'1', '2', '3'});
  auto result = tree.getPerm1(1);
  ASSERT_EQ(result, std::vector<char>({'1', '2', '3'}));
}

TEST(PMTreeTest, GetPerm2Basic) {
  PMTree tree({'1', '2', '3'});
  auto result = tree.getPerm2(2);
  ASSERT_EQ(result, std::vector<char>({'1', '3', '2'}));
}

TEST(PMTreeTest, InvalidIndex) {
  PMTree tree({'1', '2', '3'});
  auto result1 = tree.getPerm1(7);
  auto result2 = tree.getPerm2(7);
  ASSERT_TRUE(result1.empty());
  ASSERT_TRUE(result2.empty());
}
