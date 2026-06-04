#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

// প্রতিটি আউটপুট লাইনের তথ্য জমা রাখার স্ট্রাকচার
struct Entry {
    string keyword;
    string line;
    int index; // ইনপুট অর্ডার ঠিক রাখার জন্য (Stable Sort-এর বিকল্প)

    // প্রথমে কিওয়ার্ড অনুযায়ী, কিওয়ার্ড এক হলে ইনপুট অর্ডার অনুযায়ী সাজানো হবে
    bool operator<(const Entry& other) const {
        if (keyword != other.keyword) {
            return keyword < other.keyword;
        }
        return index < other.index;
    }
};

// একটি স্ট্রিংকে সম্পূর্ণ ছোট হাতের অক্ষরে রূপান্তর করার ফাংশন
string to_lower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> ignore_words;
    string word;

    // ১. 'ignore' শব্দগুলো ইনপুট নেওয়া
    while (cin >> word && word != "::") {
        ignore_words.insert(to_lower(word));
    }
    cin.ignore(); // বাফার পরিষ্কার করার জন্য

    vector<Entry> results;
    string title;
    int title_count = 0;

    // ২. টাইটেলগুলো ইনপুট নেওয়া এবং প্রসেস করা
    while (getline(cin, title)) {
        if (title.empty()) continue;
        
        title = to_lower(title);
        vector<string> words;
        string current_word = "";

        // টাইটেল থেকে শব্দগুলো আলাদা করা
        for (char c : title) {
            if (isalpha(c)) {
                current_word += c;
            } else {
                if (!current_word.empty()) {
                    words.push_back(current_word);
                    current_word = "";
                }
            }
        }
        if (!current_word.empty()) {
            words.push_back(current_word);
        }

        // প্রতিটি শব্দ কিওয়ার্ড কি না তা চেক করা
        for (size_t i = 0; i < words.size(); ++i) {
            if (ignore_words.find(words[i]) == ignore_words.end()) {
                // এটি একটি বৈধ কিওয়ার্ড, তাই আউটপুট লাইন তৈরি করি
                string formatted_line = "";
                size_t word_index = 0;
                string temp_word = "";

                // মূল টাইটেলটি আবার স্ক্যান করে কিওয়ার্ডটিকে বড় হাতের অক্ষরে রূপান্তর করা
                for (char c : title) {
                    if (isalpha(c)) {
                        temp_word += c;
                    } else {
                        if (!temp_word.empty()) {
                            if (word_index == i) {
                                for (char &tc : temp_word) tc = toupper(tc);
                            }
                            formatted_line += temp_word;
                            temp_word = "";
                            word_index++;
                        }
                        formatted_line += c;
                    }
                }
                if (!temp_word.empty()) {
                    if (word_index == i) {
                        for (char &tc : temp_word) tc = toupper(tc);
                    }
                    formatted_line += temp_word;
                }

                // রেজাল্ট ভেক্টরে পুশ করা
                Entry e;
                e.keyword = words[i];
                e.line = formatted_line;
                e.index = title_count++;
                results.push_back(e);
            }
        }
    }

    // ৩. কিওয়ার্ড অনুযায়ী সর্ট করা
    sort(results.begin(), results.end());

    // ৪. ফাইনাল আউটপুট প্রিন্ট করা
    for (const auto& entry : results) {
        cout << entry.line << "\n";
    }

    return 0;
}
