#include <iostream>
#include <vector>

int solve(int n, int k) {
    if (n == 1) return 1;
    for (int start = 1; start <= n; ++start) {
        std::vector<int> circle(n);
        for (int i = 0; i < n; ++i) circle[i] = (i + start - 1) % n + 1;

        int curr = 0;
        for (int remaining = n; remaining > 1; --remaining) {
            // Find victim (k-th person)
            int count = 0;
            int victim_idx;
            while (count < k) {
                if (circle[curr] != 0) count++;
                if (count == k) victim_idx = curr;
                curr = (curr + 1) % n;
            }

            // Find burier (k-th person excluding victim)
            int burier_idx;
            count = 0;
            int b_curr = (victim_idx + 1) % n;
            while (count < k) {
                if (circle[b_curr] != 0 && b_curr != victim_idx) count++;
                if (count == k) burier_idx = b_curr;
                b_curr = (b_curr + 1) % n;
            }

            circle[victim_idx] = circle[burier_idx];
            circle[burier_idx] = 0;
            curr = (victim_idx + 1) % n;
        }

        for (int i = 0; i < n; ++i) {
            if (circle[i] == 1) return start;
        }
    }
    return 1;
}

int main() {
    int n, k;
    while (std::cin >> n >> k && (n || k)) {
        std::cout << solve(n, k) << std::endl;
    }
    return 0;
}
