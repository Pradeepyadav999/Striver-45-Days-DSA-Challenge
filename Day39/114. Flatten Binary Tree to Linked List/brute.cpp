#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preOrderT(TreeNode* root,vector<TreeNode*>& preorder){
        if(root==NULL){
            return;
        }
        preorder.push_back(root);
        preOrderT(root->left,preorder);
        preOrderT(root->right,preorder);

    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        } 
        vector<TreeNode*>preorder;
        preOrderT(root,preorder);
        // Connect LinkedList
        for(int i=0;i<preorder.size()-1;i++){
            preorder[i]->left=NULL;
            preorder[i]->right=preorder[i+1];
        }
        preorder.back()->left=NULL;
        preorder.back()->right=NULL;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    // Output the flattened linked list
    cout << "Flattened Linked List: ";
    TreeNode* current = root;
    while (current) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}