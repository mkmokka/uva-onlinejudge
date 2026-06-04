#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    int balance;
};

int main() {
    int n, k;
    
    // Read input until N = 0 and K = 0
    while (cin >> n >> k && (n || k)) {
        queue<Student> q;
        for (int i = 1; i <= n; ++i) {
            q.push({i, 0});
        }

        int current_dispenser_limit = 1; // Machine starts by dispensing up to $1
        int current_hand_money = 0;      // Money currently held by the machine's dispenser mechanism

        while (!q.empty()) {
            // If the machine's hand is empty, generate the next payout amount
            if (current_hand_money == 0) {
                current_hand_money = current_dispenser_limit;
                current_dispenser_limit++;
                if (current_dispenser_limit > k) {
                    current_dispenser_limit = 1; // Reset back to $1 after reaching $k
                }
            }

            Student current_student = q.front();
            q.pop();

            int needed = 40 - current_student.balance;

            if (current_hand_money >= needed) {
                // Machine has enough or more money than the student needs
                current_hand_money -= needed; 
                // Student finishes and leaves the queue. Output their ID right-justified in 3 spaces.
                cout << setw(3) << current_student.id;
            } else {
                // Student takes all money in machine's hand but still needs more
                current_student.balance += current_hand_money;
                current_hand_money = 0;
                q.push(current_student); // Moves to the back of the line
            }
        }
        cout << endl; // New line after processing the entire batch of students
    }

    return 0;
}
