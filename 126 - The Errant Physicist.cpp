#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

struct Term {
    int coeff, px, py;
    
    // সর্টিং নিয়ম: x এর পাওয়ার বড় থেকে ছোট, তারপর y এর পাওয়ার ছোট থেকে বড়
    bool operator<(const Term& other) const {
        if (px != other.px) return px > other.px;
        return py < other.py;
    }
};

// স্ট্রিং এর ডানপাশের ট্রেইলিং স্পেস দূর করার হেল্পার ফাংশন
string trim_right(string s) {
    while (!s.empty() && s.back() == ' ') {
        s.pop_back();
    }
    return s;
}

vector<Term> parse(string s) {
    vector<Term> terms;
    int i = 0, n = s.length();
    
    while (i < n) {
        int sign = 1;
        if (s[i] == '+') { sign = 1; i++; }
        else if (s[i] == '-') { sign = -1; i++; }
        
        int coeff = 0;
        bool has_coeff = false;
        while (i < n && isdigit(s[i])) {
            coeff = coeff * 10 + (s[i] - '0');
            has_coeff = true;
            i++;
        }
        if (!has_coeff) coeff = 1;
        coeff *= sign;
        
        int px = 0, py = 0;
        for (int k = 0; k < 2; k++) {
            if (i < n && s[i] == 'x') {
                i++;
                if (i < n && isdigit(s[i])) {
                    while (i < n && isdigit(s[i])) {
                        px = px * 10 + (s[i] - '0');
                        i++;
                    }
                } else {
                    px = 1;
                }
            }
            if (i < n && s[i] == 'y') {
                i++;
                if (i < n && isdigit(s[i])) {
                    while (i < n && isdigit(s[i])) {
                        py = py * 10 + (s[i] - '0');
                        i++;
                    }
                } else {
                    py = 1;
                }
            }
        }
        terms.push_back({coeff, px, py});
    }
    return terms;
}

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    while (cin >> s1 && s1 != "#") {
        cin >> s2;
        
        vector<Term> p1 = parse(s1);
        vector<Term> p2 = parse(s2);
        
        map<pair<int, int>, int> combined;
        for (auto& t1 : p1) {
            for (auto& t2 : p2) {
                combined[{t1.px + t2.px, t1.py + t2.py}] += t1.coeff * t2.coeff;
            }
        }
        
        vector<Term> result;
        for (auto& it : combined) {
            if (it.second != 0) {
                result.push_back({it.second, it.first.first, it.first.second});
            }
        }
        
        if (result.empty()) {
            cout << "\n0\n";
            continue;
        }
        
        sort(result.begin(), result.end());
        
        string line1 = "", line2 = "";
        
        for (size_t i = 0; i < result.size(); i++) {
            Term t = result[i];
            
            // পদের মাঝখানের সাইন এবং স্পেসিং হ্যান্ডেলিং
            if (i > 0) {
                if (t.coeff > 0) {
                    line2 += " + ";
                    line1 += "   ";
                } else {
                    line2 += " - ";
                    line1 += "   ";
                    t.coeff = -t.coeff;
                }
            } else {
                if (t.coeff < 0) {
                    line2 += "-";
                    line1 += " ";
                    t.coeff = -t.coeff;
                }
            }
            
            // সহগ (Coefficient) বসানো
            if (t.coeff != 1 || (t.px == 0 && t.py == 0)) {
                string c_str = to_string(t.coeff);
                line2 += c_str;
                line1 += string(c_str.length(), ' ');
            }
            
            // X ভেরিয়েবল ও পাওয়ার
            if (t.px > 0) {
                line2 += "x";
                line1 += " ";
                if (t.px > 1) {
                    string e_str = to_string(t.px);
                    line1 += e_str;
                    line2 += string(e_str.length(), ' ');
                }
            }
            
            // Y ভেরিয়েবল ও পাওয়ার
            if (t.py > 0) {
                line2 += "y";
                line1 += " ";
                if (t.py > 1) {
                    string e_str = to_string(t.py);
                    line1 += e_str;
                    line2 += string(e_str.length(), ' ');
                }
            }
        }
        
        // ট্রেইলিং স্পেস ট্রিম করার মূল সংশোধন অংশ
        // ১. প্রথমে দুই লাইনেরই একদম ডানপাশের বাড়তি স্পেস কেটে নেওয়া হলো
        line1 = trim_right(line1);
        line2 = trim_right(line2);
        
        // ২. দুই লাইনের দৈর্ঘ্য তুলনা করে ছোট লাইনের শেষে স্পেস প্যাডিং করা হলো
        size_t max_len = max(line1.length(), line2.length());
        if (line1.length() < max_len) line1 += string(max_len - line1.length(), ' ');
        if (line2.length() < max_len) line2 += string(max_len - line2.length(), ' ');
        
        // ৩. এখন নিখুঁত সমদৈর্ঘ্যের লাইন দুটি আউটপুট দেওয়া হলো
        cout << line1 << "\n";
        cout << line2 << "\n";
    }
    return 0;
}
