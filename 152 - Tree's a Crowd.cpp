#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Structure to hold 3D coordinates of a tree
struct Tree {
    int x, y, z;
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Tree> trees;
    int x, y, z;

    // 1. Read input until reaching the 0 0 0 terminator
    while (cin >> x >> y >> z) {
        if (x == 0 && y == 0 && z == 0) break;
        trees.push_back({x, y, z});
    }

    int n = trees.size();
    vector<int> histogram(10, 0);

    // 2. Find the minimum distance for each tree
    for (int i = 0; i < n; ++i) {
        double min_dist = 1e9; // Initialize with a large number

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            // Calculate Euclidean distance in 3D space
            double dist = sqrt(pow(trees[i].x - trees[j].x, 2) +
                               pow(trees[i].y - trees[j].y, 2) +
                               pow(trees[i].z - trees[j].z, 2));
            
            if (dist < min_dist) {
                min_dist = dist;
            }
        }

        // Truncate distance to integer (floor) as per problem instructions
        int rounded_dist = static_cast<int>(min_dist);

        // If the closest tree is within 0-9 units, increment the histogram
        if (rounded_dist >= 0 && rounded_dist <= 9) {
            histogram[rounded_dist]++;
        }
    }

    // 3. Print out the histogram formatted to 4 character wide fields
    for (int i = 0; i < 10; ++i) {
        cout << setw(4) << histogram[i];
    }
    cout << "\n";

    return 0;
}
