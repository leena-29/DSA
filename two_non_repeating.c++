
#include <iostream>
#include <vector>
using namespace std;

void findTwoNonRepeating(const vector<int>& arr) {
    int xor_all = 0;
    for (int num : arr) xor_all ^= num;

    int set_bit = xor_all & -xor_all;
    int x = 0, y = 0;

    for (int num : arr) {
        if (num & set_bit)
            x ^= num;
        else
            y ^= num;
    }

    cout << "The two non-repeating elements are: " << x << " and " << y << endl;
}

int main() {
    vector<int> arr = {4, 2, 4, 5, 2, 3, 3, 1};
    findTwoNonRepeating(arr);
    return 0;
}
