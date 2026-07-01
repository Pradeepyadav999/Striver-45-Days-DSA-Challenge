#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void generate(int index,string &s,string curr,vector<string>&subsequence){
        if(index==s.size()){
            subsequence.push_back(curr);
            return;
        }
        // Include current character
        generate(index+1,s,curr+s[index],subsequence);
        // Exclude current character
        generate(index+1,s,curr,subsequence);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<string> subseq1, subseq2;

        generate(0,text1,"",subseq1);
        generate(0,text2,"",subseq2);

        int ans=0;

        for (string &s1 : subseq1) {
            for (string &s2 : subseq2) {
                if (s1 == s2) {
                    ans = max(ans, (int)s1.size());
                }
            }
        }
        return ans;
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