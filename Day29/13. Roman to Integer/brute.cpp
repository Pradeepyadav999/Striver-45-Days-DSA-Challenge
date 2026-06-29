#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int ans = 0;
        int prev = 0;

        for(int i = s.size() - 1; i >= 0; i--) {

            if(mp[s[i]] < prev)
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];

            prev = mp[s[i]];
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