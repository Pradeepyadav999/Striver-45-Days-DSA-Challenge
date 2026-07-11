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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1;i<preorder.size();i++){
            TreeNode* curr = root;
            while(true){
                if(preorder[i] < curr->val){    //Left subtree
                    if(curr->left == NULL){
                        curr->left = new TreeNode(preorder[i]);
                        break;
                    }
                    curr=curr->left;
                }else{  //Right Subtree
                    if(curr->right == NULL){
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    }
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};


int main() {
    Solution solution;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = solution.bstFromPreorder(preorder);
    return 0;
}