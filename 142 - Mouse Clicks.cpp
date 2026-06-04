#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Icon {
    int id;
    int x, y;
    bool visible;
};

struct Region {
    char label;
    int x1, y1, x2, y2;
};

// একটি পয়েন্ট কোনো রিজিয়নের ভেতরে বা বর্ডারে আছে কিনা তা চেক করার ফাংশন
bool isInside(int px, int py, const Region& r) {
    return (px >= r.x1 && px <= r.x2 && py >= r.y1 && py <= r.y2);
}

int main() {
    char type;
    vector<Icon> icons;
    vector<Region> regions;
    
    int icon_count = 0;
    char region_label = 'A';

    // ১. ইনপুট প্রসেসিং
    while (cin >> type && type != '#') {
        if (type == 'I') {
            int x, y;
            cin >> x >> y;
            icon_count++;
            icons.push_back({icon_count, x, y, true});
        } 
        else if (type == 'R') {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            regions.push_back({region_label, x1, y1, x2, y2});
            region_label++;
        } 
        else if (type == 'M') {
            int cx, cy;
            cin >> cx >> cy;

            // প্রথমে আইকনগুলোর ভিজিবিলিটি আপডেট করা (কোনো রিজিয়নের ভেতরে পড়েছে কিনা)
            for (auto& icon : icons) {
                icon.visible = true;
                for (const auto& reg : regions) {
                    if (isInside(icon.x, icon.y, reg)) {
                        icon.visible = false;
                        break; // একটি রিজিয়নের ভেতরে পড়লেই সেটি ইনভিজিবিল
                    }
                }
            }

            // ২. রিজিয়ন সিলেকশন চেক (উল্টো দিক থেকে, কারণ লেটার রিজিয়ন সামনে থাকে)
            bool region_found = false;
            for (int i = regions.size() - 1; i >= 0; --i) {
                if (isInside(cx, cy, regions[i])) {
                    cout << regions[i].label << "\n";
                    region_found = true;
                    break;
                }
            }

            // ৩. রিজিয়ন না পাওয়া গেলে কাছের ভিজিবিল আইকন খোঁজা
            if (!region_found) {
                long long min_dist = -1;
                vector<int> selected_icons;

                for (const auto& icon : icons) {
                    if (!icon.visible) continue; // ঢাকা পড়া আইকন বাদ

                    long long dist = (long long)(icon.x - cx) * (icon.x - cx) + 
                                     (long long)(icon.y - cy) * (icon.y - cy);

                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        selected_icons.clear();
                        selected_icons.push_back(icon.id);
                    } else if (dist == min_dist) {
                        selected_icons.push_back(icon.id);
                    }
                }

                // আইকন সিলেকশনের সঠিক আউটপুট ফরম্যাটিং (Right-aligned with width 3)
                for (int id : selected_icons) {
                    cout << setw(3) << id;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
