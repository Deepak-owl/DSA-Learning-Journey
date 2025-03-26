
// Problem: Find all leaders in an array. A leader is an element greater than all elements to its right.
// Example: Input: [16, 17, 4, 3, 5, 2] → Output: [17, 5, 2].


#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> findLeadersOptimized(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxRight = arr[n - 1]; // Last element is always a leader
    leaders.push_back(maxRight);
    
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > maxRight) { // If current element is greater than max seen so far
            maxRight = arr[i];
            leaders.push_back(maxRight);
        }
    }
    // Reverse to maintain original order (optional)
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeadersOptimized(arr);
    cout << "Leaders: ";
    for(int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;
    return 0;
}