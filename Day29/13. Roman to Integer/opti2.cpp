#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public: 
    int romanToInt(string s) {
        int value[128] = {};
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]])
                ans -= value[s[i]];
            else
                ans += value[s[i]];
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