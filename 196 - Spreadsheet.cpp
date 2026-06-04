#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int UNKNOWN = 2e9 + 7; // Sentinel block to flag uncomputed states

int cols, rows;
vector<vector<string>> sheet;
vector<vector<int>> memo;

// Converts an alphanumeric token (like "AB23") into 0-indexed row/col integer bounds
pair<int, int> parseCoordinates(const string& cellStr) {
    int r = 0, c = 0;
    for (char ch : cellStr) {
        if (ch >= 'A' && ch <= 'Z') {
            c = c * 26 + (ch - 'A' + 1);
        } else if (ch >= '0' && ch <= '9') {
            r = r * 10 + (ch - '0');
        }
    }
    return {r - 1, c - 1}; // Standardize to zero-indexed vectors
}

// Evaluates a given spreadsheet cell recursively
int evaluate(int r, int c) {
    // Return early if this coordinate calculation was already solved
    if (memo[r][c] != UNKNOWN) {
        return memo[r][c];
    }

    string formula = sheet[r][c];
    
    // If it's a basic number (no leading '='), convert and save it
    if (formula[0] != '=') {
        return memo[r][c] = stoi(formula);
    }

    // Replace '+' delimiters with space flags to ease stream extraction
    for (char& ch : formula) {
        if (ch == '=' || ch == '+') ch = ' ';
    }

    stringstream ss(formula);
    string token;
    int sum = 0;

    // Traverse every cell reference contained inside the addition formula
    while (ss >> token) {
        pair<int, int> target = parseCoordinates(token);
        sum += evaluate(target.first, target.second);
    }

    return memo[r][c] = sum;
}

void solve() {
    cin >> cols >> rows;

    sheet.assign(rows, vector<string>(cols));
    memo.assign(rows, vector<int>(cols, UNKNOWN));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> sheet[r][c];
        }
    }

    // Trigger memoized calculations for all coordinates in the sheet grid
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            evaluate(r, c);
        }
    }

    // Format output matching UVa specific spacing constraints
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << memo[r][c] << (c == cols - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
