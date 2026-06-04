#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate cross product
double cross_product(double x1, double y1, double x2, double y2, double px, double py) {
    return (x2 - x1) * (py - y1) - (y2 - y1) * (px - x1);
}

int main() {
    double x[3], y[3];
    while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] && 
          (x[0] || y[0] || x[1] || y[1] || x[2] || y[2])) {
        
        // Define search range (1 to 99) within the bounding box
        int minX = max(1, (int)ceil(min({x[0], x[1], x[2]})));
        int maxX = min(99, (int)floor(max({x[0], x[1], x[2]})));
        int minY = max(1, (int)ceil(min({y[0], y[1], y[2]})));
        int maxY = min(99, (int)floor(max({y[0], y[1], y[2]})));

        int count = 0;
        for (int i = minX; i <= maxX; ++i) {
            for (int j = minY; j <= maxY; ++j) {
                double cp1 = cross_product(x[0], y[0], x[1], y[1], i, j);
                double cp2 = cross_product(x[1], y[1], x[2], y[2], i, j);
                double cp3 = cross_product(x[2], y[2], x[0], y[0], i, j);

                // Point is inside if all cross products are >= 0 or all <= 0
                if ((cp1 >= -1e-9 && cp2 >= -1e-9 && cp3 >= -1e-9) || 
                    (cp1 <= 1e-9 && cp2 <= 1e-9 && cp3 <= 1e-9)) {
                    count++;
                }
            }
        }
        // Output right-justified in a field of width 4
        cout << setw(4) << count << endl;
    }
    return 0;
}
