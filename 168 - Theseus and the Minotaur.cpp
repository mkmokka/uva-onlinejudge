#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void solve() {
    string line;
    // Read datasets sequentially until encountering the terminal character '#'
    while (getline(cin, line) && line != "#") {
        vector<vector<int>> adj(26);
        bool lit[26] = {false};

        stringstream ss(line);
        string graph_part;
        ss >> graph_part;

        // Parse graph configurations (e.g., A:BCD;B:A.)
        int idx = 0;
        while (idx < graph_part.length() && graph_part[idx] != '.') {
            int u = graph_part[idx] - 'A';
            idx += 2; // Move past the node name and the ':' character
            
            while (idx < graph_part.length() && graph_part[idx] != ';' && graph_part[idx] != '.') {
                int v = graph_part[idx] - 'A';
                adj[u].push_back(v);
                idx++;
            }
            if (idx < graph_part.length() && graph_part[idx] == ';') {
                idx++; // Advance over the separator to read the next node configuration
            }
        }

        // Parse the initial actor positions and the candle frequency threshold k
        char mino_char, theseus_char;
        int k;
        ss >> mino_char >> theseus_char >> k;

        int mino = mino_char - 'A';
        int theseus = theseus_char - 'A';
        int step_count = 0;

        while (true) {
            int next_position = -1;

            // Search alphabetically for the first legal escape cavern 
            for (int neighbor : adj[mino]) {
                if (neighbor != theseus && !lit[neighbor]) {
                    next_position = neighbor;
                    break;
                }
            }

            // Minotaur cannot escape anywhere: he is trapped
            if (next_position == -1) {
                cout << "/" << (char)(mino + 'A') << "\n";
                break;
            }

            step_count++;
            // Theseus moves to the location the Minotaur is vacating
            theseus = mino;
            mino = next_position;

            // Drop a candle if the move frequency equals k
            if (step_count == k) {
                lit[theseus] = true;
                cout << (char)(theseus + 'A') << " ";
                step_count = 0; // Reset counter threshold
            }
        }
    }
}

int main() {
    // Optimize performance stream profiles for execution speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
