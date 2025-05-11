
#include <iostream>
using namespace std;

int copySetBitsInRange(int x, int y, int l, int r) {
    for (int i = l; i <= r; i++) {
        int mask = 1 << (i - 1);
        if (y & mask)
            x |= mask;
    }
    return x;
}

int main() {
    int x = 10, y = 13, l = 2, r = 3;
    cout << "Result after copying set bits in range: " << copySetBitsInRange(x, y, l, r) << endl;
    return 0;
}
