#include <bits/stdc++.h>
using namespace std;

long long circDist(long long a, long long b, long long C) {
    long long d = llabs(a - b);
    return min(d, C - d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long C;
    cin >> n >> C;

    vector<long long> a(n), b(n);
    vector<long long> pts;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        pts.push_back(a[i]);
        pts.push_back(b[i]);
    }

    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    // Duplicate positions by adding +C to allow sliding window
    vector<long long> all;
    all.reserve(pts.size() * 2);

    for (long long x : pts) {
        all.push_back(x);
        all.push_back(x + C);
    }

    sort(all.begin(), all.end());

    long long low = 0, high = C / 2, ans = 0;

    // Binary search on answer
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long minAllowed = C - mid;

        bool ok = false;
        for (long long x : pts) {
            long long L = x + mid;
            long long R = x + minAllowed;

            auto it = lower_bound(all.begin(), all.end(), L);
            if (it != all.end() && *it <= R) {
                ok = true;
                break;
            }
        }

        if (ok) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
