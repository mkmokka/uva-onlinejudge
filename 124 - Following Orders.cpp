#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<char> variables;
map<char, vector<char>> adj;
map<char, int> in_degree;
map<char, bool> visited;
string current_path;

// সব সম্ভাব্য টপোলজিক্যাল সর্ট খোঁজার ব্যাকট্র্যাকিং ফাংশন
void backtrack() {
    // যদি সব ভেরিয়েবল নেওয়া হয়ে যায়, তবে একটি সঠিক ক্রম পাওয়া গেছে
    if (current_path.length() == variables.size()) {
        cout << current_path << "\n";
        return;
    }

    // বর্ণানুক্রমিকভাবে প্রতিটি ভেরিয়েবল চেক করা হচ্ছে
    for (char u : variables) {
        if (!visited[u] && in_degree[u] == 0) {
            // নোডটি সিলেক্ট করা হলো
            visited[u] = true;
            current_path.push_back(u);

            // এই নোডের সাথে যুক্ত সব নোডের ইন-ডিগ্রী ১ কমানো হলো
            for (char v : adj[u]) {
                in_degree[v]--;
            }

            // পরবর্তী নোড খোঁজার জন্য রিকার্সন কল
            backtrack();

            // ব্যাকট্র্যাকিং: আগের অবস্থায় ফেরত যাওয়া
            for (char v : adj[u]) {
                in_degree[v]++;
            }
            current_path.pop_back();
            visited[u] = false;
        }
    }
}

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string var_line, constraint_line;
    bool first_case = true;

    // এন্ড অফ ফাইল (EOF) পর্যন্ত ইনপুট নেওয়া
    while (getline(cin, var_line)) {
        if (getline(cin, constraint_line)) {
            
            // UVa-এর নিয়ম অনুযায়ী দুটি কেসের মাঝে একটি খালি লাইন প্রিন্ট করতে হবে
            if (!first_case) {
                cout << "\n";
            }
            first_case = false;

            // ডাটা স্ট্রাকচারগুলো রিসেট করা
            variables.clear();
            adj.clear();
            in_degree.clear();
            visited.clear();
            current_path = "";

            // ১. ভেরিয়েবলগুলো ইনপুট নেওয়া
            stringstream ss1(var_line);
            char ch;
            while (ss1 >> ch) {
                variables.push_back(ch);
                in_degree[ch] = 0;
                visited[ch] = false;
            }

            // বর্ণানুক্রমিক আউটপুট নিশ্চিত করতে ভেরিয়েবলগুলো সর্ট করা হলো
            sort(variables.begin(), variables.end());

            // ২. শর্ত বা কনস্ট্রেইন্টগুলো ইনপুট নেওয়া (যেমন: x y মানে x < y)
            stringstream ss2(constraint_line);
            char u, v;
            while (ss2 >> u >> v) {
                adj[u].push_back(v);
                in_degree[v]++; // v-এর ইন-ডিগ্রী বৃদ্ধি
            }

            // ৩. ব্যাকট্র্যাকিং শুরু করা
            backtrack();
        }
    }

    return 0;
}
