#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is 1
        n >>= 1; // Right shift to check the next bit
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of set bits: " << countSetBits(n) << endl;
    return 0;
}

