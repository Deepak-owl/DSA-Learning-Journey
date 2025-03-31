// Row 0: 00 01 02 03 04 05 06 07 08
// Row 1: 10 11 12 13 14 15 16 17 18
// Row 2: 20 21 22 23 24 25 26 27 28
// Row 3: 30 31 32 33 34 35 36 37 38
// Row 4: 40 41 42 43 44 45 46 47 48

// Row 0:     *       (1 *,  4 spaces: 04)
// Row 1:    ***      (3 *,  3 spaces: 13 14 15)
// Row 2:   *****     (5 *,  2 spaces: 22 23 24 25 26)
// Row 3:  *******    (7 *,  1 space:  31 32 33 34 35 36 37)
// Row 4: *********   (9 *,  0 spaces: 40 41 42 43 44 45 46 47 48)

#include <iostream>
using namespace std;

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {              // i = row number (0 to n-1)
        // Print leading spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 0; j < 2 * i + 1; j++) {       //2*i+1
            
            cout << "*";
        }
        cout << endl;                          // New line after each row
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printPyramid(n);
    return 0;
}