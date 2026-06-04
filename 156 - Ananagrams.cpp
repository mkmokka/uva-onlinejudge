#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Helper function to normalize a word (lowercase and sort letters alphabetically)
string normalize_word(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    vector<string> original_words;
    map<string, int> signature_counts;

    // 1. Read input words until the '#' termination character
    while (cin >> word && word != "#") {
        original_words.push_back(word);
        string signature = normalize_word(word);
        signature_counts[signature]++;
    }

    vector<string> ananagrams;

    // 2. Identify words whose normalized signature appears exactly once
    for (const string &orig : original_words) {
        string signature = normalize_word(orig);
        if (signature_counts[signature] == 1) {
            ananagrams.push_back(orig);
        }
    }

    // 3. Output requirements mandate lexicographical sorting of the original words
    sort(ananagrams.begin(), ananagrams.end());

    // 4. Print out the results line by line
    for (const string &res : ananagrams) {
        cout << res << "\n";
    }

    return 0;
}
