#include <bits/stdc++.h>
using namespace std;

long strangeCounter(long t) {
    long cycle = 3; // initial cycle length
    while (t > cycle) {
        t -= cycle;
        cycle *= 2; // each cycle doubles
    }
    return cycle - t + 1;
}

int main() {
    long t;
    cin >> t;
    cout << strangeCounter(t) << endl;
    return 0;
}
