#include <iostream>
#include <cctype>

using namespace std;

int target_sum;
bool path_found;

// পরবর্তী ক্যারেক্টার ট্র্যাকিং বাফার
char next_ch = ' ';

// শুধুমাত্র নন-স্পেস ক্যারেক্টার রিড করার ফাংশন
char get_clean_char() {
    char ch;
    while (cin.get(ch)) {
        if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '\t') {
            return ch;
        }
    }
    return EOF;
}

// দ্রুত ট্রি পার্সিং ফাংশন
bool parse_tree(int current_sum) {
    // আগের লুপে পঠিত ক্যারেক্টার না থাকলে নতুন ক্যারেক্টার নিবে (সাধারণত এটি '(' হবে)
    char ch = (next_ch != ' ') ? next_ch : get_clean_char();
    next_ch = ' '; // বাফার ক্লিয়ার
    
    // পরবর্তী ক্যারেক্টারটি কী তা দেখি (সংখ্যার শুরু নাকি খালি ট্রি ')')
    ch = get_clean_char();
    if (ch == ')') {
        return false; // খালি সাব-ট্রি
    }
    
    // চিহ্নের হিসাব (- বা +)
    int sign = 1;
    if (ch == '-') {
        sign = -1;
        ch = get_clean_char();
    }
    
    // ম্যানুয়ালি ফাস্ট নাম্বার পার্সিং
    int value = 0;
    while (isdigit(ch)) {
        value = value * 10 + (ch - '0');
        cin.get(ch); // স্পেসসহ যেকোনো ক্যারেক্টার রিড করবে
    }
    value *= sign;
    
    // 'ch' এখন ডিজিট নয়, এটি অবশ্যই বাম সাব-ট্রির ওপেনিং '(' অথবা হোয়াইটস্পেস হতে পারে
    // তাই একে ক্লিন করে পরবর্তী ভ্যালিড নন-স্পেস ক্যারেক্টার হিসেবে বাফারে রাখবো
    if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
        next_ch = get_clean_char();
    } else {
        next_ch = ch;
    }
    
    current_sum += value;
    
    // বাম ও ডান সাব-ট্রি ভিজিট
    bool left_exists = parse_tree(current_sum);
    bool right_exists = parse_tree(current_sum);
    
    // লিফ নোড চেক
    if (!left_exists && !right_exists) {
        if (current_sum == target_sum) {
            path_found = true;
        }
    }
    
    // বর্তমান নোডের ক্লোজিং ব্র্যাকেট ')' রিমুভ করা
    if (next_ch != ' ') {
        next_ch = ' '; // বাফারে থাকলে তা ড্রপ (যা আসলে ')')
    } else {
        get_clean_char(); 
    }
    
    return true;
}

int main() {
    // C++ স্ট্যান্ডার্ড স্ট্রিমের গতি বাড়ানোর জন্য সর্বোচ্চ অপ্টিমাইজেশন
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> target_sum) {
        path_found = false;
        next_ch = ' '; // প্রতি কেসের শুরুতে বাফার রিসেট
        
        parse_tree(0);
        
        if (path_found) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
