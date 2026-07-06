#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& pre) {
        if (!root) return;
        pre.push_back(root->data);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    void inorder(TreeNode* root, vector<int>& in) {
        if (!root) return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    void postorder(TreeNode* root, vector<int>& post) {
        if (!root) return;
        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->data);
    }

	vector<vector<int>> treeTraversal(TreeNode* root){
        vector<int> pre, in, post;
        preorder(root, pre);
        inorder(root, in);
        postorder(root, post);
        return {in, pre, post};
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.treeTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder Traversal: ";
    for (int val : result[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int val : result[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}