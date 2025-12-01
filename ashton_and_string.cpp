#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to make all suffixes of the string
vector<string> makeSuffixes(string s) {
    vector<string> suffixes;
    for (int i = 0; i < s.size(); i++) {
        suffixes.push_back(s.substr(i)); // take substring from i to end
    }
    return suffixes;
}

// Function to find Ashton character
char findAshtonChar(string s, long long k) {
    // Step 1: make all suffixes
    vector<string> suffixes = makeSuffixes(s);

    // Step 2: sort all suffixes alphabetically
    sort(suffixes.begin(), suffixes.end());

    // Step 3: now make all substrings from sorted suffixes (unique)
    vector<string> substrings;
    for (string suf : suffixes) {
        for (int len = 1; len <= suf.size(); len++) {
            substrings.push_back(suf.substr(0, len));
        }
    }

    // Step 4: remove duplicates
    sort(substrings.begin(), substrings.end());
    substrings.erase(unique(substrings.begin(), substrings.end()), substrings.end());

    // Step 5: join all substrings together into one long string
    string joined = "";
    for (string sub : substrings) {
        joined += sub;
    }

    // Step 6: return the k-th character (1-based)
    if (k > 0 && k <= joined.size())
        return joined[k - 1];
    else
        return '?'; // if k is out of range
}

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        cout << findAshtonChar(s, k) << endl;
    }

    return 0;
}
