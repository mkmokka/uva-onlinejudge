#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// List of all prime numbers less than 100
const int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
                      53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const int NUM_PRIMES = 25;

void solve(int n) {
    vector<int> prime_counts(NUM_PRIMES, 0);
    int max_prime_idx = 0;

    // Dynamically factorize every integer from 2 up to n
    for (int i = 2; i <= n; ++i) {
        int temp = i;
        for (int j = 0; j < NUM_PRIMES; ++j) {
            while (temp % PRIMES[j] == 0) {
                prime_counts[j]++;
                temp /= PRIMES[j];
                if (j > max_prime_idx) {
                    max_prime_idx = j; // Keep track of the highest prime used
                }
            }
            if (temp == 1) break;
        }
    }

    // Print initial block formatting: 'N! =' (N right-justified in 3 spaces)
    cout << setw(3) << n << "! =";

    int printed_count = 0;
    for (int i = 0; i <= max_prime_idx; ++i) {
        printed_count++;
        
        // After printing 15 factors, wrap to a new line and pad correctly
        if (printed_count > 15) {
            cout << "\n      "; // 6 spaces of indentation on the new line
            printed_count = 1;  // Reset count tracking for the new row
        }
        
        cout << setw(3) << prime_counts[i];
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        solve(n);
    }

    return 0;
}
