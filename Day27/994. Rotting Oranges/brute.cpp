#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (true) {
            vector<pair<int,int>> rotten;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        for (int k = 0; k < 4; k++) {
                            int nr = i + dr[k];
                            int nc = j + dc[k];
                            if (nr >= 0 && nr < m &&
                                nc >= 0 && nc < n &&
                                grid[nr][nc] == 1) {
                                rotten.push_back({nr, nc});
                            }
                        }
                    }
                }
            }
            if (rotten.empty())
                break;
            for (auto cell : rotten)
                grid[cell.first][cell.second] = 2;
            minutes++;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return minutes;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = sol.orangesRotting(grid);
    cout << result << endl; // Output: 4
    return 0;
}