#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int solve(int idx1,int idx2,string text1, string text2){
        // Base Case
        if(idx1<0 || idx2<0){
            return 0;
        }
        // If character match
        if(text1[idx1]==text2[idx2]){
            return 1+solve(idx1-1,idx2-1,text1,text2);
        }
        // Character don`t match
        return max(solve(idx1-1,idx2,text1,text2),solve(idx1,idx2-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};

int main() {
    Solution solution;
    string text1 = "abcde";
    string text2 = "ace";
    int result = solution.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl;
    return 0;
}