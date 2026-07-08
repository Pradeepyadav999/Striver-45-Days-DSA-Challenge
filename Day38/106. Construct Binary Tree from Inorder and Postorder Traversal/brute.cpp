#include <iostream>
#include <vector>
#include <functional>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int pos = inStart;
        while (pos <= inEnd) {
            if (inorder[pos] == root->val)
                break;
            pos++;
        }
        root->left = build(preorder, inorder, inStart, pos - 1);

        root->right = build(preorder, inorder, pos + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return build(preorder, inorder, 0, (int)inorder.size() - 1);
    }
};

int main() {
    // Example usage:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Output the constructed tree (inorder traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}