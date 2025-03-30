#include <iostream>
#include <vector>
using namespace std;

void printSpiral(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while(num <= n * n) {
        for(int i = left; i <= right && num <= n * n; i++) {
            matrix[top][i] = num++;
        }
        top++;
        int row = top;
        while(row <= bottom && num <= n * n) {
            matrix[row][right] = num++;
            row++;
        }
        right--;
        for(int i = right; i >= left && num <= n * n; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;
        row = bottom;
        while(row >= top && num <= n * n) {
            matrix[row][left] = num++;
            row--;
        }
        left++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    printSpiral(n);
    return 0;
}

// Boundaries:
// top = 0 (row 0)
// bottom = 2 (row 2)
// left = 0 (column 0)
// right = 2 (column 2)
// num = 1

// T: 0 0 0  (top = 0)
//    0 0 0
// B: 0 0 0  (bottom = 2)
//    L   R
//    0   2