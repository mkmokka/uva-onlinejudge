#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to print a term with the correct sign (+ or -) and 3 decimal places
void printTerm(double val, char var) {
    if (abs(val) < 1e-9) return; // Skip if coefficient is zero
    
    if (val >= 0) {
        cout << " + " << fixed << setprecision(3) << val << var;
    } else {
        cout << " - " << fixed << setprecision(3) << abs(val) << var;
    }
}

// Function to print the general equation constant term
void printConstant(double val) {
    if (abs(val) < 1e-9) return;
    
    if (val >= 0) {
        cout << " + " << fixed << setprecision(3) << val;
    } else {
        cout << " - " << fixed << setprecision(3) << abs(val);
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x1, y1, x2, y2, x3, y3;
    
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        // Calculate determinants to find the circle center using Cramer's rule
        // Reference lines equations from perpendicular bisectors:
        // 2x(x1 - x2) + 2y(y1 - y2) = (x1^2 + y1^2) - (x2^2 + y2^2)
        // 2x(x2 - x3) + 2y(y2 - y3) = (x2^2 + y2^2) - (x3^2 + y3^2)
        
        double a1 = 2 * (x1 - x2);
        double b1 = 2 * (y1 - y2);
        double c1 = (x1 * x1 + y1 * y1) - (x2 * x2 + y2 * y2);
        
        double a2 = 2 * (x2 - x3);
        double b2 = 2 * (y2 - y3);
        double c2 = (x2 * x2 + y2 * y2) - (x3 * x3 + y3 * y3);
        
        double det = a1 * b2 - a2 * b1;
        
        // Compute center (h, k)
        double h = (c1 * b2 - c2 * b1) / det;
        double k = (a1 * c2 - a2 * c1) / det;
        
        // Compute radius r squared
        double r2 = (x1 - h) * (x1 - h) + (y1 - k) * (y1 - k);
        double r = sqrt(r2);
        
        // 1. Output Standard Form: (x - h)^2 + (y - k)^2 = r^2
        if (h >= 0) {
            cout << "(x - " << fixed << setprecision(3) << h << ")^2";
        } else {
            cout << "(x + " << fixed << setprecision(3) << abs(h) << ")^2";
        }
        
        if (k >= 0) {
            cout << " + (y - " << fixed << setprecision(3) << k << ")^2";
        } else {
            cout << " + (y + " << fixed << setprecision(3) << abs(k) << ")^2";
        }
        
        cout << " = " << fixed << setprecision(3) << r << "^2\n";
        
        // 2. Output General Form: x^2 + y^2 + cx + dy + e = 0
        // Expanding (x-h)^2 + (y-k)^2 = r^2 yields: x^2 + y^2 - 2hx - 2ky + (h^2 + k^2 - r^2) = 0
        double c_gen = -2 * h;
        double d_gen = -2 * k;
        double e_gen = h * h + k * k - r2;
        
        cout << "x^2 + y^2";
        printTerm(c_gen, 'x');
        printTerm(d_gen, 'y');
        printConstant(e_gen);
        cout << " = 0\n\n"; // Double newline required between test cases
    }
    
    return 0;
}
