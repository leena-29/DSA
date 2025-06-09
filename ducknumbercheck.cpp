
#include <iostream>
using namespace std;

bool isDuckNumber(int n) {
    while (n > 0) {
        if (n % 10 == 0)
            return true;
        n /= 10;
    }
    return false;
}

int main() {
    int num = 204;
    if (num % 10 == 0) {
        cout << num << " is not a Duck number." << endl;
    } else if (isDuckNumber(num)) {
        cout << num << " is a Duck number." << endl;
    } else {
        cout << num << " is not a Duck number." << endl;
    }
    return 0;
}
