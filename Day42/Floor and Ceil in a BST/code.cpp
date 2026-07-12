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
    vector<int> floorCeilOfBST(TreeNode* root, int key) {

        int floor = -1;
        int ceil = -1;
        TreeNode* curr = root;

        // Find Floor
        while (curr) {
            if (curr->data == key) {
                floor = curr->data;
                break;
            }
            else if (curr->data < key) {
                floor = curr->data;
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        curr = root;

        while (curr) {
            if (curr->data == key) {
                ceil = curr->data;
                break;
            }
            else if (curr->data > key) {
                ceil = curr->data;
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return {floor, ceil};
    }
};