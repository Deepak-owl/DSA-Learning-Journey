// Problem: Given a string with words followed by digits, rearrange 
// the words according to the digits in ascending order and remove the digits.
// Example: Input: "is2 This1 a3 test4" → Output: "This is a test".


#include <iostream>
#include <vector>
#include <string>
using namespace std;

string rearrangeWords(string str) {
    // Step 1: Count spaces to determine number of words
    int space = 0;
    for(char c : str) {
        if(c == ' ') space++;
    }
    int wordCount = space + 1;

    // Step 2: Vector sized to wordCount (0-based indexing)
    vector<string> res(wordCount); // No +1, size matches word count

    // Step 3: Parse the string
    string s = ""; // Current word being built
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ' ' && !isdigit(str[i])) {
            s += str[i]; // Build word
        } else if(isdigit(str[i])) {
            int digit = str[i] - '0'; // Convert char digit to int
            res[digit - 1] = s; // Place word at 0-based index (digit - 1)
            s = ""; // Reset word
        } else if(str[i] == ' ') {
            s = ""; // Reset word for next one
        }
    }

    // Step 4: Build result string
    string result = "";
    for(int i = 0; i < wordCount; i++) { // Start from 0 to wordCount-1
        if(!res[i].empty()) {
            if(!result.empty()) result += " "; // Add space between words
            result += res[i];
        }
    }
    return result;
}

int main() {
    string str = "is2 This1 a3 test4";
    string result = rearrangeWords(str);
    cout << "Rearranged string: " << result << endl;
    return 0;
}