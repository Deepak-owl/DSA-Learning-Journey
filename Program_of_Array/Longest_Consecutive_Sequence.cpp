// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

// my approach: we can store the element in ordered set and check difference between element is 1 or not and according add length variable +1


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    // Step 1: Store elements in an unordered_set
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLength = 0;
    
    // Step 2: Check each element as a potential sequence start
    for (int num : nums) {
        // Only process if num is the start of a sequence
        if (s.find(num - 1) == s.end()) { // No predecessor
            int currentNum = num;
            int currentLength = 1;
            
            // Keep checking next numbers
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentLength++;
            }
            
            maxLength = max(maxLength, currentLength);
        }
    }
    
    return maxLength;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl;
    return 0;
}