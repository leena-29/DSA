#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> val, sub, vis;
long long total = 0;

long long dfs(int u) {
    vis[u] = 1;
    long long s = val[u];
    for (int v : g[u]) {
        if (!vis[v]) s += dfs(v);
    }
    sub[u] = s;
    return s;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int n = data.size();
    g.assign(n + 1, {});
    val.assign(n + 1, 0);
    sub.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) val[i] = data[i - 1];
    
    for (auto &e : edges) {
        int a = e[0], b = e[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    total = dfs(1);
    
    long long ans = LLONG_MAX;
    for (int i = 2; i <= n; i++) {
        long long part1 = sub[i];
        long long part2 = total - part1;
        ans = min(ans, llabs(part1 - part2));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) cin >> data[i];
    
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    cout << cutTheTree(data, edges);
    return 0;
}
