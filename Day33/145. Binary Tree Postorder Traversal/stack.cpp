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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            
            st2.push(curr);

            if(curr->left){
                st1.push(curr->left);

            }
            if(curr->right){
                st1.push(curr->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
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
    vector<int> result = solution.postorderTraversal(root);

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