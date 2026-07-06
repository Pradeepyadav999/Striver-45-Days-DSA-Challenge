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
    int widthOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            long long minIndex = q.front().second;

            long long first, last;

            for (int i = 0; i < size; i++) {

                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                long long curr = it.second - minIndex;

                if (i == 0)
                    first = curr;

                if (i == size - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, 2 * curr + 1});

                if (node->right)
                    q.push({node->right, 2 * curr + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    int width = solution.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}