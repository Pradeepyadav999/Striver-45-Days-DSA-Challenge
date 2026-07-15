#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* prev = NULL;
    Node* head = NULL;

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev == NULL) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }

    Node* treeToDLL(Node* root) {
        inorder(root);
        return head;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution solution;
    Node* head = solution.treeToDLL(root);

    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->right;
    }

    return 0;
}