#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    cout << n % 2;
}

int main() {
    int num = 10;
    cout << "Binary of " << num << " is: ";
    decimalToBinary(num);
    cout << endl;
    return 0;
}

