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
    TreeNode* prev = NULL;

    bool inorder(TreeNode* root) {
        if (root == NULL)
            return true;

        if (!inorder(root->left))
            return false;

        if (prev != NULL && root->val <= prev->val)
            return false;

        prev = root;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
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
