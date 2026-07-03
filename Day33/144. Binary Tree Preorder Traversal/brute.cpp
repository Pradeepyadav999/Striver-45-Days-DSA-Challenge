#include <iostream>
#include <vector>
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
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
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