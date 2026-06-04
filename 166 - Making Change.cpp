#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int COINS[] = {5, 10, 20, 50, 100, 200};
const int INF = 1e9;
const int MAX_LIMIT = 1000; // $5.00 limit cap + buffer window for overpaying

vector<int> shopkeeper_dp(MAX_LIMIT + 1, INF);

// Precompute the shopkeeper's optimal change matrix (Unbounded Knapsack)
void precompute_shopkeeper() {
    shopkeeper_dp[0] = 0;
    for (int coin : COINS) {
        for (int j = coin; j <= MAX_LIMIT; ++j) {
            if (shopkeeper_dp[j - coin] != INF) {
                shopkeeper_dp[j] = min(shopkeeper_dp[j], shopkeeper_dp[j - coin] + 1);
            }
        }
    }
}

void solve() {
    precompute_shopkeeper();
    
    vector<int> counts(6);
    while (true) {
        int total_coins = 0;
        for (int i = 0; i < 6; ++i) {
            cin >> counts[i];
            total_coins += counts[i];
        }
        
        // Terminal case check: loop breaks on 6 zeros
        if (total_coins == 0) break;

        double target_float;
        cin >> target_float;
        // Safely round floating transactions into fixed cents integers
        int target = round(target_float * 100.0);

        // dp_give[x] stores the minimum number of coins you use to pay exactly value 'x'
        vector<int> dp_give(MAX_LIMIT + 1, INF);
        dp_give[0] = 0;

        // Bounded Knapsack calculation for coins out of your wallet
        for (int i = 0; i < 6; ++i) {
            int coin_val = COINS[i];
            int available = counts[i];
            
            // Loop through counts one by one (or via binary optimization)
            for (int qty = 0; qty < available; ++qty) {
                for (int j = MAX_LIMIT; j >= coin_val; --j) {
                    if (dp_give[j - coin_val] != INF) {
                        dp_give[j] = min(dp_give[j], dp_give[j - coin_val] + 1);
                    }
                }
            }
        }

        int min_total_coins_exchanged = INF;

        // Evaluate all overpayment cases and find the minimum combination cost
        for (int pay = target; pay <= MAX_LIMIT; pay += 5) {
            if (dp_give[pay] != INF && shopkeeper_dp[pay - target] != INF) {
                int current_exchange = dp_give[pay] + shopkeeper_dp[pay - target];
                min_total_coins_exchanged = min(min_total_coins_exchanged, current_exchange);
            }
        }

        // Output format requirement: Right-aligned using 3 spaces padding
        cout << setw(3) << min_total_coins_exchanged << "\n";
    }
}

int main() {
    // Optimize performance stream profiles
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
