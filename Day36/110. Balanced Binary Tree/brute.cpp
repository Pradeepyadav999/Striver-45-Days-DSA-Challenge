#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

// Simple TreeNode definition for binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(abs(leftHeight-rightHeight)>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }   
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    bool balanced = sol.isBalanced(root);

    if (balanced) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}