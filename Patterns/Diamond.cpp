// Row 0: 00 01 02 03 04 05 06 07 08
// Row 1: 10 11 12 13 14 15 16 17 18
// Row 2: 20 21 22 23 24 25 26 27 28
// Row 3: 30 31 32 33 34 35 36 37 38
// Row 4: 40 41 42 43 44 45 46 47 48
// Row 5: 50 51 52 53 54 55 56 57 58
// Row 6: 60 61 62 63 64 65 66 67 68
// Row 7: 70 71 72 73 74 75 76 77 78
// Row 8: 80 81 82 83 84 85 86 87 88

// Row 0:     *       (1 *,  4 spaces: 04)
// Row 1:    ***      (3 *,  3 spaces: 13 14 15)
// Row 2:   *****     (5 *,  2 spaces: 22 23 24 25 26)
// Row 3:  *******    (7 *,  1 space:  31 32 33 34 35 36 37)
// Row 4: *********   (9 *,  0 spaces: 40 41 42 43 44 45 46 47 48)
// Row 5:  *******    (7 *,  1 space:  51 52 53 54 55 56 57)
// Row 6:   *****     (5 *,  2 spaces: 62 63 64 65 66)
// Row 7:    ***      (3 *,  3 spaces: 73 74 75)
// Row 8:     *       (1 *,  4 spaces: 84)


#include <iostream>
using namespace std;

void printDiamond(int n) {
    // Upper half (including middle row)
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        // Print leading spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the upper half: ";
    cin >> n;
    printDiamond(n);
    return 0;
}