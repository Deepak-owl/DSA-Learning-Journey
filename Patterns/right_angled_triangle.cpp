// Row 0: 00 01 02 03 04
// Row 1: 10 11 12 13 14
// Row 2: 20 21 22 23 24
// Row 3: 30 31 32 33 34
// Row 4: 40 41 42 43 44

// Row 0: *            
// Row 1: *  *         
// Row 2: *  *  *      
// Row 3: *  *  *  *   
// Row 4: *  *  *  *  *

#include <iostream>
using namespace std;

void printTriangle(int n) {
    for (int i = 0; i < n; i++) {         // i = row number (0 to n-1)
        for (int j = 0; j <= i; j++) {    // j = column number, prints * up to j <= i
            cout << "* ";
        }
        cout << endl;                      // New line after each row
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printTriangle(n);
    return 0;
}