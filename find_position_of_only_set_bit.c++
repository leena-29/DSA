
#include <iostream>
#include <cmath>
using namespace std;

int findPosition(int n) {
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;
    int pos = 1;
    while (n > 1) {
        n >>= 1;
        pos++;
    }
    return pos;
}

int main() {
    int num = 16;
    cout << "Position of the only set bit: " << findPosition(num) << endl;
    return 0;
}
