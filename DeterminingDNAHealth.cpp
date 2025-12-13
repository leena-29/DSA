#include <bits/stdc++.h>
using namespace std;

// Function to calculate total health for a given DNA strand
long long calculateHealth(int start, int end, const string &dna,
                          const vector<string> &genes,
                          const vector<int> &health) {
    long long totalHealth = 0;
    for (int i = start; i <= end; i++) {
        size_t pos = dna.find(genes[i]);
        while (pos != string::npos) {
            totalHealth += health[i];
            pos = dna.find(genes[i], pos + 1);
        }
    }
    return totalHealth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> genes(n);
    for (int i = 0; i < n; i++) cin >> genes[i];

    vector<int> health(n);
    for (int i = 0; i < n; i++) cin >> health[i];

    int s;
    cin >> s;

    long long minHealth = LLONG_MAX, maxHealth = LLONG_MIN;

    for (int i = 0; i < s; i++) {
        int start, end;
        string dna;
        cin >> start >> end >> dna;

        long long totalHealth = calculateHealth(start, end, dna, genes, health);

        minHealth = min(minHealth, totalHealth);
        maxHealth = max(maxHealth, totalHealth);
    }

    cout << minHealth << " " << maxHealth << endl;
    return 0;
}
