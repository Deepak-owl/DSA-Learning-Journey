#include <iostream>
#include <string>
using namespace std;

long long countSalutes(string str) {
    int n = str.length();
    long long totalSalutes = 0;
    int rightLeftCount = 0; // Count of < to the right

    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == '<') {
            rightLeftCount++;
        } else if(str[i] == '>') {
            totalSalutes += rightLeftCount;
        }
    }

    return totalSalutes;
}

int main() {
    string str = ">>><<";
    long long result = countSalutes(str);
    cout << "Total salutes: " << result << endl;
    return 0;
}



// Explanation
// Initial Count: Count all < (e.g., 2 in ">>><<").
// Traversal:
// i = 0, '>': 2 < to right, add 2 to totalSalutes.
// i = 1, '>': 2 < to right, add 2.
// i = 2, '>': 2 < to right, add 2.
// i = 3, '<': Decrease leftCount to 1 (passed one <).
// i = 4, '<': Decrease leftCount to 0.
// Result: totalSalutes = 2 + 2 + 2 = 6.
// Time Complexity: O(n) – Two passes through the string (can be combined into one, but kept separate for clarity).