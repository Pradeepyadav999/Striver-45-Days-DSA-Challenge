#include<iostream>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return 1+max(leftDepth,rightDepth);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    return 0;
}