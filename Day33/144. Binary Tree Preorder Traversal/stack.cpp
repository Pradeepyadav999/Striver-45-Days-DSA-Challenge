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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->data);

            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
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
    vector<int> result = solution.preorderTraversal(root);

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