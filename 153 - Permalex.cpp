#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for setw

using namespace std;

// Recursive Greatest Common Divisor function to assist in fraction reduction
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Computes permutations with repetitions safely: (total!) / (c1! * c2! * ... * ck!)
long long compute_permutations(int total_length, const vector<int>& counts) {
    if (total_length == 0) return 1;

    // Create a numerator array containing values from 1 to total_length
    vector<long long> numerator(total_length + 1);
    for (int i = 1; i <= total_length; ++i) {
        numerator[i] = i;
    }

    // Cancel out all elements of the denominator factorials sequentially using GCD
    for (int count : counts) {
        for (int c = 2; c <= count; ++c) {
            long long rem_denominator = c;
            for (int n = 2; n <= total_length && rem_denominator > 1; ++n) {
                long long common = gcd(rem_denominator, numerator[n]);
                numerator[n] /= common;
                rem_denominator /= common;
            }
        }
    }

    // Multiply the remaining elements in the numerator array
    long long total_permutations = 1;
    for (int i = 1; i <= total_length; ++i) {
        total_permutations *= numerator[i];
    }
    return total_permutations;
}

int main() {
    // Fast I/O to avoid time limit issues
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Loops cleanly until '#' is encountered.
    while (cin >> s && s != "#") {
        long long rank = 1;
        int n = s.length();

        // Calculate initial frequencies of each character ('a' through 'z')
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Process the string position by position
        for (int i = 0; i < n; ++i) {
            // Test all characters lexicographically smaller than s[i]
            for (int j = 0; j < (s[i] - 'a'); ++j) {
                if (freq[j] > 0) {
                    // Temporarily choose 'j' as the character for position 'i'
                    freq[j]--;

                    // Add the unique permutations of the remaining letters
                    rank += compute_permutations(n - 1 - i, freq);

                    // Restore the frequency balance
                    freq[j]++;
                }
            }
            // Permanently consume s[i] as we advance to the next position
            freq[s[i] - 'a']--;
        }

        // FIX: Format output to be exactly 10 characters wide, right-justified
        cout << setw(10) << rank << "\n";
    }
    return 0;
}
