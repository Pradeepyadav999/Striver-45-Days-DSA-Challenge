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
    bool isMirror(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if(left->val != right->val) return false;
        return isMirror(left->left,right->right) && isMirror(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
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