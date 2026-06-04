#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Custom case-insensitive ordering: A -> a -> B -> b -> ... -> Z -> z
bool customCompare(char lhs, char rhs) {
    char lowerLhs = std::tolower(static_cast<unsigned char>(lhs));
    char lowerRhs = std::tolower(static_cast<unsigned char>(rhs));
    
    if (lowerLhs == lowerRhs) {
        // If characters are identical when lowercased, Uppercase comes first
        // In ASCII, 'A' (65) < 'a' (97), so standard '<' matches this logic
        return lhs < rhs; 
    }
    
    return lowerLhs < lowerRhs;
}

int main() {
    // Optimize standard input/output streams for fast performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testCases;
    if (std::cin >> testCases) {
        std::string word;
        while (testCases--) {
            std::cin >> word;
            
            // Step 1: Sort the string according to our unique custom order
            std::sort(word.begin(), word.end(), customCompare);
            
            // Step 2: Lexicographically cycle permutations using next_permutation
            do {
                std::cout << word << "\n";
            } while (std::next_permutation(word.begin(), word.end(), customCompare));
        }
    }
    return 0;
}
