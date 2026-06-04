#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    // ইনপুট এবং আউটপুট দ্রুত করার জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, k, m;
    while (cin >> N >> k >> m && (N != 0 || k != 0 || m != 0)) {
        vector<bool> in_queue(N + 1, true); // ১-ভিত্তিক ইনডেক্সিং
        int remaining = N;

        // ঘড়ির কাঁটার দিকের (CW) শুরুর অবস্থান ১ এর বামে (অর্থাৎ N) 
        // ঘড়ির কাঁটার বিপরীত দিকের (CCW) শুরুর অবস্থান N এর ডানে (অর্থাৎ ১)
        int p1 = N; 
        int p2 = 1;

        bool first_output = true;

        while (remaining > 0) {
            // ১. ঘড়ির কাঁটার দিকে (Clockwise) k-তম সক্রিয় ব্যক্তি খোঁজা
            int count1 = 0;
            while (count1 < k) {
                p1 = (p1 % N) + 1; // পরবর্তী অবস্থানে যাওয়া (১ থেকে N)
                if (in_queue[p1]) {
                    count1++;
                }
            }

            // ২. ঘড়ির কাঁটার বিপরীত দিকে (Counter-Clockwise) m-তম সক্রিয় ব্যক্তি খোঁজা
            int count2 = 0;
            while (count2 < m) {
                p2 = p2 - 1;
                if (p2 == 0) p2 = N; // বৃত্তাকার ঘূর্ণন ঠিক রাখা
                if (in_queue[p2]) {
                    count2++;
                }
            }

            // কমা ফরম্যাটিং
            if (!first_output) {
                cout << ",";
            }
            first_output = false;

            // ৩. এলিমিনেশন এবং আউটপুট প্রিন্ট
            if (p1 == p2) {
                // দুজনেই একই ব্যক্তিকে সিলেক্ট করলে
                cout << setw(3) << p1;
                in_queue[p1] = false;
                remaining--;
            } else {
                // আলাদা দুজনকে সিলেক্ট করলে
                cout << setw(3) << p1 << setw(3) << p2;
                in_queue[p1] = false;
                in_queue[p2] = false;
                remaining -= 2;
            }
        }
        cout << "\n";
    }

    return 0;
}
