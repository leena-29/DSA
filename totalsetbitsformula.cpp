
#include <iostream>
using namespace std;

int countSetBits(int n) {
    n++;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        int cycle = 1 << (i + 1);
        count += (n / cycle) * (cycle >> 1);
        int remainder = n % cycle;
        if (remainder > (cycle >> 1))
            count += remainder - (cycle >> 1);
    }
    return count;
}

int main() {
    int n = 17;
    cout << "Total set bits from 1 to " << n << " is " << countSetBits(n) << endl;
    return 0;
}
