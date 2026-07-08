#include <iostream>
#include <vector>
#include <functional>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    unordered_map<int,int> mp;
    int postIndex;

    TreeNode* build(vector<int>& postorder,int inStart,int inEnd){

        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int pos = mp[root->val];

        root->right = build(postorder, pos+1, inEnd);
        root->left = build(postorder, inStart, pos-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        postIndex = postorder.size()-1;
        return build(postorder,0,inorder.size()-1);
    }
};

int main() {
    // Example usage:
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Output the constructed tree (inorder traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}