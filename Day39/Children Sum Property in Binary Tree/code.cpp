#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root==NULL) return true;
        // Leaf node
        if(root->left == NULL && root->right == NULL) return true;
        int left=0,right=0;
        if (root->left)
            left = root->left->data;
        if (root->right)
            right = root->right->data;
        return (root->data == left + right) && isSumProperty(root->left) && isSumProperty(root->right);
    }
};

int main() {
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    Solution obj;
    if (obj.isSumProperty(root))
        cout << "The given tree satisfies the children sum property";
    else
        cout << "The given tree does not satisfy the children sum property";
}