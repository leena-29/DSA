
#include <iostream>
using namespace std;

int countBitsToFlip(int a, int b) {
    int xor_val = a ^ b;
    int count = 0;
    while (xor_val) {
        count += xor_val & 1;
        xor_val >>= 1;
    }
    return count;
}

int main() {
    int a = 29, b = 15;
    cout << "Bits to flip: " << countBitsToFlip(a, b) << endl;
    return 0;
}
