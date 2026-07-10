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
    TreeNode* build(vector<int>& nums, int left, int right) {
        // Base case
        if (left > right)
            return NULL;

        // Find middle element
        int mid = left + (right - left) / 2;

        // Create root node
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = build(nums, left, mid - 1);

        // Build right subtree
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);
    // You can add code here to print the tree or verify its structure
    return 0;
}