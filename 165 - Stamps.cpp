#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int H, N;
int max_continuous;
vector<int> best_stamps;
vector<int> current_stamps;

// Core Evaluation: Calculates the maximum continuous sequence [1...M] 
// possible with the current stamp setup using at most H total stamps.
int get_max_continuous(const vector<int>& stamps) {
    int max_possible_sum = stamps.back() * H;
    // dp[i] stores the minimum number of stamps required to make value 'i'
    vector<int> dp(max_possible_sum + 2, H + 1);
    dp[0] = 0;

    int continuous_limit = 0;
    for (int i = 1; i <= max_possible_sum + 1; ++i) {
        for (int coin : stamps) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        // If the value requires more than H stamps, the continuous chain breaks
        if (dp[i] > H) {
            continuous_limit = i - 1;
            break;
        }
    }
    return continuous_limit;
}

// Backtracking DFS tree to look for valid combinations
void search_stamps(int current_index) {
    // Base Case: If we have picked N stamp denominations
    if (current_index == N) {
        int current_max = get_max_continuous(current_stamps);
        if (current_max > max_continuous) {
            max_continuous = current_max;
            best_stamps = current_stamps;
        }
        return;
    }

    int last_stamp = current_stamps.back();
    int current_limit = get_max_continuous(current_stamps);

    // Pruning/Branch Bound rule: Next stamp can range from last_stamp + 1 up to current_limit + 1
    for (int next_val = last_stamp + 1; next_val <= current_limit + 1; ++next_val) {
        current_stamps.push_back(next_val);
        search_stamps(current_index + 1);
        current_stamps.pop_back(); // Backtrack
    }
}

void solve() {
    // Process input pairs until both parameters match terminal sequence 0 0
    while (cin >> H >> N && (H != 0 || N != 0)) {
        max_continuous = 0;
        best_stamps.clear();
        current_stamps.clear();

        // The first stamp denomination must always be 1
        current_stamps.push_back(1);
        search_stamps(1);

        // Strict Alignment Layout Format requirement
        // Printed stamps values must fit within right-justified fields of width 3
        for (int stamp : best_stamps) {
            cout << setw(3) << stamp;
        }
        cout << " ->" << setw(3) << max_continuous << "\n";
    }
}

int main() {
    // Optimize performance throughput 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
