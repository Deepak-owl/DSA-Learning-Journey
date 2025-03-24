#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Encode: List of strings -> Single string
    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs) {
            result += to_string(s.length()) + "#" + s;
        }
        return result;
    }
    
    // Decode: Single string -> List of strings
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.length()) {
            // Find the delimiter '#'
            int j = i;
            while (j < s.length() && s[j] != '#') {
                j++;
            }
            
            // Extract length (from i to j-1)
            int length = stoi(s.substr(i, j - i));
            
            // Extract string (after '#' for 'length' characters)
            string str = s.substr(j + 1, length);
            result.push_back(str);
            
            // Move past this string
            i = j + 1 + length;
        }
        
        return result;
    }
};

int main() {
    Codec codec;
    vector<string> strs = {"Hello", "World"};
    
    // Test encoding
    string encoded = codec.encode(strs);
    cout << "Encoded: " << encoded << endl;
    
    // Test decoding
    vector<string> decoded = codec.decode(encoded);
    cout << "Decoded: ";
    for (const string& s : decoded) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}

// Problem Description (Assumed)
// Task: Design an algorithm to:
// Encode a list of strings (e.g., ["Hello", "World"]) into a single string.
// Decode that string back into the original list.
// Requirements:
// Must work with any characters (e.g., lowercase, uppercase, special chars).
// Should be stateless (no global variables).
// No built-in serialization (e.g., eval).
// Example:
// Input: ["Hello", "World"]
// Encoded: Something like "5#Hello5#World"
// Decoded: ["Hello", "World"]