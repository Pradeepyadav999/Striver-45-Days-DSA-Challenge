#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        // Iterate for n-1 times 
        for(int i=2;i<=n;i++){
            string temp = "";
            int count = 1;  //Initially count is 1
            // Now we iterate on ans
            for(int j=0;j<ans.size();j++){
                if (j+1<ans.size() && ans[j]==ans[j+1]){
                    count++;
                }else{
                    temp+=to_string(count);
                    temp+=ans[j];
                    count = 1;
                }
            }
            ans=temp;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.countAndSay(n);
}