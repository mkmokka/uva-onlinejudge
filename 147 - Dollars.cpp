#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Fixed: Added correct braces for array initialization
const int COINS[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
const int MAX_VAL = 6000; // 30000 cents / 5

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> dp(MAX_VAL + 1, 0);
    dp[0] = 1; // Base case

    // Precompute DP table
    for (int coin : COINS) {
        for (int i = coin; i <= MAX_VAL; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    double input_amount;
    while (cin >> input_amount && input_amount != 0.00) {
        // Round safely to avoid floating-point truncations
        int total_cents = (int)round(input_amount * 100);
        int dp_index = total_cents / 5; // Fixed variable consistency

        // Print output with exact field widths required by UVa
        cout << setw(6) << fixed << setprecision(2) << input_amount
             << setw(17) << dp[dp_index] << "\n";
    }

    return 0;
}
