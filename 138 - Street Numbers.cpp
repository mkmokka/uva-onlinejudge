#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // ইনপুট-আউটপুট দ্রুত করার জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N = 2; // সর্বনিম্ন বাড়ি ২ থেকে শুরু (যেহেতু ১ম জোড়া ৮ এবং ৪৯ থেকে শুরু)
    int count = 0;

    // যতক্ষণ না ১০টি জোড়া পাওয়া যাচ্ছে
    while (count < 10) {
        // ডানপাশের যোগফলের সূত্র N * (N + 1) / 2
        long long sum = (N * (N + 1)) / 2;
        
        // C = sqrt(sum)
        long long C = round(sqrt(sum));

        // যদি C এর বর্গ sum এর সমান হয়, তারমানে এটি একটি পূর্ণ বর্গসংখ্যা
        if (C * C == sum) {
            // ১০টি স্পেস চওড়া ব্লকে ডানপাশে এলাইন করে প্রিন্ট করা
            cout << setw(10) << C << setw(10) << N << "\n";
            count++;
        }
        N++;
    }

    return 0;
}
