// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"

int main() {
  std::vector<char> symbols = {'1', '2', '3', '4'};
  PMTree tree(symbols);

  auto allPerms = tree.getAllPerms();
  std::cout << "All permutations (" << allPerms.size() << "):\n";
  for (size_t i = 0; i < allPerms.size(); ++i) {
    std::cout << (i+1) << ": ";
    for (char c : allPerms[i]) std::cout << c;
    std::cout << "\n";
  }

  const int testIndex = 5;
  auto perm1 = tree.getPerm1(testIndex);
  auto perm2 = tree.getPerm2(testIndex);

  std::cout << "\nPermutation #" << testIndex << ":\n";
  std::cout << "Method 1: ";
  for (char c : perm1) std::cout << c;
  std::cout << "\nMethod 2: ";
  for (char c : perm2) std::cout << c;
  std::cout << "\n";

  return 0;
}
