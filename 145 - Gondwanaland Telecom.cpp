#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Charging rate matrix [Charging Step (A-E)][Time Band (Day, Evening, Night)]
const double RATES[5][3] = {
    {0.10, 0.06, 0.02}, // A
    {0.25, 0.15, 0.05}, // B
    {0.53, 0.33, 0.13}, // C
    {0.87, 0.47, 0.17}, // D
    {1.44, 0.80, 0.30}  // E
};

// Function to determine time band based on minute of the day (0 to 1439)
int get_time_band(int minute) {
    if (minute >= 480 && minute < 1080) return 0;       // Day: 08:00 - 18:00
    if (minute >= 1080 && minute < 1320) return 1;      // Evening: 18:00 - 22:00
    return 2;                                           // Night: 22:00 - 08:00
}

int main() {
    char step;
    while (cin >> step && step != '#') {
        string phone_number;
        int start_h, start_m, end_h, end_m;
        cin >> phone_number >> start_h >> start_m >> end_h >> end_m;

        int start_time = start_h * 60 + start_m;
        int end_time = end_h * 60 + end_m;

        // If start time equals end time, it represents a 24-hour call (1440 minutes)
        if (start_time == end_time) {
            end_time += 1440;
        } else if (end_time < start_time) {
            // Call extends past midnight into the next day
            end_time += 1440;
        }

        int minutes_per_band[3] = {0, 0, 0};

        // Simulate the call minute by minute
        for (int t = start_time; t < end_time; ++t) {
            int current_minute = t % 1440;
            minutes_per_band[get_time_band(current_minute)]++;
        }

        // Calculate total cost
        int step_idx = step - 'A';
        double total_cost = 0;
        for (int i = 0; i < 3; ++i) {
            total_cost += minutes_per_band[i] * RATES[step_idx][i];
        }

        // Output formatting
        cout << setw(10) << phone_number
             << setw(6) << minutes_per_band[0]
             << setw(6) << minutes_per_band[1]
             << setw(6) << minutes_per_band[2]
             << setw(3) << step
             << setw(8) << fixed << setprecision(2) << total_cost << endl;
    }
    return 0;
}
