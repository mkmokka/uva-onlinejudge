#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Roman numeral values (standard modern)
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"}, {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},  {5, "V"},   {4, "IV"},
        {1, "I"}
    };

    // LUSIVERS font: matches per character
    unordered_map<char, int> matches = {
        {'I', 1},
        {'V', 2},
        {'X', 2},
        {'L', 2},
        {'C', 2},
        {'D', 3},
        {'M', 4}
    };

    int N;
    while (cin >> N) {              // multiple test cases
        string romanStr = "";

        // Convert number to Roman numeral
        for (auto &p : roman) {
            while (N >= p.first) {
                romanStr += p.second;
                N -= p.first;
            }
        }

        // Count matches
        int totalMatches = 0;
        for (char c : romanStr) {
            totalMatches += matches[c];
        }

        cout << totalMatches << '\n';
    }

    return 0;
}
