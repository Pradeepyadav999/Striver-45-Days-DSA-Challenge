#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->left == NULL) {
                ans.push_back(cur->data);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    ans.push_back(cur->data);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> inorderTraversal = sol.getInorder(root);

    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}