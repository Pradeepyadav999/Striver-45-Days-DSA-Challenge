#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    long long ans = 0;
    vector<long long> firstIndex;

    void dfs(TreeNode* root, int depth, long long index) {

        if (!root)
            return;

        if (depth == firstIndex.size())
            firstIndex.push_back(index);

        ans = max(ans, index - firstIndex[depth] + 1);

        dfs(root->left, depth + 1, 2 * index + 1);
        dfs(root->right, depth + 1, 2 * index + 2);
    }

    int widthOfBinaryTree(TreeNode* root) {

        dfs(root, 0, 0);

        return ans;
    }
};