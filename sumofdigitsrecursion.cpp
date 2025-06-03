
#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int number = 12345;
    cout << "Sum of digits of " << number << " is " << sumOfDigits(number) << endl;
    return 0;
}
