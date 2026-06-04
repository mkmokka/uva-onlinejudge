#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

// Converts a card rank character into its corresponding 0-indexed clock pile position
int get_pile_index(char rank) {
    if (rank == 'A') return 0;
    if (rank >= '2' && rank <= '9') return rank - '1';
    if (rank == 'T') return 9;
    if (rank == 'J') return 10;
    if (rank == 'Q') return 11;
    if (rank == 'K') return 12;
    return 0;
}

void solve() {
    string card_token;
    
    // Process input streams continuously until encountering terminal character "#"
    while (cin >> card_token && card_token != "#") {
        // Use standard FIFO queues to mirror the face-down layout piles
        vector<queue<string>> piles(13);

        // The first token read is the top card of Pile 13 (King, index 12)
        piles[12].push(card_token);

        // Read and distribute the remaining 51 cards sequentially
        for (int i = 50; i >= 0; --i) {
            cin >> card_token;
            // Math equation maps cycle intervals flawlessly back into piles
            piles[i % 13].push(card_token);
        }

        int cards_exposed = 0;
        int active_pile = 12; // Simulation always begins at the King pile (index 12)
        string current_card = "";

        // Simulation Loop
        do {
            cards_exposed++;
            current_card = piles[active_pile].front();
            piles[active_pile].pop();
            
            // Look up the card rank to derive our next target index position
            active_pile = get_pile_index(current_card[0]);
            
        } while (!piles[active_pile].empty()); // Loops until the destination has no cards left

        // Output formatting: 2-digit padding followed by comma and final card token
        cout << setw(2) << setfill('0') << cards_exposed << "," << current_card << "\n";
    }
}

int main() {
    // Optimize performance stream profiles for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
