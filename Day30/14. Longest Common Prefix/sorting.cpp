#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first = strs.front();
        string last = strs.back();
        string ans="";
        for(int i=0;i<min(first.size(), last.size()); i++){
            if (first[i] != last[i])
                break;

            ans += first[i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl; // Output: "fl"
    return 0;
}