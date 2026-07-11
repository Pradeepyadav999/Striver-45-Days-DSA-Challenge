#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && root->val < q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && root->val > q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    Solution solution;
    TreeNode* p = root->left; 
    TreeNode* q = root->right;
    
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;

    return 0;
}