#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O streams for quick processing
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int origNumerator, denominator;

    // Read successive cases until hitting EOF
    while (cin >> origNumerator >> denominator) {
        int numerator = origNumerator;
        
        // Print the primary base fractional identity line
        cout << numerator << "/" << denominator << " = " << (numerator / denominator) << ".";
        
        numerator %= denominator;
        
        // seenAtPos[rem] maps a remainder 'rem' to the index inside decimalDigits where it was generated
        // Initialize with -1 to flag unvisited states
        vector<int> seenAtPos(denominator + 1, -1);
        string decimalDigits = "";
        
        int cycleStartPos = -1;

        // Perform mock long division manually digit by digit
        while (true) {
            // If the current remainder has been seen before, we found our cycle boundary
            if (seenAtPos[numerator] != -1) {
                cycleStartPos = seenAtPos[numerator];
                break;
            }
            
            // Log the current placement location index
            seenAtPos[numerator] = decimalDigits.length();
            
            numerator *= 10;
            decimalDigits += to_string(numerator / denominator);
            numerator %= denominator;
        }

        // Print the decimal digits up to the first 50 characters max
        for (int i = 0; i < (int)decimalDigits.length(); ++i) {
            if (i == cycleStartPos) {
                cout << "(";
            }
            if (i < 50) {
                cout << decimalDigits[i];
            } else {
                cout << "...";
                break;
            }
        }
        cout << ")\n";

        // Calculate and display total cycle lengths
        int cycleLength = decimalDigits.length() - cycleStartPos;
        cout << "   " << cycleLength << " = number of digits in repeating cycle\n\n";
    }

    return 0;
}
