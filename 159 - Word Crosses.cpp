#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Finds the first intersection between a horizontal word (h) and vertical word (v)
// Returns pair of indices {h_idx, v_idx}. Returns {-1, -1} if no match is found.
pair<int, int> find_intersection(const string& h, const string& v) {
    for (int i = 0; i < h.length(); ++i) {
        for (int j = 0; j < v.length(); ++j) {
            if (h[i] == v[j]) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void solve() {
    string A, B, C, D;
    bool first_case = true;

    while (cin >> A && A != "#") {
        cin >> B >> C >> D;

        if (!first_case) {
            cout << "\n"; // Blank line between successive outputs
        }
        first_case = false;

        pair<int, int> cross1 = find_intersection(A, B);
        pair<int, int> cross2 = find_intersection(C, D);

        // If either crossword pair cannot form an intersection
        if (cross1.first == -1 || cross2.first == -1) {
            cout << "Unable to make two crosses\n";
            continue;
        }

        // Determine grid rows based on top-padding and bottom-padding needs
        int top1 = cross1.second; 
        int top2 = cross2.second;
        int max_top = max(top1, top2);

        int bot1 = B.length() - cross1.second - 1;
        int bot2 = D.length() - cross2.second - 1;
        int max_bot = max(bot1, bot2);

        int total_rows = max_top + 1 + max_bot;

        // Render line by line
        for (int r = 0; r < total_rows; ++r) {
            string line = "";

            // --- CROSS 1 REGION ---
            int current_v1_row = r - (max_top - top1);
            if (current_v1_row == top1) {
                // This row contains the full horizontal word A
                line += A;
            } else if (current_v1_row >= 0 && current_v1_row < B.length()) {
                // This row contains a single character of vertical word B
                line += string(cross1.first, ' ') + B[current_v1_row];
            }
            
            // Pad the rest of Cross 1's width if Cross 2 needs to print details
            int current_len = line.length();
            if (current_len < A.length()) {
                line += string(A.length() - current_len, ' ');
            }

            // --- SEPARATOR (3 spaces) ---
            line += "   ";

            // --- CROSS 2 REGION ---
            int current_v2_row = r - (max_top - top2);
            if (current_v2_row == top2) {
                // This row contains the full horizontal word C
                line += C;
            } else if (current_v2_row >= 0 && current_v2_row < D.length()) {
                // This row contains a single character of vertical word D
                line += string(cross2.first, ' ') + D[current_v2_row];
            }

            // Stripping trailing spaces from the output line to prevent Presentation Errors
            while (!line.empty() && line.back() == ' ') {
                line.pop_back();
            }
            cout << line << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
