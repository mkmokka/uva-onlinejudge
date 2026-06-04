#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Checks if all traffic lights are Green at a specific second
bool all_lights_green(const vector<int>& cycles, int t) {
    for (int c : cycles) {
        if (t % (2 * c) >= c - 5) {
            return false; // Not green (either orange or red)
        }
    }
    return true;
}

void solve() {
    int cycle;
    
    // Continue running until the EOF or 3 consecutive zeros are triggered
    while (cin >> cycle && cycle != 0) {
        vector<int> cycles;
        cycles.push_back(cycle);
        
        int min_cycle = cycle;
        
        // Read the remaining traffic lights for the current scenario
        while (cin >> cycle && cycle != 0) {
            cycles.push_back(cycle);
            min_cycle = min(min_cycle, cycle);
        }

        int sync_time = -1;
        // Start simulation after the first light turns orange (2 * min_cycle)
        // Cap simulation at 5 hours (18000 seconds)
        for (int t = 2 * min_cycle; t <= 18000; ++t) {
            if (all_lights_green(cycles, t)) {
                sync_time = t;
                break;
            }
        }

        // Print final scenario statistics structured via HH:MM:SS format
        if (sync_time != -1) {
            int hours = sync_time / 3600;
            int minutes = (sync_time % 3600) / 60;
            int seconds = sync_time % 60;

            cout << setfill('0') << setw(2) << hours << ":"
                 << setw(2) << minutes << ":"
                 << setw(2) << seconds << "\n";
        } else {
            cout << "Signals fail to synchronise in 5 hours\n";
        }
    }
}

int main() {
    // Optimize standard I/O streams for competitive programming speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
