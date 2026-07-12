#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> kLargesSmall(TreeNode* root, int k) {

        vector<int> ans;
        inorder(root, ans);

        int n = ans.size();

        int smallest = ans[k - 1];
        int largest = ans[n - k];

        return {smallest, largest};
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->right = new TreeNode(40);

    int k = 2;
    vector<int> result = solution.kLargesSmall(root, k);

    cout << "Kth Smallest: " << result[0] << ", Kth Largest: " << result[1] << endl;
    return 0;
}