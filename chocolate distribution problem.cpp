#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of chocolate packets: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sizes of the packets: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of students: ";
    cin >> m;

    if (m > n) {
        cout << "Number of students can't be more than the number of packets!" << endl;
        return 0;
    }

    sort(arr, arr + n);

    int min_diff = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int diff = arr[i + m - 1] - arr[i];
        min_diff = min(min_diff, diff);
    }

    cout << "The minimum difference is: " << min_diff << endl;
    return 0;
}

