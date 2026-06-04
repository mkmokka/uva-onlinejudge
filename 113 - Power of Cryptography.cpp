#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // দ্রুত I/O এর জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n, p;

    // ইনপুট ফাইল শেষ না হওয়া পর্যন্ত লুপ চলবে
    while (cin >> n >> p) {
        // k = p^(1/n) হিসাব করা হচ্ছে
        double k = pow(p, 1.0 / n);

        // দশমিক অংশ বাদ দিয়ে পূর্ণসংখ্যা প্রিন্ট করার জন্য fixed এবং setprecision(0) ব্যবহার করা হয়েছে
        cout << fixed << setprecision(0) << k << "\n";
    }

    return 0;
}
