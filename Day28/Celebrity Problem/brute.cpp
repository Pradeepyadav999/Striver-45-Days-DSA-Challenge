#include <iostream>  
#include <vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int>iKnow(n,0);
        vector<int>knowMe(n,0);
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                if(i != j && mat[i][j] == 1) {
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        for(int i=0; i < n; i++) {
            if(knowMe[i] == n-1 && iKnow[i] == 0) {
                return i;  
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int result = solution.celebrity(mat);
    cout << "Celebrity index: " << result << endl;
    return 0;
}