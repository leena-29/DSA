#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;

    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial of a negative number is not defined.\n";
    else
        cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    return 0;
}

