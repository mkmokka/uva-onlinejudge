#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int board[8][8];
int queen_rows[8]; // queen_rows[c] stores the row index of the queen placed in column c
int max_score;

// Verifies if placing a queen at (r, c) conflicts with queens in previous columns
bool is_safe(int r, int c) {
    for (int prev_c = 0; prev_c < c; ++prev_c) {
        int prev_r = queen_rows[prev_c];
        
        // Check row conflict or diagonal conflict
        if (prev_r == r || abs(prev_r - r) == abs(prev_c - c)) {
            return false;
        }
    }
    return true;
}

// Depth-First Search over each column
void solve_8_queens(int col, int current_sum) {
    // Base Case: All 8 queens are safely placed
    if (col == 8) {
        max_score = max(max_score, current_sum);
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < 8; ++row) {
        if (is_safe(row, col)) {
            queen_rows[col] = row; // Commit placement
            solve_8_queens(col + 1, current_sum + board[row][col]); // Recurse
            // Backtracking happens naturally when loop transitions to next row
        }
    }
}

void solve() {
    int k;
    if (!(cin >> k)) return;

    while (k--) {
        // Read the 8x8 point matrix
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> board[i][j];
            }
        }

        max_score = 0;
        solve_8_queens(0, 0);

        // Print final score right-justified using exactly 5 spaces padding
        cout << setw(5) << max_score << "\n";
    }
}

int main() {
    // Optimize performance stream profiles for competitive programming speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
