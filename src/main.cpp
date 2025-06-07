// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"

int main() {
    std::vector<char> symbols = {'1', '2', '3', '4'};
    
    try {
        PermutationTree tree(symbols);
        
       
        auto allPerms = tree.generateAllPermutations();
        std::cout << "All permutations (" << allPerms.size() << "):\n";
        for (size_t i = 0; i < allPerms.size(); ++i) {
            std::cout << (i+1) << ": ";
            for (char c : allPerms[i]) {
                std::cout << c;
            }
            std::cout << "\n";
        }
        
        
        const int testIndex = 5;
        auto permSlow = tree.getPermutationByIndexSlow(testIndex);
        auto permFast = tree.getPermutationByIndexFast(testIndex);
        
        std::cout << "\nPermutation #" << testIndex << ":\n";
        std::cout << "Slow method: ";
        for (char c : permSlow) std::cout << c;
        std::cout << "\nFast method: ";
        for (char c : permFast) std::cout << c;
        std::cout << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
