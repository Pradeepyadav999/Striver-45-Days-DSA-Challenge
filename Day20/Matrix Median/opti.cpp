class Solution {
public:
    int findMedian(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        // Find minimum and maximum element
        for(int i = 0; i < row; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][col - 1]);
        }

        // 1-based median position
        int required = (row * col + 1) / 2;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int count = 0;  // count of elements <= mid

            for(int i = 0; i < row; i++) {
                count += upper_bound(matrix[i].begin(),
                                     matrix[i].end(),
                                     mid) - matrix[i].begin();
            }

            if(count < required)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};