#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ইনপুট-আউটপুট দ্রুত করার জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target = 1500;
    vector<long long> ugly(target);
    ugly[0] = 1; // ১ম Ugly Number

    int p2 = 0, p3 = 0, p5 = 0;

    for (int i = 1; i < target; i++) {
        long long next2 = ugly[p2] * 2;
        long long next3 = ugly[p3] * 3;
        long long next5 = ugly[p5] * 5;

        // সর্বনিম্ন মানটি খুঁজে বের করা
        long long next_ugly = min({next2, next3, next5});
        ugly[i] = next_ugly;

        // পয়েন্টার আপডেট করা (ডুপ্লিকেট এড়াতে if-else এর বদলে আলাদা if ব্যবহার করা হয়েছে)
        if (next_ugly == next2) p2++;
        if (next_ugly == next3) p3++;
        if (next_ugly == next5) p5++;
    }

    // নির্দিষ্ট ফরম্যাট অনুযায়ী আউটপুট প্রিন্ট করা
    cout << "The 1500'th ugly number is " << ugly[target - 1] << ".\n";

    return 0;
}
