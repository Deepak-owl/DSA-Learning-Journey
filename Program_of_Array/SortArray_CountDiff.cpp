// Sort Array and Count Differences
// Problem: Given an unsorted array, determine how many positions differ from its sorted version.
// Example: Input: [1, 2, 5, 4, 3, 6] → Output: 2 (positions 2 and 4 differ after sorting to [1, 2, 3, 4, 5, 6]).


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDifferences(vector<int>& arr) {
    // Step 1: Create a copy of the array
    vector<int> sortedArr = arr;

    // Step 2: Sort the copy
    sort(sortedArr.begin(), sortedArr.end());

    // Step 3: Compare and count differences
    int position = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != sortedArr[i]) {
            position++;
        }
    }

    return position;
}

int main() {
    vector<int> arr = {1, 2, 5, 4, 3, 6};
    int result = countDifferences(arr);
    cout << "Number of differing positions: " << result << endl;
    return 0;
}