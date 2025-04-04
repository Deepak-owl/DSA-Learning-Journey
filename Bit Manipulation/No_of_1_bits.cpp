#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {          // Continue until n becomes 0
        count += n & 1;  // Add 1 if the least significant bit is 1
        n >>= 1;         // Shift right to check the next bit
    }
    return count;
}

int main() {
    uint32_t n = 11; // 00001011
    cout << "Number of 1 bits: " << hammingWeight(n) << endl;
    return 0;
}