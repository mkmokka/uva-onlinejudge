#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
};

// বহুভুজের সাইনড ক্ষেত্রফল নির্ণয় (Shoelace Formula)
double getSignedArea(const vector<Point>& p) {
    double area = 0.0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}

// বিন্দু ও রেখার ওরিয়েন্টেশন চেক (কাউন্টার-ক্লকওয়াইজ হলে রেখার বামে থাকবে)
bool isInside(Point p, Point p1, Point p2) {
    return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x) >= -EPS;
}

// দুটি লাইনের নিখুঁত ইন্টারসেকশন পয়েন্ট বের করা
Point getIntersection(Point a1, Point a2, Point b1, Point b2) {
    double A1 = a2.y - a1.y;
    double B1 = a1.x - a2.x;
    double C1 = A1 * a1.x + B1 * a1.y;

    double A2 = b2.y - b1.y;
    double B2 = b1.x - b2.x;
    double C2 = A2 * b1.x + B2 * b1.y;

    double det = A1 * B2 - A2 * B1;
    return { (B2 * C1 - B1 * C2) / det, (A1 * C2 - A2 * C1) / det };
}

// সাদারল্যান্ড-হজম্যান ক্লিপিং সাব-রুটিন
vector<Point> clipPolygon(const vector<Point>& poly, Point p1, Point p2) {
    vector<Point> clipped;
    int n = poly.size();
    if (n == 0) return clipped;

    Point s = poly[n - 1];
    for (int i = 0; i < n; i++) {
        Point p = poly[i];
        if (isInside(p, p1, p2)) {
            if (!isInside(s, p1, p2)) {
                clipped.push_back(getIntersection(p1, p2, s, p));
            }
            clipped.push_back(p);
        } else if (isInside(s, p1, p2)) {
            clipped.push_back(getIntersection(p1, p2, s, p));
        }
        s = p;
    }
    return clipped;
}

// দুই পলিগনের ইন্টারসেকশন পলিগন জেনারেট করা
vector<Point> getIntersectionPolygon(const vector<Point>& poly1, const vector<Point>& poly2) {
    vector<Point> result = poly1;
    int n = poly2.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        result = clipPolygon(result, poly2[i], poly2[j]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    while (cin >> n1 && n1 != 0) {
        vector<Point> poly1(n1);
        for (int i = 0; i < n1; i++) cin >> poly1[i].x >> poly1[i].y;

        cin >> n2;
        vector<Point> poly2(n2);
        for (int i = 0; i < n2; i++) cin >> poly2[i].x >> poly2[i].y;

        // ওরিয়েন্টেশন ফিক্সিং: ক্লকওয়াইজ থাকলে রিভার্স করে কাউন্টার-ক্লকওয়াইজ করা
        double sArea1 = getSignedArea(poly1);
        if (sArea1 < 0) {
            reverse(poly1.begin(), poly1.end());
            sArea1 = -sArea1;
        }

        double sArea2 = getSignedArea(poly2);
        if (sArea2 < 0) {
            reverse(poly2.begin(), poly2.end());
            sArea2 = -sArea2;
        }

        // সাধারণ ইন্টারসেকশন অংশের ক্ষেত্রফল নির্ণয়
        vector<Point> interPoly = getIntersectionPolygon(poly1, poly2);
        double interArea = abs(getSignedArea(interPoly));

        // Symmetric Difference / XOR Area ফর্মুলা
        double ans = sArea1 + sArea2 - 2.0 * interArea;

        // UVa ফরম্যাট অনুযায়ী স্পেস ছাড়া টানা ৮-ডিজিটের উইডথ ব্লকে আউটপুট প্রিন্ট করা
        cout << fixed << setprecision(2) << setw(8) << ans;
    }
    cout << "\n"; // সকল কেস সমাপ্তির পর সিঙ্গেল নিউলাইন

    return 0;
}
