// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>
#include <algorithm>

struct Node {
  char val;
  std::vector<std::unique_ptr<Node>> children;
  explicit Node(char v) : val(v) {}
};

class PMTree {
 public:
  explicit PMTree(const std::vector<char>& symbols);
  ~PMTree() = default;

  std::vector<std::vector<char>> getAllPerms() const;
  std::vector<char> getPerm1(int index) const;
  std::vector<char> getPerm2(int index) const;
  Node* getRoot() const { return root.get(); }

 private:
  std::unique_ptr<Node> root;
  void build(Node* node, std::vector<char> symbols);
  void collectPermutations(const Node* node,
                         std::vector<char>& current,
                         std::vector<std::vector<char>>& result) const;
  int factorial(int n) const;
};

#endif  // INCLUDE_TREE_H_
