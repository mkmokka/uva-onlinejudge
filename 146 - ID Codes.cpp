#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    
    // Read input until a single '#' is encountered
    while (cin >> s && s != "#") {
        // Find the next lexicographical permutation
        if (next_permutation(s.begin(), s.end())) {
            cout << s << "\n";
        } else {
            cout << "No Successor\n";
        }
    }
    
    return 0;
}
