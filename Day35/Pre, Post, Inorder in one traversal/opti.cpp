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
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        if (!root)
            return {pre, in, post};
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            TreeNode* node = it.first;
            int state = it.second;
            // State 1 -> Preorder
            if (state == 1) {
                pre.push_back(node->data);
                st.push({node, 2});
                if (node->left)
                    st.push({node->left, 1});
            }
            // State 2 -> Inorder
            else if (state == 2) {
                in.push_back(node->data);
                st.push({node, 3});
                if (node->right)
                    st.push({node->right, 1});
            }
            // State 3 -> Postorder
            else {
                post.push_back(node->data);
            }
        }
        return {in ,pre,    post};
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

    cout << "Inorder: ";
    for (int val : result[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder: ";
    for (int val : result[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int val : result[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}