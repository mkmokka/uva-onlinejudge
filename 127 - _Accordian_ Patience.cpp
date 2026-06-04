#include <iostream>
#include <string>
#include <vector>

using namespace std;

// দুটি তাসের র‍্যাঙ্ক বা স্যুট মিলছে কি না তা চেক করার ফাংশন
bool is_match(const string& card1, const string& card2) {
    return card1[0] == card2[0] || card1[1] == card2[1];
}

// সিমুলেশন রান করার মূল ফাংশন
void solve_patience(vector<vector<string>>& piles) {
    int i = 0;
    while (i < piles.size()) {
        // ১. প্রথমে ৩ ঘর বামের পাইলের সাথে ম্যাচ চেক করা
        if (i >= 3 && is_match(piles[i].back(), piles[i - 3].back())) {
            piles[i - 3].push_back(piles[i].back());
            piles[i].pop_back();
            
            // যদি বর্তমান পাইলটি খালি হয়ে যায়, তবে সেটি ভেক্টর থেকে মুছে ফেলা হবে
            if (piles[i].empty()) {
                piles.erase(piles.begin() + i);
            }
            // মুভ সফল হলে আবার একদম শুরু থেকে (বাম থেকে) চেক করা শুরু হবে
            i = 0; 
        }
        // ২. ৩ ঘর বামে না মিললে, ১ ঘর বামের পাইলের সাথে ম্যাচ চেক করা
        else if (i >= 1 && is_match(piles[i].back(), piles[i - 1].back())) {
            piles[i - 1].push_back(piles[i].back());
            piles[i].pop_back();
            
            if (piles[i].empty()) {
                piles.erase(piles.begin() + i);
            }
            i = 0;
        } 
        // কোনো মুভ না পাওয়া গেলে পরবর্তী পাইলে যাওয়া হবে
        else {
            i++;
        }
    }
}

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string card;
    while (cin >> card && card != "#") {
        // প্রতিটি পাইলে তাসের লিস্ট রাখার জন্য ২ডি ভেক্টর
        vector<vector<string>> piles(52);
        piles[0].push_back(card);

        // বাকি ৫১টি তাস ইনপুট নেওয়া
        for (int i = 1; i < 52; ++i) {
            cin >> card;
            piles[i].push_back(card);
        }

        // খেলা শুরু করা
        solve_patience(piles);

        // সঠিক ফরম্যাটে আউটপুট প্রিন্ট করা
        if (piles.size() == 1) {
            cout << "1 pile remaining: 52\n";
        } else {
            cout << piles.size() << " piles remaining:";
            for (size_t i = 0; i < piles.size(); ++i) {
                cout << " " << piles[i].size();
            }
            cout << "\n";
        }
    }

    return 0;
}
