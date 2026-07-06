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
        int l=height(root->left);
        if(l==-1)return -1;
        int r=height(root->right);
        if(r==-1)return -1;
        if(abs(l-r)>1)
            return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;;
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