#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check each row
    for (int i = 0; i < 9; i++) {
        unordered_set<char> row;
        for (int j = 0; j < 9; j++) {
            char cell = board[i][j];
            if (cell != '.') { // Skip empty cells
                if (row.count(cell)) return false; // Duplicate found
                row.insert(cell);
            }
        }
    }
    
    // Check each column
    for (int j = 0; j < 9; j++) {
        unordered_set<char> col;
        for (int i = 0; i < 9; i++) {
            char cell = board[i][j];
            if (cell != '.') {
                if (col.count(cell)) return false;
                col.insert(cell);
            }
        }
    }
    
    // Check each 3x3 sub-box
    for (int boxRow = 0; boxRow < 3; boxRow++) {
        for (int boxCol = 0; boxCol < 3; boxCol++) {
            unordered_set<char> box;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = boxRow * 3 + i; // Actual row index
                    int col = boxCol * 3 + j; // Actual col index
                    char cell = board[row][col];
                    if (cell != '.') {
                        if (box.count(cell)) return false;
                        box.insert(cell);
                    }
                }
            }
        }
    }
    
    return true; // No violations found
}

int main() {
    // Example board
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    if (isValidSudoku(board)) {
        cout << "Valid Sudoku" << endl;
    } else {
        cout << "Invalid Sudoku" << endl;
    }
    
    return 0;
}


// Complexity
// Time: O(1) technically, since the board is fixed at 9x9:
// Rows: 9 * 9 = 81 checks.
// Columns: 9 * 9 = 81 checks.
// Sub-boxes: 9 * (3 * 3) = 81 checks.
// Total: 243 operations, constant time.
// Each count/insert is O(1) average with unordered_set.
// Generalized: If board size were n x n, it’d be O(n²).
// Space: O(1) — each set holds at most 9 digits.