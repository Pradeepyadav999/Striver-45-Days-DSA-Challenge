#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int top=0,down=n-1;
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }else if(mat[down][top]==1){
                down--;
            }else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;//Diagonal 
            if(mat[top][i] == 1 || mat[i][top] == 0) {
                return -1;
            }
        }
        return top;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    int result = sol.celebrity(mat);
    cout << result << endl;
    return 0;
}