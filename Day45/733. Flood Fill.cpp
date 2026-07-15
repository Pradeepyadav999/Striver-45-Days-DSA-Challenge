#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor){
        image[r][c] = newColor;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 &&
               nr<image.size() &&
               nc>=0 &&
               nc<image[0].size() &&
               image[nr][nc]==oldColor)
            {
                dfs(image,nr,nc,oldColor,newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return image;
        dfs(image,sr,sc,oldColor,color);
        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}