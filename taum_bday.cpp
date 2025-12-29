#include <bits/stdc++.h>
using namespace std;

// Use long long to avoid overflow
long long taumBday(long long b, long long w, long long bc, long long wc, long long z) {
    // Find effective costs (direct vs convert)
    long long effectiveBlack = min(bc, wc + z);
    long long effectiveWhite = min(wc, bc + z);

    return b * effectiveBlack + w * effectiveWhite;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long b, w, bc, wc, z;
        cin >> b >> w;
        cin >> bc >> wc >> z;
        cout << taumBday(b, w, bc, wc, z) << "\n";
    }
    return 0;
}
