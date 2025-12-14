#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());  // Step 1: Sort the array
    int n = arr.size();
    return arr[n / 2];             // Step 2: Return the middle element
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << findMedian(arr) << endl;
    return 0;
}
