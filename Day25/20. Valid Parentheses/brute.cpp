#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        while(!s.empty()){
            bool found = false;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]=='[' && s[i+1]==']'||
                   s[i]=='{' && s[i+1]=='}'||
                   s[i]=='(' && s[i+1]==')'){
                        s.erase();
                        found=true;
                        break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.isValid(str);
}