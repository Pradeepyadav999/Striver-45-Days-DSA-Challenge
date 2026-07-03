#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;  //Initially current is root node
        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;    //Move left 
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);  //Add the value of current node to ans
            curr = curr->right;
        }
        return ans;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}