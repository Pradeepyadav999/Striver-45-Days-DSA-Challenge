#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& ans) {
        if (root == NULL)
            return;
        path.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }
        else {
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
        path.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, path, ans);

        return ans;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> paths = sol.allRootToLeaf(root);

    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}