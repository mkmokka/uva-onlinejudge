#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <iomanip>

using namespace std;

// Returns challenge penalty value. Returns 0 for normal face rank values.
int get_penalty(char rank) {
    if (rank == 'J') return 1;
    if (rank == 'Q') return 2;
    if (rank == 'K') return 3;
    if (rank == 'A') return 4;
    return 0;
}

void solve() {
    string first_card;
    while (cin >> first_card && first_card != "#") {
        // Index 0: Dealer (Player 1), Index 1: Non-Dealer (Player 2)
        vector<deque<char>> players(2);
        deque<char> table;

        // Deal first card to Non-Dealer (Index 1)
        players[1].push_front(first_card[1]);

        // Deal out the remaining 51 cards sequentially
        for (int i = 1; i < 52; ++i) {
            string card;
            cin >> card;
            int player_id = (i % 2 == 0) ? 1 : 0; // Alternates: Non-dealer, Dealer
            players[player_id].push_front(card[1]); // Store face values ('A','K','Q','J' or numbers)
        }

        int turn = 1;         // Non-dealer plays the very first card
        int penalty = 0;      // Current active face card challenge tracking 
        int last_face_player = -1;

        while (true) {
            // Check if current active turn player has run out of playing cards
            if (players[turn].empty()) break;

            // Take card from face/top of player pile and lay it onto the active table pile
            char played_card = players[turn].front();
            players[turn].pop_front();
            table.push_back(played_card);

            int card_penalty = get_penalty(played_card);

            if (card_penalty > 0) {
                // Fresh face card found: override prior challenges and reset turn
                penalty = card_penalty;
                last_face_player = turn;
                turn = 1 - turn; // Shifts to the opponent to defend
            } else if (penalty > 0) {
                // If a player is trying to pay a penalty and puts down a normal card
                penalty--;
                if (penalty == 0) {
                    // Challenge defense failed completely. Opponent takes all table cards.
                    while (!table.empty()) {
                        players[last_face_player].push_back(table.front());
                        table.pop_front();
                    }
                    turn = last_face_player; // The winner of the trick initiates next round
                }
            } else {
                // Standard un-challenged play alternating back and forth
                turn = 1 - turn;
            }
        }

        // The game ended because 'turn' ran out of cards, making the other player the winner
        int winner = 1 - turn;
        int remaining_cards = players[winner].size();

        // Output formatting must show 1 or 2 right-aligned using exactly 3 spaces padding
        cout << (winner == 0 ? "1" : "2") << setw(3) << remaining_cards << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
