// Row 0: 00 01 02 03 04
// Row 1: 10 11 12 13 14
// Row 2: 20 21 22 23 24
// Row 3: 30 31 32 33 34
// Row 4: 40 41 42 43 44

// Row 0: *  *  *  *  *   (5 - 0 = 5 columns)
// Row 1: *  *  *  *      (5 - 1 = 4 columns)
// Row 2: *  *  *         (5 - 2 = 3 columns)
// Row 3: *  *            (5 - 3 = 2 columns)
// Row 4: *               (5 - 4 = 1 column)

#include <iostream>
using namespace std;

void printInvertedTriangle(int n) {
    for (int i = 0; i < n; i++) {         // i = row number (0 to n-1)
        for (int j = 0; j < n - i; j++) { // j = column number, prints * up to n - i
            cout << "* ";
        }
        cout << endl;                      // New line after each row
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printInvertedTriangle(n);
    return 0;
}