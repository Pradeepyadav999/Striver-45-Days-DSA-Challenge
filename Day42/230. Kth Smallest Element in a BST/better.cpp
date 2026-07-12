#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {
        if (root == NULL)
            return;

        inorder(root->left, k);

        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->right = new TreeNode(40);

    int k = 2;
    int result = solution.kthSmallest(root, k);

    cout << "Kth Smallest: " << result << endl;
    return 0;
}