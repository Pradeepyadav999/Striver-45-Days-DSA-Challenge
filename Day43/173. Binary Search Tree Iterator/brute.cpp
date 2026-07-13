#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    vector<int> inorder;
    int index = 0;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < inorder.size();
    }
};