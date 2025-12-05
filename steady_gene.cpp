#include <bits/stdc++.h>
using namespace std;

int steadyGene(string s) {
    int n = s.size();
    unordered_map<char, int> count;
    
    // Count occurrences of A, C, G, T
    for (char c : s) count[c]++;
    
    int required = n / 4;
    int left = 0, min_len = n;

    for (int right = 0; right < n; right++) {
        count[s[right]]--;
        
        // While all counts are <= required, move left pointer
        while (left < n && count['A'] <= required && count['C'] <= required &&
               count['G'] <= required && count['T'] <= required) {
            min_len = min(min_len, right - left + 1);
            count[s[left]]++;
            left++;
        }
    }
    return min_len;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << steadyGene(s);
    return 0;
}
