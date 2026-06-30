#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        int number=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if(number > INT_MAX/10 ||(number == INT_MAX / 10 && digit > 7)){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            number=number*10+digit;
            i++;
        }
        return sign*number;
    }
};

int main() {
    Solution solution;
    string s = "   -42";
    int result = solution.myAtoi(s);
    cout << result << endl; // Output: -42
    return 0;
}