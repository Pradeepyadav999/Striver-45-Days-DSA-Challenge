#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        // Empty tree
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            // Number of nodes in the current level
            int size = q.size();

            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Last node of this level -> Right side view
                if (i == size - 1)
                    ans.push_back(node->val);

                // Add children for the next level
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> ans = s.rightSideView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}