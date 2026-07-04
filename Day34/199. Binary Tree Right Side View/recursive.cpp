// DFS
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
    void solve(TreeNode* root, int level, vector<int>&res){
        if(root==NULL){
            return;
        }
        // Push if ds size==level
        if(res.size()==level){
            res.push_back(root->val);
        }
        // go right
        solve(root->right,level+1,res);
        // go left
        solve(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root,0,res);
        return res;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> ans = s.rightSideView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}