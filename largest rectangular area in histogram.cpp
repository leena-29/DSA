#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the largest rectangular area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int index = 0;
    
    // Traverse through the histogram
    while (index < heights.size()) {
        // If the current bar is higher than the bar at the stack top, push it to the stack
        if (s.empty() || heights[index] >= heights[s.top()]) {
            s.push(index++);
        } else {
            // Calculate the area with the top of the stack as the smallest bar
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
            maxArea = max(maxArea, area);
        }
    }
    
    // Calculate the area for remaining bars in the stack
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    
    return 0;
}

