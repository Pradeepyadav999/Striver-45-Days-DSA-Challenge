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
    void dfs(TreeNode* root,string path,vector<string>& ans){
        if(root==NULL){
            return;
        }
        if(path.empty()){
            path=to_string(root->val);
        }else{
            path+="->" + to_string(root->val);
        }
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        dfs(root,"",ans);
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