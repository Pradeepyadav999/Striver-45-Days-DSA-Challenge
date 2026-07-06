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
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            pre.push_back(node->data);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
    }
    void inorder(TreeNode* root, vector<int>& in) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            in.push_back(curr->data);
            curr = curr->right;
        }
    }

    void postorder(TreeNode* root, vector<int>& post) {
        if (!root) return;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }
        while (!st2.empty()) {
            post.push_back(st2.top()->data);
            st2.pop();
        }
    }

    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        preorder(root, pre);
        inorder(root, in);
        postorder(root, post);
        return {in,pre, post};
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