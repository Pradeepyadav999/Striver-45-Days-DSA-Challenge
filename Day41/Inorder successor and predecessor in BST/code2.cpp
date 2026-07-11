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
    vector<int> succPredBST(TreeNode* root, int key) {

        int pre = -1;
        int suc = -1;
        TreeNode* curr = root;
        // Find predecessor
        while (curr) {
            if (curr->val < key) {
                pre = curr->val;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        curr = root;
        // Find successor
        while (curr) {
            if (curr->val > key) {
                suc = curr->val;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return {pre, suc};
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

    int key = 15;
    vector<int> result = solution.succPredBST(root, key);
    
    cout << "Predecessor: " << result[0] << ", Successor: " << result[1] << endl;
    return 0;
}
