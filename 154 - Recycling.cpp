#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Map waste bin colors to consistent array indexes
int colorToIndex(char c) {
    if (c == 'r') return 0; // Red
    if (c == 'o') return 1; // Orange
    if (c == 'y') return 2; // Yellow
    if (c == 'g') return 3; // Green
    if (c == 'b') return 4; // Blue
    return -1;
}

int main() {
    // Fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // Maximum 100 cities per block, 5 distinct color bins
    char city_bins[105][5]; 
    int city_count = 0;

    // Read the input line by line until '#' is reached
    while (getline(cin, line) && line != "#") {
        
        // 'e' signifies the end of the current city allocation block
        if (line[0] == 'e') {
            int min_total_diff = 1e9;
            int best_city_index = 1;

            // Compare each city i against every other city j
            for (int i = 0; i < city_count; ++i) {
                int current_diff_sum = 0;

                for (int j = 0; j < city_count; ++j) {
                    if (i == j) continue;

                    // Count how many bin designations don't match
                    for (int bin = 0; bin < 5; ++bin) {
                        if (city_bins[i][bin] != city_bins[j][bin]) {
                            current_diff_sum++;
                        }
                    }
                }

                // Track the city with the minimal total differences
                if (current_diff_sum < min_total_diff) {
                    min_total_diff = current_diff_sum;
                    best_city_index = i + 1; // 1-based indexing for output
                }
            }

            // Output the optimal city index for the block
            cout << best_city_index << "\n";
            
            // Reset the counter for the next independent block
            city_count = 0;
        } 
        else {
            // Parse a normal city block line (e.g., "r/P,o/G,y/S,g/A,b/N")
            // Safely jump every 4 characters to extract color and waste type
            for (size_t i = 0; i < line.length(); i += 4) {
                char color = line[i];
                char waste = line[i + 2];
                city_bins[city_count][colorToIndex(color)] = waste;
            }
            city_count++;
        }
    }

    return 0;
}
