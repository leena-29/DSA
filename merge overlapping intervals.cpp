#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    // If there are no intervals, return an empty list
    if (intervals.empty()) {
        return {};
    }
    
    // Sort intervals based on the starting times
    sort(intervals.begin(), intervals.end());
    
    // Vector to store merged intervals
    vector<pair<int, int>> merged;
    
    // Start with the first interval
    merged.push_back(intervals[0]);
    
    // Traverse through the intervals and merge them if necessary
    for (int i = 1; i < intervals.size(); ++i) {
        // If the current interval overlaps with the previous one, merge them
        if (merged.back().second >= intervals[i].first) {
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            // Otherwise, no overlap, just add the current interval
            merged.push_back(intervals[i]);
        }
    }
    
    return merged;
}

int main() {
    vector<pair<int, int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    
    cout << "Original Intervals: ";
    for (auto& interval : intervals) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;
    
    vector<pair<int, int>> mergedIntervals = mergeIntervals(intervals);
    
    cout << "Merged Intervals: ";
    for (auto& interval : mergedIntervals) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;
    
    return 0;
}

