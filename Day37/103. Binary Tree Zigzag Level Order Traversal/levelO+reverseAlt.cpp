#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false; // Flag to indicate whether to reverse the level order
        while(!q.empty()){
            int size = q.size();    // // Number of nodes in current level
            vector<int>level;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // Now we have to push to ans
            if(rev){
                std::reverse(level.begin(), level.end());
            }
            rev = !rev; // Toggle the reverse flag for the next level
            ans.push_back(level);
        }
        return ans;
    }
};
     
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal: " << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}