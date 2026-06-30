// Own Logic 
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count=0;
        string repeated = "";    
        while(repeated.size() < b.size()){
            repeated +=a;
            count++;
            if (repeated.find(b) != string::npos)
                return count;
        }    
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos)
            return count;

        return -1;
    }
};

int main() {
    Solution solution;
    string a = "abcd";
    string b = "cdabcdab";
    int result = solution.repeatedStringMatch(a, b);
    cout << "Result: " << result << endl; // Output: 3
    return 0;
}