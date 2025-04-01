//n[i]+n[j]+n[k]=0


#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Need at least 3 numbers
        if (n < 3) return result;
        
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Fix first number and use two pointers
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for first number
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Use two pointers
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];  // We need two numbers that sum to -nums[i]
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

// Test the solution
int main() {
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    
    // Print results
    for (const auto& triplet : result) {
        std::cout << "[" << triplet[0] << "," << triplet[1] << "," 
                  << triplet[2] << "]" << std::endl;
    }
    
    return 0;
}