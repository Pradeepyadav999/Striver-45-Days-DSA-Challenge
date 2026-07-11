#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
	vector<int> succPredBST(TreeNode* root,int key){
		vector<int> ans;
        inorder(root, ans);
        int pre = -1;
        int suc = -1;
        for (int x : ans) {
            if (x < key)
                pre = x;
            else if (x > key) {
                suc = x;
                break;
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