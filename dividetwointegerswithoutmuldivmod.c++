
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long)divisor);
    long long result = 0;

    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        result += multiple;
    }

    return sign * result;
}

int main() {
    int a = 43, b = -8;
    cout << "Quotient: " << divide(a, b) << endl;
    return 0;
}
