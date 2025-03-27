// Row 0: *  *  *  *  *   (top border)
// Row 1: *           *   (left and right borders)
// Row 2: *           *   (left and right borders)
// Row 3: *           *   (left and right borders)
// Row 4: *  *  *  *  *   (bottom border)

// Row 0: 00 01 02 03 04
// Row 1: 10          14
// Row 2: 20          24
// Row 3: 30          34
// Row 4: 40 41 42 43 44

#include <iostream>
using namespace std;

void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {         // i = row number (0 to n-1)
        for (int j = 0; j < n; j++) {     // j = column number (0 to n-1)
            // Print * if it's the first/last row or first/last column
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "* ";
            } else {
                cout << "  ";             // Two spaces to align with "* "
            }
        }
        cout << endl;                     // New line after each row
    }
}

int main() {
    int n;
    cout << "Enter the size of the square: ";
    cin >> n;
    printHollowSquare(n);
    return 0;
}