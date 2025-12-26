#include <bits/stdc++.h>
using namespace std;

vector<string> detonate(vector<string> grid, int r, int c) {
    vector<string> result(r, string(c, 'O'));
    vector<vector<int>> directions = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                for (auto &d : directions) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                        result[ni][nj] = '.';
                    }
                }
            }
        }
    }
    return result;
}

vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size(), c = grid[0].size();

    if (n == 1) return grid;
    if (n % 2 == 0) return vector<string>(r, string(c, 'O'));

    vector<string> firstDetonation = detonate(grid, r, c);
    vector<string> secondDetonation = detonate(firstDetonation, r, c);

    if ((n - 3) % 4 == 0) return firstDetonation;
    else return secondDetonation;
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    vector<string> result = bomberMan(n, grid);
    for (string &row : result) {
        cout << row << "\n";
    }
    return 0;
}
