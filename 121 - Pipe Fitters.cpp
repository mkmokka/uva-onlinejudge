#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate pipes using skew (hexagonal) packing
int calculateSkew(double width, double height) {
    if (height < 1.0) return 0;

    // Number of rows possible given height and the sqrt(3)/2 vertical offset
    int rows = 1 + (int)((height - 1.0) / (sqrt(3.0) / 2.0));

    // Rows alternate between 'width' pipes and 'width - 1' pipes
    int fullRows = (rows + 1) / 2;
    int offsetRows = rows / 2;

    int pipesInFullRow = (int)width;
    int pipesInOffsetRow = (int)(width - 0.5);

    return (fullRows * pipesInFullRow) + (offsetRows * pipesInOffsetRow);
}

int main() {
    double a, b;
    while (cin >> a >> b) {
        // Grid packing is simple: floor(width) * floor(height)
        int gridTotal = (int)a * (int)b;

        // Skew packing can be better if pipes are packed along side 'a' or side 'b'
        int skewTotal = max(calculateSkew(a, b), calculateSkew(b, a));

        if (skewTotal > gridTotal) {
            cout << skewTotal << " skew" << endl;
        } else {
            cout << gridTotal << " grid" << endl;
        }
    }
    return 0;
}
