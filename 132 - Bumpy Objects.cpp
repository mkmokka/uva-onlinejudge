#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    int id; // মূল বহভুজের ১-ভিত্তিক ইনডেক্স রাখার জন্য
    
    bool operator<(const Point& other) const {
        if (abs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
};

// ক্রস প্রোডাক্ট (Cross Product)
double cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// ডট প্রোডাক্ট (Dot Product)
double dot(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.x - A.x) + (B.y - A.y) * (C.y - A.y);
}

// একটি বিন্দু কোনো রেখাংশের ওপর আছে কিনা তা পরীক্ষা করা
bool onSegment(const Point& A, const Point& B, const Point& C) {
    return abs(cross(A, B, C)) < EPS && dot(A, B, C) >= -EPS && dot(B, A, C) >= -EPS;
}

// Andrew's Monotone Chain অ্যালগরিদম দিয়ে Convex Hull তৈরি
vector<Point> getConvexHull(vector<Point> P) {
    int n = P.size(), k = 0;
    if (n <= 3) return P;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end());
    
    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= EPS) k--;
        H[k++] = P[i];
    }
    // Upper hull
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= EPS) k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
    return H;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string objectName;
    while (cin >> objectName && objectName != "#") {
        Point massCenter;
        cin >> massCenter.x >> massCenter.y;
        
        vector<Point> originalPoints;
        double x, y;
        int index = 1;
        
        while (cin >> x >> y && (x != 0 || y != 0)) {
            Point p = {x, y, index++};
            originalPoints.push_back(p);
        }
        
        // Convex hull তৈরি করা
        vector<Point> hull = getConvexHull(originalPoints);
        int hullSize = hull.size();
        
        int minBaseLineIndex = 1e9; // ইনফিনিটি সেট করা
        
        // Convex Hull এর প্রতিটি বাহু পরীক্ষা করা
        for (int i = 0; i < hullSize; ++i) {
            Point A = hull[i];
            Point B = hull[(i + 1) % hullSize];
            
            // কেন্দ্রবিন্দুটি রেখাংশ AB এর লম্বালম্বি ভেতরে আছে কিনা পরীক্ষা
            if (dot(A, B, massCenter) >= -EPS && dot(B, A, massCenter) >= -EPS) {
                int maxCurrentIndex = -1;
                
                // মূল বহুভুজের কোন কোন বিন্দু এই বেস লাইনে পড়ছে তা দেখা
                for (const auto& p : originalPoints) {
                    if (onSegment(A, B, p)) {
                        maxCurrentIndex = max(maxCurrentIndex, p.id);
                    }
                }
                
                // সব সম্ভাব্য স্থিতিশীল অবস্থানের মধ্যে সর্বনিম্নটি নেওয়া
                if (maxCurrentIndex != -1) {
                    minBaseLineIndex = min(minBaseLineIndex, maxCurrentIndex);
                }
            }
        }
        
        // UVa ফরম্যাট অনুযায়ী আউটপুট প্রিন্ট করা (নামের জন্য ২০টি ক্যারেক্টার স্পেস বামে এলাইন করা)
        cout << left << setw(20) << objectName << minBaseLineIndex << "\n";
    }
    
    return 0;
}
