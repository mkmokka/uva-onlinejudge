#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int get_value(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

int evaluate_hand(const vector<string>& cards) {
    vector<int> values(5);
    map<int, int> value_counts;
    map<char, int> suit_counts;

    for (int i = 0; i < 5; ++i) {
        values[i] = get_value(cards[i][0]);
        value_counts[values[i]]++;
        suit_counts[cards[i][1]]++; // Fixed suit indexing
    }

    sort(values.begin(), values.end());

    bool is_flush = (suit_counts.size() == 1);
    bool is_straight = false;

    if (value_counts.size() == 5) {
        // Normal straight
        if (values[4] - values[0] == 4) {
            is_straight = true;
        } 
        // Ace-low straight check: A, 2, 3, 4, 5 (sorted as 2, 3, 4, 5, 14)
        else if (values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 14) {
            is_straight = true;
        }
    }

    vector<int> counts;
    for (auto const& [val, count] : value_counts) {
        counts.push_back(count);
    }
    sort(counts.rbegin(), counts.rend());

    if (is_flush && is_straight) return 9; // straight-flush
    if (counts[0] == 4)           return 8; // four-of-a-kind
    if (counts[0] == 3 && counts[1] == 2) return 7; // full-house
    if (is_flush)                 return 6; // flush
    if (is_straight)              return 5; // straight
    if (counts[0] == 3)           return 4; // three-of-a-kind
    if (counts[0] == 2 && counts[1] == 2) return 3; // two-pairs
    if (counts[0] == 2)           return 2; // one-pair
    return 1;                               // highest-card
}

string rank_to_string(int rank) {
    switch(rank) {
        case 9: return "straight-flush";
        case 8: return "four-of-a-kind";
        case 7: return "full-house";
        case 6: return "flush";
        case 5: return "straight";
        case 4: return "three-of-a-kind";
        case 3: return "two-pairs"; // Fixed plural string requirement
        case 2: return "one-pair";
        default: return "highest-card";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> hand(5), deck(5);
    while (cin >> hand[0]) {
        for (int i = 1; i < 5; ++i) cin >> hand[i];
        for (int i = 0; i < 5; ++i) cin >> deck[i];

        int best_rank = 0;

        // Try all 32 combinations of discarding / keeping cards
        for (int mask = 0; mask < 32; ++mask) {
            vector<string> current_combination;
            int deck_idx = 0;

            for (int i = 0; i < 5; ++i) {
                if ((mask >> i) & 1) {
                    current_combination.push_back(hand[i]);
                }
            }
            while (current_combination.size() < 5) {
                current_combination.push_back(deck[deck_idx++]);
            }

            best_rank = max(best_rank, evaluate_hand(current_combination));
        }

        cout << "Hand:";
        for (const string& card : hand) cout << " " << card;
        cout << " Deck:";
        for (const string& card : deck) cout << " " << card;
        cout << " Best hand: " << rank_to_string(best_rank) << "\n";
    }
    return 0;
}
