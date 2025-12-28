
#include <bits/stdc++.h>
using namespace std;

struct Plus {
    int x, y, arm;
    int area() const { return 4 * arm + 1; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<Plus> pluses;

    // Generate all possible pluses
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G') {
                int arm = 0;
                while (true) {
                    if (i - arm < 0 || i + arm >= n || j - arm < 0 || j + arm >= m)
                        break;
                    if (grid[i - arm][j] != 'G' || grid[i + arm][j] != 'G' ||
                        grid[i][j - arm] != 'G' || grid[i][j + arm] != 'G')
                        break;
                    pluses.push_back({i, j, arm});
                    arm++;
                }
            }
        }
    }

    auto overlap = [&](const Plus &p1, const Plus &p2) {
        set<pair<int, int>> cells1, cells2;

        cells1.insert({p1.x, p1.y});
        for (int k = 1; k <= p1.arm; k++) {
            cells1.insert({p1.x + k, p1.y});
            cells1.insert({p1.x - k, p1.y});
            cells1.insert({p1.x, p1.y + k});
            cells1.insert({p1.x, p1.y - k});
        }

        cells2.insert({p2.x, p2.y});
        for (int k = 1; k <= p2.arm; k++) {
            cells2.insert({p2.x + k, p2.y});
            cells2.insert({p2.x - k, p2.y});
            cells2.insert({p2.x, p2.y + k});
            cells2.insert({p2.x, p2.y - k});
        }

        for (auto &c : cells1) {
            if (cells2.count(c)) return true;
        }
        return false;
    };

    int maxProduct = 0;
    for (int i = 0; i < (int)pluses.size(); i++) {
        for (int j = i + 1; j < (int)pluses.size(); j++) {
            if (!overlap(pluses[i], pluses[j])) {
                maxProduct = max(maxProduct, pluses[i].area() * pluses[j].area());
            }
        }
    }

    cout << maxProduct << endl;
    return 0;
}
