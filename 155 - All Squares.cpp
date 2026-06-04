#include <iostream>
#include <iomanip>

using namespace std;

// Global counter for the total number of squares enclosing the target point
int squares_count;

/**
 * Recursive function to traverse the square fractal structure.
 * @param k: half of the current square's side length
 * @param cx, cy: center coordinates of the current square
 * @param px, py: target point coordinates to check
 */
void count_squares(int k, int cx, int cy, int px, int py) {
    if (k < 1) return; // Base case: squares cannot have a size less than 1

    // 1. Check if the target point falls inside or on the border of the current square
    if (px >= cx - k && px <= cx + k && py >= cy - k && py <= cy + k) {
        squares_count++;
    }

    // 2. Recursively check the 4 sub-squares branching from the current corners
    count_squares(k / 2, cx - k, cy - k, px, py); // Bottom-Left Corner
    count_squares(k / 2, cx + k, cy - k, px, py); // Bottom-Right Corner
    count_squares(k / 2, cx - k, cy + k, px, py); // Top-Left Corner
    count_squares(k / 2, cx + k, cy + k, px, py); // Top-Right Corner
}

int main() {
    // Optimize standard input/output streams for execution speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, px, py;

    // Standard loop termination when "0 0" is given for k and px/py
    while (cin >> k >> px >> py) {
        if (k == 0 && px == 0 && py == 0) break;

        squares_count = 0;
        
        // Initial call starts at the exact grid center (1024, 1024)
        count_squares(k, 1024, 1024, px, py);

        // Problem explicitly demands an output format width right-justified to 3 spaces
        cout << setw(3) << squares_count << "\n";
    }

    return 0;
}
