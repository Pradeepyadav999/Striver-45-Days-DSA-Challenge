#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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
    void dfs(TreeNode* root, vector<string>& path, vector<string>& ans) {

        if (root == NULL)
            return;

        path.push_back(to_string(root->val));

        if (root->left == NULL && root->right == NULL) {

            string s = "";

            for (int i = 0; i < path.size(); i++) {
                s += path[i];
                if (i != path.size() - 1)
                    s += "->";
            }

            ans.push_back(s);
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> path;
        vector<string> ans;

        dfs(root, path, ans);

        return ans;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    for (const auto& path : paths) {
        cout << path << endl;
    }

    return 0;
}