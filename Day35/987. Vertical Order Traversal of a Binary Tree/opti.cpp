#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<tuple<int, int, int>> nodes;
    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        nodes.push_back({col, row, root->val});
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int prevCol = INT_MIN;
        for (auto &[col, row, val] : nodes) {
            if (col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal: " << endl;
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
