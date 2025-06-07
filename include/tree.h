// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>
#include <algorithm>

struct PermNode {
    char value;
    std::vector<std::unique_ptr<PermNode>> children;
    explicit PermNode(char v) : value(v) {}
};

class PermutationTree {
public:
    explicit PermutationTree(const std::vector<char>& elements);
    ~PermutationTree() = default;

    std::vector<std::vector<char>> generateAllPermutations() const;
    std::vector<char> getPermutationByIndexSlow(int index) const;
    std::vector<char> getPermutationByIndexFast(int index) const;

private:
    std::unique_ptr<PermNode> root;
    void buildTree(PermNode* node, std::vector<char> remaining);
    void collectPermutations(const PermNode* node, 
                           std::vector<char>& current, 
                           std::vector<std::vector<char>>& result) const;
    int factorial(int n) const;
};

#endif  // INCLUDE_TREE_H_
