//vector offers multiple initialization methods. Let’s see them in action :
// Empty:        vector<int> v1 starts with size 0.
// Size only:    vector<int> v2(5) creates 5 elements, default-initialized to 0.
// Size + value: vector<int> v3(3, 10) fills with the specified value.
// Initializer list: vector<int> v4 = {1, 2, 3, 4, 5} directly sets elements.
// Copy:         vector<int> v5(v4) duplicates another vector.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Method 1: Empty vector
    vector<int> v1;
    cout << "v1 (empty): size = " << v1.size() << endl;

    // Method 2: Size specified, default value (0 for int)
    vector<int> v2(5); // 5 elements, all 0
    cout << "v2 (size 5, default 0): ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    // Method 3: Size and custom value
    vector<int> v3(3, 10); // 3 elements, all 10
    cout << "v3 (size 3, all 10): ";
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    // Method 4: Initializer list (C++11 and later)
    vector<int> v4 = {1, 2, 3, 4, 5};
    cout << "v4 (initializer list): ";
    for (int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    // Method 5: Copy from another vector
    vector<int> v5(v4);
    cout << "v5 (copy of v4): ";
    for (int i = 0; i < v5.size(); i++) {
        cout << v5[i] << " ";
    }
    cout << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     // Initialize with initializer list
//     vector<int> arr = {10, 20, 30, 40};

//     // Size and capacity
//     cout << "Size: " << arr.size() << endl; // Current number of elements
//     cout << "Capacity: " << arr.capacity() << endl; // Allocated memory (may be more than size)

//     // Add elements
//     arr.push_back(50); // Add to end
//     cout << "After push_back(50): ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     // Insert at position
//     arr.insert(arr.begin() + 1, 15); // Insert 15 at index 1
//     cout << "After insert(15 at 1): ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     // Remove elements
//     arr.pop_back(); // Remove last element
//     cout << "After pop_back(): ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     arr.erase(arr.begin() + 2); // Remove element at index 2
//     cout << "After erase(index 2): ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     // Access elements
//     cout << "First element: " << arr.front() << endl;
//     cout << "Last element: " << arr.back() << endl;
//     cout << "Element at index 1: " << arr.at(1) << endl;

//     // Resize
//     arr.resize(3); // Shrink to 3 elements
//     cout << "After resize(3): ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }