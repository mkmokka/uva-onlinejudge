#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ইনপুট এবং আউটপুট দ্রুত করার জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    int cases = 0;

    // ফাইলের শেষ পর্যন্ত k এর মান ইনপুট নেওয়া
    while (cin >> K) {
        // দুটি টেস্ট কেসের আউটপুটের মাঝে একটি খালি লাইন প্রিন্ট করার জন্য
        if (cases++ > 0) {
            cout << "\n";
        }

        int m = K - 1;

        // ১ম ধাপ: প্রথম K টি লাইনের কম্বিনেশন জেনারেট করা
        for (int i = 0; i < K; i++) {
            cout << 1;
            for (int j = 1; j < K; j++) {
                cout << " " << (i * m + j + 1);
            }
            cout << "\n";
        }

        // ২য় ধাপ: বাকি (m * m) লাইনের কম্বিনেশন জেনারেট করা
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << (i + 2);
                for (int s = 0; s < m; s++) {
                    int val = (j + s * i) % m + s * m + K + 1;
                    cout << " " << val;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
