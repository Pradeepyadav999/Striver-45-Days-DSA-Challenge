#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     int solve(int i, int j, vector<vector<int>>& grid) {
        if(i == 0 && j == 0)
            return grid[0][0];

        if(i < 0 || j < 0)
            return 1e9;
        int up = grid[i][j] + solve(i - 1, j, grid);
        int left = grid[i][j] + solve(i, j - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        return solve(m - 1, n - 1, grid);
    }
};

int main() {
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };

    Solution obj;
    cout << "Minimum sum path: "
         << obj.minPathSum(grid) << endl;

    return 0;
}