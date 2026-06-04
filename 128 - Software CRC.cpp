#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// CRC ডিভাইজর বা জেনারেটর পলিনোমিয়াল মান
const int MOD = 34943;

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // এন্ড অফ ফাইল (EOF) অথবা '#' ক্যারেক্টার না পাওয়া পর্যন্ত ইনপুট নেওয়া
    while (getline(cin, line)) {
        if (!line.empty() && line[0] == '#') {
            break;
        }

        long long current_rem = 0;

        // ১. প্রতিটি ক্যারেক্টারকে ২৫৬ বেসের সংখ্যা ধরে মডুলাস হিসাব করা
        for (char c : line) {
            current_rem = ((current_rem * 256) + (unsigned char)c) % MOD;
        }

        // ২. চেকসামের জন্য ডেটাকে ১৬-বিট বামে শিফট করা (২টি শূন্য বাইট কল্পনা করে)
        current_rem = (current_rem * 256) % MOD;
        current_rem = (current_rem * 256) % MOD;

        // ৩. ৩৪৯৪৩ দ্বারা বিভাজ্য করার জন্য প্রয়োজনীয় মান বা চেকসাম বের করা
        long long crc_checksum = (MOD - current_rem) % MOD;

        // ৪. চেকসামটিকে উচ্চ বাইট এবং নিম্ন বাইটে আলাদা করা
        int high_byte = crc_checksum / 256;
        int low_byte = crc_checksum % 256;

        // ৫. বড় হাতের হেক্সাডেসিমেল ফরম্যাটে ২ ঘর করে প্রিন্ট করা
        // উদাহরণ: সংখ্যা ৫ হলে "05", ১০ হলে "0A" প্রিন্ট হবে
        cout << setfill('0') << setw(2) << hex << uppercase << high_byte << " "
             << setfill('0') << setw(2) << hex << uppercase << low_byte << "\n";
    }

    return 0;
}
