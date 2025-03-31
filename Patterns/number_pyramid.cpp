#include <iostream>
using namespace std;

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {              // i = row number (0 to n-1)
        // Print leading spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 0; j <i + 1; j++) {       //2*i+1
            
            cout << i+1<<" ";
        }
        cout << endl;                          // New line after each row
    }
}

int main() {
    int n;
    // cout << "Enter the number of rows: ";
    // cin >> n;
    printPyramid(5);
    return 0;
}