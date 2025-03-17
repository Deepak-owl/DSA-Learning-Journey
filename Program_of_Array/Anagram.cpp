//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    // If lengths differ, not anagrams
    if (s.length() != t.length()) {
        return false;
    }
//     Sort both strings
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
    
//     // Compare sorted strings
//     return s == t;
// }
    
    // Array for 26 lowercase letters
    int count[26] = {0}; // Initialized to 0
    
    // Count characters in s
    for (char c : s) {
        count[c - 'a']++; // Increment count for this letter
    }
    
    // Decrement for t
    for (char c : t) {
        count[c - 'a']--; // Decrement count for this letter
        if (count[c - 'a'] < 0) { // Early exit if negative
            return false;
        }
    }
    
    // Check if all counts are 0
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, t;
    
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    
    if (isAnagram(s, t)) {
        cout << "True - '" << t << "' is an anagram of '" << s << "'" << endl;
    } else {
        cout << "False - '" << t << "' is not an anagram of '" << s << "'" << endl;
    }
    
    return 0;
}

// Character Counting: Use an array of size 26 (for a-z) to count frequencies of each letter in s and t. If the counts match, they’re anagrams.
// Time: O(n).
// Space: O(1) since the array size is fixed (26).