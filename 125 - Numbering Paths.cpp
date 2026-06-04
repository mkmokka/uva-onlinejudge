#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int matrix[35][35];

int main() {
    // দ্রুত ইনপুট-আউটপুটের জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int edge_count;
    int case_num = 0;

    while (cin >> edge_count) {
        // ম্যাট্রিক্স সম্পূর্ণ শূন্য দিয়ে রিসেট করা
        memset(matrix, 0, sizeof(matrix));
        
        int max_node = -1; // শুরুতে -1 রাখা হলো যেন ০ এজের ক্ষেত্রে হ্যান্ডেল করা যায়

        for (int i = 0; i < edge_count; ++i) {
            int u, v;
            cin >> u >> v;
            matrix[u][v] = 1; 
            max_node = max({max_node, u, v});
        }

        // যদি কোনো এজ না থাকে (edge_count = 0), তবুও সর্বোচ্চ নোড অন্তত ০ ধরে নিতে হবে
        if (max_node < 0) {
            max_node = 0; 
        }

        // ১. মডিফাইড ফ্লয়েড-ওয়ারশ: পথ সংখ্যা গণনা
        for (int k = 0; k <= max_node; ++k) {
            for (int i = 0; i <= max_node; ++i) {
                for (int j = 0; j <= max_node; ++j) {
                    if (matrix[i][k] > 0 && matrix[k][j] > 0) {
                        matrix[i][j] += matrix[i][k] * matrix[k][j];
                    }
                }
            }
        }

        // ২. নিখুঁত সাইকেল বা ইনফিনিটি পাথ সনাক্তকরণ এবং প্রোপাগেশন
        for (int k = 0; k <= max_node; ++k) {
            if (matrix[k][k] > 0) { // k নোডে লুপ/সাইকেল আছে
                for (int i = 0; i <= max_node; ++i) {
                    for (int j = 0; j <= max_node; ++j) {
                        // i থেকে k এবং k থেকে j তে যাওয়ার যেকোনো পথ থাকলেই সেটি অসীম (-1) হবে
                        // এখানে গুণফল != 0 দেওয়া হয়েছে যাতে পূর্বের -1 এর প্রভাবও ছড়িয়ে পড়ে
                        if (matrix[i][k] != 0 && matrix[k][j] != 0) {
                            matrix[i][j] = -1;
                        }
                    }
                }
            }
        }

        // ৩. সঠিক ফরম্যাটে আউটপুট প্রিন্ট করা
        cout << "matrix for city " << case_num++ << "\n";
        for (int i = 0; i <= max_node; ++i) {
            for (int j = 0; j <= max_node; ++j) {
                cout << matrix[i][j];
                if (j < max_node) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
