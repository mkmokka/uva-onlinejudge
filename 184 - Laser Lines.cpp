#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

// Sort points by x coordinate, then by y coordinate
bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// Check if three points are collinear using cross-product
bool isCollinear(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) == (p2.y - p1.y) * (p3.x - p1.x);
}

void solve() {
    Point p;
    while (true) {
        vector<Point> points;
        
        // Read coordinate points until (0, 0) is encountered
        while (cin >> p.x >> p.y && (p.x != 0 || p.y != 0)) {
            points.push_back(p);
        }
        
        if (points.empty()) break;

        sort(points.begin(), points.end(), comparePoints);
        
        int n = points.size();
        bool found_any_line = false;
        
        // Matrix to track used point pairs to avoid printing overlapping subsets of lines
        vector<vector<bool>> used(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (used[i][j]) continue;

                vector<int> line_indices;
                line_indices.push_back(i);
                line_indices.push_back(j);

                // Look for other points collinear with points[i] and points[j]
                for (int k = j + 1; k < n; ++k) {
                    if (isCollinear(points[i], points[j], points[k])) {
                        line_indices.push_back(k);
                    }
                }

                // Problem constraints require 3 or more points to form a legal laser line
                if (line_indices.size() >= 3) {
                    if (!found_any_line) {
                        cout << "The following lines were found:\n";
                        found_any_line = true;
                    }

                    // Print points on the line formatted as (  X,  Y)
                    for (int idx : line_indices) {
                        cout << "(" << setw(4) << points[idx].x << "," << setw(4) << points[idx].y << ")";
                    }
                    cout << "\n";

                    // Mark all unique pairs on this straight line to skip future duplicate tracks
                    for (size_t a = 0; a < line_indices.size(); ++a) {
                        for (size_t b = a + 1; b < line_indices.size(); ++b) {
                            used[line_indices[a]][line_indices[b]] = true;
                        }
                    }
                }
            }
        }

        if (!found_any_line) {
            cout << "No lines were found\n";
        }
    }
}

int main() {
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
