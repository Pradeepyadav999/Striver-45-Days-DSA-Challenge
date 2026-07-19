#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse 4 neighbours
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {

                    // Skip diagonals and the current cell
                    if (abs(delrow) + abs(delcol) != 1)
                        continue;

                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' &&
                        !visited[nrow][ncol]) {

                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid[row][col] == '1' && !visited[row][col]) {
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int numberOfIslands = solution.numIslands(grid);
    cout << "Number of Islands: " << numberOfIslands << endl;

    return 0;
}