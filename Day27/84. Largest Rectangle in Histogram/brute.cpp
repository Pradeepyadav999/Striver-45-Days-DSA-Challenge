#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int minHeight = INT_MAX;
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                int width = j - i + 1;
                int area = minHeight * width;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = solution.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl; // Output: 10
    return 0;
}