#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size()) {
                if(s[i] == 'I' && s[i+1] == 'V') {
                    ans += 4;
                    i++;
                }else if(s[i] == 'I' && s[i+1] == 'X') {
                    ans += 9;
                    i++;
                }else if(s[i] == 'X' && s[i+1] == 'L') {
                    ans += 40;
                    i++;
                }else if(s[i] == 'X' && s[i+1] == 'C') {
                    ans += 90;
                    i++;
                }else if(s[i] == 'C' && s[i+1] == 'D') {
                    ans += 400;
                    i++;
                }else if(s[i] == 'C' && s[i+1] == 'M') {
                    ans += 900;
                    i++;
                }else {
                    ans += mp[s[i]];
                }
            }else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    cout << result << endl; // Output: 1994
    return 0;
}