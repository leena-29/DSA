
#include <iostream>
using namespace std;

bool isAutomorphic(int n) {
    int sq = n * n;
    while (n > 0) {
        if (n % 10 != sq % 10)
            return false;
        n /= 10;
        sq /= 10;
    }
    return true;
}

int main() {
    int num = 76;
    if (isAutomorphic(num))
        cout << num << " is an Automorphic number." << endl;
    else
        cout << num << " is not an Automorphic number." << endl;
    return 0;
}
