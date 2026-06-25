#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(char ch :s){
            if(ch =='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }else{
                if(st.empty())
                    return false;

                if(ch == ')' && st.top() != '(')
                    return false;

                if(ch == ']' && st.top() != '[')
                    return false;

                if(ch == '}' && st.top() != '{')
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.isValid(str);
}