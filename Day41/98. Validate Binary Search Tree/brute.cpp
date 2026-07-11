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
    int findMax(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    int findMin(TreeNode* root){
        while (root->left){
            root = root->left;
        }
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

        if (root->left && findMax(root->left) >= root->val)
            return false;

        if (root->right && findMin(root->right) <= root->val)
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
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