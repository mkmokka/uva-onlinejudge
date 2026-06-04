#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Constants representing backtrace operations
const int MATCH_OR_COPY = 1;
const int DELETE_OP     = 2;
const int INSERT_OP     = 3;
const int CHANGE_OP     = 4;

string A, B;
int dp[25][25];
int parent_op[25][25];

// Recursively walks the DP choices back to front to print commands in proper sequence
void print_operations(int i, int j) {
    if (i == 0 && j == 0) return;

    if (parent_op[i][j] == MATCH_OR_COPY) {
        print_operations(i - 1, j - 1);
    } 
    else if (parent_op[i][j] == DELETE_OP) {
        print_operations(i - 1, j);
        // Position reflects 1-based indexing on the current modified target row
        cout << "D" << A[i - 1] << setfill('0') << setw(2) << j + 1;
    } 
    else if (parent_op[i][j] == INSERT_OP) {
        print_operations(i, j - 1);
        cout << "I" << B[j - 1] << setfill('0') << setw(2) << j;
    } 
    else if (parent_op[i][j] == CHANGE_OP) {
        print_operations(i - 1, j - 1);
        cout << "C" << B[j - 1] << setfill('0') << setw(2) << j;
    }
}

void solve() {
    // Process input pairs sequentially until meeting a termination string '#'
    while (cin >> A && A != "#") {
        cin >> B;

        int n = A.length();
        int m = B.length();

        // Initialize the base boundaries of the DP table
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
            parent_op[i][0] = DELETE_OP;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
            parent_op[0][j] = INSERT_OP;
        }

        // Fill out grid transformations matrix
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    parent_op[i][j] = MATCH_OR_COPY;
                } else {
                    // Start by picking the Change option cost layout
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    parent_op[i][j] = CHANGE_OP;

                    // Evaluate if Deleting gives a cheaper path
                    if (dp[i - 1][j] + 1 < dp[i][j]) {
                        dp[i][j] = dp[i - 1][j] + 1;
                        parent_op[i][j] = DELETE_OP;
                    }

                    // Evaluate if Inserting gives a cheaper path
                    if (dp[i][j - 1] + 1 < dp[i][j]) {
                        dp[i][j] = dp[i][j - 1] + 1;
                        parent_op[i][j] = INSERT_OP;
                    }
                }
            }
        }

        // Output reconstructed transformation commands
        print_operations(n, m);
        cout << "E\n"; // End of sequence marker
    }
}

int main() {
    // Optimize standard input/output streams for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
