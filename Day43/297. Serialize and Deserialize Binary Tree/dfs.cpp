#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // -------- Serialize --------
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // -------- Deserialize --------
    TreeNode* buildTree(stringstream &ss) {
        string str;
        getline(ss, str, ',');

        if (str == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(str));

        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};