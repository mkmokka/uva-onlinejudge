#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// Standard GCD function
long long gcd(long long a, long long b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

int main() {
    int N;
    while (cin >> N) {
        vector<bool> used(N + 1, false);
        int primitiveCount = 0;

        // m^2 + n^2 <= N implies m < sqrt(N)
        for (int m = 2; m * m <= N; ++m) {
            for (int n = 1; n < m; ++n) {
                // Check m^2 + n^2 <= N first for speed
                if (m * m + n * n > N) break;

                // Primitive Triple Conditions
                if ((m - n) % 2 == 1 && gcd(m, n) == 1) {
                    primitiveCount++;

                    // Mark all multiples of this triple as "used"
                    int a = m * m - n * n;
                    int b = 2 * m * n;
                    int c = m * m + n * n;
                    for (int k = 1; k * c <= N; ++k) {
                        used[k * a] = used[k * b] = used[k * c] = true;
                    }
                }
            }
        }

        int unusedCount = 0;
        for (int i = 1; i <= N; ++i) {
            if (!used[i]) unusedCount++;
        }

        cout << primitiveCount << " " << unusedCount << endl;
    }
    return 0;
}
