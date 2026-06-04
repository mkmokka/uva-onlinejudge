#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<string> Board;

// Function to rotate board 90 degrees clockwise
Board rotate(const Board& b, int n) {
    Board res(n, string(n, '0'));
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            res[c][n - 1 - r] = b[r][c];
    return res;
}

void solve() {
    int n;
    while (cin >> n && n != 0) {
        Board board(n, string(n, '0'));
        set<Board> history;
        int winner = 0, winningMove = 0;
        bool gameOver = false;

        for (int i = 1; i <= 2 * n; ++i) {
            int r, c;
            string move;
            cin >> r >> c >> move;
            if (gameOver) continue;

            // Update board
            board[r - 1][c - 1] = (move == "+" ? '1' : '0');

            // Check all 4 rotations
            Board temp = board;
            bool found = false;
            for (int k = 0; k < 4; ++k) {
                if (history.count(temp)) found = true;
                temp = rotate(temp, n);
            }

            if (found) {
                winner = (i % 2 == 0 ? 1 : 2); // Current player loses
                winningMove = i;
                gameOver = true;
            } else {
                history.insert(board);
            }
        }

        if (winner == 0) cout << "Draw" << endl;
        else cout << "Player " << winner << " wins on move " << winningMove << endl;
    }
}

int main() {
    solve();
    return 0;
}
