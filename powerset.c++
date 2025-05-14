
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printPowerSet(string str) {
    int n = str.length();
    int powerSetSize = 1 << n;

    for (int i = 0; i < powerSetSize; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                cout << str[j];
        }
        cout << endl;
    }
}

int main() {
    string s = "abc";
    printPowerSet(s);
    return 0;
}
