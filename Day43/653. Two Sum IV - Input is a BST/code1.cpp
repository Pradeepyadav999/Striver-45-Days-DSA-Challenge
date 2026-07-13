#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_set<int> st;

    bool dfs(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};