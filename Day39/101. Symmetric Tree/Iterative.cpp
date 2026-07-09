#include <iostream>
#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (root == NULL)
            return true;

        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {

            TreeNode* left = q.front();
            q.pop();

            TreeNode* right = q.front();
            q.pop();

            if (left == NULL && right == NULL)
                continue;

            if (left == NULL || right == NULL)
                return false;

            if (left->val != right->val)
                return false;

            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout<<s.isSymmetric(root)<<endl;
}