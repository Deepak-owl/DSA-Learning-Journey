#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    for (int i = 0; i < 32; i++) {
        // Get the rightmost bit of n
        uint32_t bit = n & 1;
        
        // Shift result left to make room, add the bit
        result = (result << 1) | bit;
        
        // Shift n right to process next bit
        n >>= 1;
    }
    
    return result;
}

int main() {
    uint32_t n = 43261596; // 00000010100101000001111010011100
    uint32_t reversed = reverseBits(n);
    cout << "Original: " << n << endl;
    cout << "Reversed: " << reversed << endl;
    return 0;
}