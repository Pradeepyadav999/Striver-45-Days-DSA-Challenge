#include <iostream>
#include <algorithm>
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
    int longestPalindromeSubseq(string s) {
        string sReve = s;
        reverse(sReve.begin(), sReve.end());        
        return solve(s.size() - 1, sReve.size() - 1, s, sReve);
    }
};


int main() {
    Solution sol;
    string s = "bbbab";
    int result = sol.longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence: " << result << endl;
    return 0;
}
