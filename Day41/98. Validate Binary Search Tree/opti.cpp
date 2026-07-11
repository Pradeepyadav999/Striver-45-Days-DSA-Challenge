#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool solve(TreeNode* root, long long low, long long high) {
        if(root==NULL) return true;
        if(root->val<=low || root->val>=high){
            return false;
        }
        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool isValid = solution.isValidBST(root);
    if (isValid) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is not a valid BST." << std::endl;
    }

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}