#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

// Standard conversion map for Roman to Arabic values
map<char, int> rMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// Convert a Roman string to its numerical value
int parseRoman(const string& s) {
    int total = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && rMap[s[i]] < rMap[s[i+1]]) {
            total -= rMap[s[i]];
        } else {
            total += rMap[s[i]];
        }
    }
    return total;
}

// Convert an encoded string into a number based on current letter-to-digit assignments
long long getArabicValue(const string& s, const int letterToDigit[]) {
    long long val = 0;
    for (char c : s) {
        val = val * 10 + letterToDigit[c];
    }
    return val;
}

string w1, w2, w3;
vector<char> uniqueLetters;
bool isLeading[256];
bool usedDigit[10];
int letterToDigit[256];
int arabicSolutionsCount;

// Backtracking DFS to find valid digit combinations
void solveArabic(int idx) {
    // Optimization: Stop if we already found multiple configurations
    if (arabicSolutionsCount > 1) return;

    if (idx == uniqueLetters.size()) {
        long long v1 = getArabicValue(w1, letterToDigit);
        long long v2 = getArabicValue(w2, letterToDigit);
        long long v3 = getArabicValue(w3, letterToDigit);
        
        if (v1 + v2 == v3) {
            arabicSolutionsCount++;
        }
        return;
    }

    char currentLetter = uniqueLetters[idx];
    for (int digit = 0; digit <= 9; ++digit) {
        if (usedDigit[digit]) continue;
        if (digit == 0 && isLeading[(unsigned char)currentLetter]) continue; // No leading zeroes

        letterToDigit[currentLetter] = digit;
        usedDigit[digit] = true;

        solveArabic(idx + 1);

        usedDigit[digit] = false; // Backtrack
        if (arabicSolutionsCount > 1) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line;
    while (cin >> line && line != "#") {
        // Parse the input equation string format: "W1+W2=W3"
        size_t plusPos = line.find('+');
        size_t eqPos = line.find('=');
        
        w1 = line.substr(0, plusPos);
        w2 = line.substr(plusPos + 1, eqPos - plusPos - 1);
        w3 = line.substr(eqPos + 1);

        // 1. Evaluate standard Roman correctness
        bool romanValid = (parseRoman(w1) + parseRoman(w2) == parseRoman(w3));

        // 2. Setup state structures for Arabic combination searches
        memset(isLeading, 0, sizeof(isLeading));
        memset(usedDigit, 0, sizeof(usedDigit));
        uniqueLetters.clear();
        bool seen[256] = {false};

        // Track leading letters to block '0' mapping
        if (!w1.empty()) isLeading[(unsigned char)w1[0]] = true;
        if (!w2.empty()) isLeading[(unsigned char)w2[0]] = true;
        if (!w3.empty()) isLeading[(unsigned char)w3[0]] = true;

        // Gather unique characters
        for (char c : w1 + w2 + w3) {
            if (!seen[(unsigned char)c]) {
                seen[(unsigned char)c] = true;
                uniqueLetters.push_back(c);
            }
        }

        // 3. Process the state machine if letter count fits inside digits limit
        arabicSolutionsCount = 0;
        if (uniqueLetters.size() <= 10) {
            solveArabic(0);
        }

        // 4. Match outputs with constraints
        if (romanValid) cout << "Correct ";
        else cout << "Incorrect ";

        if (arabicSolutionsCount == 0) cout << "impossible\n";
        else if (arabicSolutionsCount == 1) cout << "valid\n";
        else cout << "ambiguous\n";
    }
    return 0;
}
