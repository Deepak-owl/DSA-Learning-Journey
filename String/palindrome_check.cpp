#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        // Handle left pointer
        if (!isalnum(s[left])) {
            left++;
        }
        // Handle right pointer
        else if (!isalnum(s[right])) {
            right--;
        }
        // Compare if both are alphanumeric
        else {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
    }
    
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << "Is '" << s << "' a palindrome? " << (isPalindrome(s) ? "true" : "false") << endl;
    return 0;
}