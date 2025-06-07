// Copyright 2022 NNTU-CS
#include "tree.h"
#include <stdexcept>

PermutationTree::PermutationTree(const std::vector<char>& elements) {
    if (elements.empty()) {
        root = nullptr;
        return;
    }
    
    root = std::make_unique<PermNode>('\0');  // Dummy root node
    std::vector<char> sorted = elements;
    std::sort(sorted.begin(), sorted.end());
    buildTree(root.get(), sorted);
}

void PermutationTree::buildTree(PermNode* node, std::vector<char> remaining) {
    for (size_t i = 0; i < remaining.size(); ++i) {
        auto child = std::make_unique<PermNode>(remaining[i]);
        std::vector<char> newRemaining = remaining;
        newRemaining.erase(newRemaining.begin() + i);
        buildTree(child.get(), newRemaining);
        node->children.push_back(std::move(child));
    }
}

std::vector<std::vector<char>> PermutationTree::generateAllPermutations() const {
    std::vector<std::vector<char>> result;
    if (!root) return result;
    
    std::vector<char> current;
    for (const auto& child : root->children) {
        collectPermutations(child.get(), current, result);
    }
    return result;
}

void PermutationTree::collectPermutations(const PermNode* node,
                                        std::vector<char>& current,
                                        std::vector<std::vector<char>>& result) const {
    current.push_back(node->value);
    
    if (node->children.empty()) {
        result.push_back(current);
    } else {
        for (const auto& child : node->children) {
            collectPermutations(child.get(), current, result);
        }
    }
    
    current.pop_back();
}

std::vector<char> PermutationTree::getPermutationByIndexSlow(int index) const {
    auto all = generateAllPermutations();
    if (index <= 0 || index > static_cast<int>(all.size())) {
        return {};
    }
    return all[index - 1];
}

std::vector<char> PermutationTree::getPermutationByIndexFast(int index) const {
    if (!root || index <= 0) return {};
    
    std::vector<char> elements;
    for (const auto& child : root->children) {
        elements.push_back(child->value);
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

int PermutationTree::factorial(int n) const {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
