#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);

        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (!root) return false;

        BSTIterator left(root, false);   // smallest iterator
        BSTIterator right(root, true);   // largest iterator

        int i = left.next();
        int j = right.next();

        while (i < j) {

            if (i + j == k)
                return true;

            if (i + j < k)
                i = left.next();
            else
                j = right.next();
        }

        return false;
    }
};