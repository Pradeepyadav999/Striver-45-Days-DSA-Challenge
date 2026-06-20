class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        vector<int>elements;
        for (auto& row : matrix) {
            for (int val : row) {
                elements.push_back(val);
            }
        }
        sort(elements.begin(), elements.end());
        int n = elements.size();
        return elements[n / 2];
    }
};