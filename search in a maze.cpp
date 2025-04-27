#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num = 6;
    cout << "Fibonacci number at position " << num << " is " << fibonacci(num) << endl;
    return 0;
}

