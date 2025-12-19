#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> count(100, 0); // Frequency array for numbers 0–99
    
    // Count occurrences
    for (int num : arr) {
        count[num]++;
    }
    
    // Create sorted result
    vector<int> sorted;
    for (int i = 0; i < 100; i++) {
        while (count[i] > 0) {
            sorted.push_back(i);
            count[i]--;
        }
    }
    
    return sorted;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> result = countingSort(arr);
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    
    return 0;
}
