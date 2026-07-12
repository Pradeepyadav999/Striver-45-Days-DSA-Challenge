#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
;

class Solution {
public:
    int count = 0;

    int inorder(TreeNode* root, int k) {

        if (root == NULL)
            return -1;

        int left = inorder(root->left, k);

        if (left != -1)
            return left;

        count++;

        if (count == k)
            return root->val;

        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
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