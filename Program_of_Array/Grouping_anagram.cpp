// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters





// Complexity
// Time: O(n * k log k).
// n strings, each sorted in O(k log k).
// Space: O(n * k) for the hash map and output.


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    
    // Group strings by their sorted version
    for (string s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        anagramMap[sorted].push_back(s); // Add original string to group
    }
    
    // Convert map values to result
    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    cout << "Grouped anagrams:" << endl;
    for (const auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}