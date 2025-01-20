#include <iostream>
#include <vector>
using namespace std;

int searchInsertPosition(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;  // If target is not found, left will be the position to insert.
}

int main() {
    int n, target;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the target value: ";
    cin >> target;
    
    int result = searchInsertPosition(nums, target);
    cout << "The position to insert the target is: " << result << endl;
    
    return 0;
}

