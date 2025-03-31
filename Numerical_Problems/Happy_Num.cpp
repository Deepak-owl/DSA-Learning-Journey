// Problem: Determine if a number is a "happy number" (sum of squares of digits eventually reaches 1).
// Example: Input: 19 → Output: True (1² + 9² = 82, 8² + 2² = 68, 6² + 8² = 100, 1² + 0² + 0² = 1).

#include <iostream>
#include <unordered_set>
using namespace std;

// Helper function to compute sum of squares of digits
int getSumOfSquares(int num) {
    int sum = 0;
    while(num > 0) {
        int digit = num % 10;     // Extract digit
        sum += digit * digit;     // Square and add
        num /= 10;                // Remove digit
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen; // To detect cycles
    int num = n;

    while(num != 1 && seen.find(num) == seen.end()) {
        seen.insert(num);              // Track number
        num = getSumOfSquares(num);    // Get next sum
    }

    return num == 1; // True if we reach 1, False if cycle detected
}

int main() {
    int n = 19;
    bool result = isHappy(n);
    cout << "Is " << n << " a happy number? " << (result ? "True" : "False") << endl;
    return 0;
}   

// Time Complexity: O(log n) average case – The number of digits reduces with each step, and cycles are detected quickly. Worst case depends on cycle length.

// Space Complexity: O(log n) – Size of the set storing intermediate sums.

// another approach

// #include <iostream>
// using namespace std;

// int getSumOfSquares(int num) {
//     int sum = 0;
//     while(num > 0) {
//         int digit = num % 10;
//         sum += digit * digit;
//         num /= 10;
//     }
//     return sum;
// }

// bool isHappy(int n) {
//     int slow = n;
//     int fast = getSumOfSquares(n);

//     while(fast != 1 && slow != fast) {
//         slow = getSumOfSquares(slow);          // Move one step
//         fast = getSumOfSquares(getSumOfSquares(fast)); // Move two steps
//     }

//     return fast == 1;
// }

// int main() {
//     int n = 19;
//     bool result = isHappy(n);
//     cout << "Is " << n << " a happy number? " << (result ? "True" : "False") << endl;
//     return 0;
// }



// Execution:
// Initial: slow = 19, fast = 82 (one step from 19).
// fast != 1 and slow != fast → Continue.
// Step 1:
// slow = 82 (one step: 19 → 82).
// fast = 68 (two steps: 82 → 68).
// fast != 1, 19 != 82 → Continue.
// Step 2:
// slow = 68 (82 → 68).
// fast = 1 (68 → 100 → 1).
// fast == 1 → Exit loop.
// Result: return fast == 1, so true.
// Why It Stops: Fast hits 1, indicating the sequence terminates at 1 (happy).
// Example: 23 (Not Happy)
// Sequence: 23 → 13 → 10 → 1 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 → 16 (cycle at 4).
// Execution:
// slow = 23, fast = 13.
// slow = 13, fast = 1 (13 → 10 → 1).
// slow = 10, fast = 16 (1 → 4 → 16).
// slow = 1, fast = 58 (16 → 37 → 58).
// slow = 4, fast = 145 (58 → 89 → 145).
// slow = 16, fast = 20 (145 → 42 → 20).
// slow = 37, fast = 16 (20 → 4 → 16).
// slow = 58, fast = 58 (16 → 37 → 58).
// slow == fast → Cycle detected.
// Result: fast != 1, so false.