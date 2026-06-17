class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(int index,string &s,vector<string>& part,vector<vector<string>>& ans) {
        if(index == s.size()) {
            ans.push_back(part);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            // Check palindrome BEFORE recursion
            if(isPalindrome(s, index, i)) {
                part.push_back(s.substr(index, i - index + 1));
                solve(i+1,s,part,ans);
                part.pop_back(); // Backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        solve(0, s, part, ans);

        return ans;
    }
};