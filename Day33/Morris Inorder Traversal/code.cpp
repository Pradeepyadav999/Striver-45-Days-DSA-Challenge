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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        // curr pointing to root
        TreeNode* curr=root;
        while(curr!=NULL){
            // Case 1 ->No left present
            if(curr->left==NULL){
                inorder.push_back(curr->data);
                curr=curr->right;   //curr goes to rignt 
            }else{
                // Case 2->Move to left subtree rightmost element and make thread
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;   //We goes right if prev have right and its right pointer not pointing to curr
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr = curr->left;
                    // After threading we goes to left of root
                }else{
                    prev->right=NULL;   //Remove thread
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> inorderTraversal = sol.inorderTraversal(root);

    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}