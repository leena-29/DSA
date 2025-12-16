#include <bits/stdc++.h>
using namespace std;

int beautifulBinaryString(string b) {
    int count = 0;
    for (int i = 0; i < b.size() - 2; i++) {
        if (b.substr(i, 3) == "010") {
            count++;
            i += 2;  // skip next two to avoid overlap
        }
    }
    return count;
}

int main() {
    int n;
    string b;
    cin >> n >> b;
    cout << beautifulBinaryString(b);
    return 0;
}
