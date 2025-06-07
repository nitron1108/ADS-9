// Copyright 2022 NNTU-CS
#include <algorithm>
#include <memory>
#include <utility>
#include <vector>
#include "tree.h"

int PMTree::factorial(int n) const {
  return (n <= 1) ? 1 : n * factorial(n - 1);
}

PMTree::PMTree(const std::vector<char>& symbols) {
  if (symbols.empty()) return;
  root = std::make_unique<Node>('\0');
  std::vector<char> sorted = symbols;
  std::sort(sorted.begin(), sorted.end());
  build(root.get(), sorted);
}

void PMTree::build(Node* node, std::vector<char> symbols) {
  for (size_t i = 0; i < symbols.size(); ++i) {
    auto child = std::make_unique<Node>(symbols[i]);
    std::vector<char> newSymbols = symbols;
    newSymbols.erase(newSymbols.begin() + i);
    build(child.get(), newSymbols);
    node->children.push_back(std::move(child));
  }
}

std::vector<std::vector<char>> PMTree::getAllPerms() const {
  std::vector<std::vector<char>> result;
  if (!root) return result;

  std::vector<char> current;
  for (const auto& child : root->children) {
    collectPermutations(child.get(), current, result);
  }
  return result;
}

void PMTree::collectPermutations(const Node* node,
                               std::vector<char>& current,
                               std::vector<std::vector<char>>& result) const {
  current.push_back(node->val);

  if (node->children.empty()) {
    result.push_back(current);
  } else {
    for (const auto& child : node->children) {
      collectPermutations(child.get(), current, result);
    }
  }

  current.pop_back();
}

std::vector<char> PMTree::getPerm1(int index) const {
  auto all = getAllPerms();
  if (index <= 0 || index > static_cast<int>(all.size())) {
    return {};
  }
  return all[index - 1];
}

std::vector<char> PMTree::getPerm2(int index) const {
  if (!root || index <= 0) return {};

  std::vector<char> elements;
  for (const auto& child : root->children) {
    elements.push_back(child->val);
  }

  const int n = elements.size();
  const int total = factorial(n);
  if (index > total) return {};

  std::vector<char> result;
  int remaining = index - 1;
  std::vector<char> available = elements;

  for (int i = n; i >= 1; --i) {
    const int fact = factorial(i - 1);
    const int pos = remaining / fact;
    remaining %= fact;

    result.push_back(available[pos]);
    available.erase(available.begin() + pos);
  }

  return result;
}
