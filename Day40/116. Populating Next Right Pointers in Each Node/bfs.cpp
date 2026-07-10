#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            // Initially prev is NULL
            Node* prev=NULL;
            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();

                if(prev!=NULL){
                    prev->next=curr;
                }
                prev=curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            prev->next=NULL;
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    // Print the next pointers for each level
    Node* level_start = root;
    while (level_start) {
        Node* curr = level_start;
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
        level_start = level_start->left; // Move to the next level
    }

    return 0;
}