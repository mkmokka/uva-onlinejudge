#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, l;
int current_count;
string result_str;
bool found;

// বর্তমান স্ট্রিংটি "Easy" কি না তা পরীক্ষা করার ফাংশন
bool is_easy(const string& s) {
    int len = s.length();
    for (int i = 1; i <= len / 2; ++i) {
        if (s.substr(len - i) == s.substr(len - 2 * i, i)) {
            return false; // পরপর দুটি সাব-স্ট্রিং মিলে গেলে এটি "Hard"
        }
    }
    return true;
}

// ব্যাকট্র্যাকিং এর মূল ফাংশন
bool backtrack(string& current) {
    if (current_count == n) {
        result_str = current;
        return true;
    }

    for (int i = 0; i < l; ++i) {
        current.push_back('A' + i);
        if (is_easy(current)) {
            current_count++;
            if (backtrack(current)) return true;
        }
        current.pop_back();
    }
    return false;
}

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> l && (n != 0 || l != 0)) {
        current_count = 0;
        string current = "";
        result_str = "";

        // ব্যাকট্র্যাকিং রান করা
        backtrack(current);

        // জাজ-টেস্টেড নিখুঁত আউটপুট ফরম্যাটিং (PE ফিক্স করার মূল অংশ)
        int len = result_str.length();
        for (int i = 0; i < len; ++i) {
            cout << result_str[i];
            
            // যদি এটি লাইনের শেষ ক্যারেক্টার হয় অথবা ঠিক ৬৪ নম্বর ক্যারেক্টার হয় (৪ ক্যারেক্টারের ১৫টি ব্লক = ৬০ অক্ষরের পর স্পেসসহ ৬৪তম কলাম)
            // জাজের স্ট্যান্ডার্ড ভিউ অনুযায়ী ৬০ ক্যারেক্টার বা ১৫টি ব্লকের পর নতুন লাইন দিতে হয়।
            if (i == len - 1 || i % 64 == 63) {
                cout << "\n";
            } 
            // প্রতি ৪টি ক্যারেক্টার পর স্পেস হবে (তবে ব্লকের শেষে নয়)
            else if (i % 4 == 3) {
                cout << " ";
            }
        }
        
        // পরিশেষে দৈর্ঘ্য প্রিন্ট করা (এখানে অতিরিক্ত কোনো ফাঁকা লাইন তৈরি হবে না)
        cout << len << "\n";
    }

    return 0;
}
