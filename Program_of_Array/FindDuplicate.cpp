// Given an integer array nums, return true if 
// any value appears at least twice in the array, and return false if every element is distinct.

// Constraints:

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9


#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if (nums.size() <= 1) {
        return false; // No duplicates possible with 0 or 1 element
    }
    
    // Sort the array in-place
    sort(nums.begin(), nums.end());
    
    // Check adjacent elements
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true; // Duplicate found
        }
    }
    return false; // No duplicates
}

int main() {
    vector<int> nums;
    int n, element;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        nums.push_back(element);
    }
    
    // Check for duplicates
    if (containsDuplicate(nums)) {
        cout << "True - Array contains duplicates" << endl;
    } else {
        cout << "False - All elements are distinct" << endl;
    }
    
    // Print sorted array (for verification)
    cout << "Sorted array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}