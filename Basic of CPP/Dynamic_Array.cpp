// Pointers with new (manual memory management).
// std::vector (a standard library container, much easier).

// Feature	        int arr[size]  (VLA)	        new int[size] (Dynamic)
// Memory Location	Stack	                        Heap
// Size             Flexibility	Fixed at creation	Fixed, but can reallocate
// Standard C++	    No (compiler extension)	        Yes
// Memory Limit  	Small (stack size)	            Large (system memory)
// Cleanup	        Automatic	                    Manual(delete[])

// #include <iostream>
// using namespace std;

// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;

//     // Allocate memory dynamically
//     int* arr = new int[size];

//     // Input elements
//     cout << "Enter " << size << " elements:" << endl;
//     for (int i = 0; i < size; i++) {
//         cin >> arr[i];
//     }

//     // Print the array
//     cout << "Dynamic array elements:" << endl;
//     for (int i = 0; i < size; i++) {
//         cout << "Element at index " << i << ": " << arr[i] << endl;
//     }

//     // Deallocate memory (important to avoid memory leaks!)
//     delete[] arr;

//     return 0;
// }


//Vector
#include <iostream>
#include <vector> // Required for vector
using namespace std;

int main() {
    int size;
    cout << "Enter the initial size of the array: ";
    cin >> size;

    // Declare a vector
    vector<int> arr;

    // Input elements
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        arr.push_back(element); // Adds element to the end
    }

    // Print initial array
    cout << "Initial vector elements:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    // Insert an element dynamically
    int element, pos;
    cout << "Enter an element to insert: ";
    cin >> element;
    cout << "Enter the position (0 to " << arr.size() << "): ";
    cin >> pos;

    if (pos < 0 || pos > arr.size()) {
        cout << "Invalid position!" << endl;
    } else {
        arr.insert(arr.begin() + pos, element); // Inserts at position
    }

    // Print updated array
    cout << "Updated vector elements:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    return 0;
}