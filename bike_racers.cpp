#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> bikers, bikes;
vector<vector<long long>> distMatrix;

bool bpm(int u, vector<int> &matchR, vector<int> &seen, long long maxDistSq) {
    for (int v = 0; v < m; v++) {
        if (!seen[v] && distMatrix[u][v] <= maxDistSq) {
            seen[v] = 1;
            if (matchR[v] < 0 || bpm(matchR[v], matchR, seen, maxDistSq)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool canAssign(long long maxDistSq) {
    vector<int> matchR(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++) {
        vector<int> seen(m, 0);
        if (bpm(u, matchR, seen, maxDistSq))
            result++;
        if (result >= k) return true;
    }
    return result >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    bikers.resize(n);
    bikes.resize(m);
    for (int i = 0; i < n; i++)
        cin >> bikers[i].first >> bikers[i].second;
    for (int j = 0; j < m; j++)
        cin >> bikes[j].first >> bikes[j].second;

    distMatrix.assign(n, vector<long long>(m));
    long long maxDist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long dx = bikers[i].first - bikes[j].first;
            long long dy = bikers[i].second - bikes[j].second;
            distMatrix[i][j] = dx * dx + dy * dy;
            maxDist = max(maxDist, distMatrix[i][j]);
        }
    }

    long long low = 0, high = maxDist, ans = maxDist;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canAssign(mid)) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}
