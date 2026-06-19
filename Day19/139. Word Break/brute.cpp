class Solution {
public:
    bool solve(int index, string& s, vector<string>& wordDict){
        // Base case
        if(index==s.length()){
            return true;
        }
        for(string &word : wordDict){
            int len=word.size();
            if(index+len<=s.size() && s.substr(index,len)==word){
                if(solve(index+len,s,wordDict)){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0,s,wordDict);
    }
};