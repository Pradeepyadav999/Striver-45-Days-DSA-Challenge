class Solution {
public:
    vector<string> ans;
    
    bool isSafe(int row, int col, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        // Out of Bound
        if (row < 0 || col < 0 || row >= n || col >= n)
            return false;
        // Blocked
        if (grid[row][col] == 0)
            return false;
        // Visited
        if (visited[row][col])
            return false;

        return true;
    }

    void solve(int row, int col, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited, string path){
        // Base case
        if(row == n - 1 && col == n - 1){
            ans.push_back(path);
            return;
        }
        
        // mark visited
        visited[row][col] = true;
        
        // Down
        if (isSafe(row + 1, col, n, grid, visited))
            solve(row + 1, col, n, grid, visited, path + 'D');
            
        // Left
        if (isSafe(row, col - 1, n, grid, visited))
            solve(row, col - 1, n, grid, visited, path + 'L');

        // Right
        if (isSafe(row, col + 1, n, grid, visited))
            solve(row, col + 1, n, grid, visited, path + 'R');

        // Up
        if (isSafe(row - 1, col, n, grid, visited))
            solve(row - 1, col, n, grid, visited, path + 'U');

        // Backtrack
        visited[row][col] = false; 
    }
    
    vector<string> findPath(vector<vector<int>> &grid) {
        // FIX 1: Clear the global/class vector for sequential test cases
        ans.clear();
        
        int n = grid.size();
        
        // Edge case handling
        if(n == 0 || grid[0][0] == 0 || grid[n - 1][n - 1] == 0) {
            return {}; 
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        solve(0, 0, n, grid, visited, "");
        
        return ans;
    }
};