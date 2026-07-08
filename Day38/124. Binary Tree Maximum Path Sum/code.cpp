#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int solve(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        int leftSum=solve(root->left,maxi);
        int rightSum=solve(root->right,maxi);

        maxi=max(maxi,leftSum+rightSum+root->data);
        return root->data+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int result = sol.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}