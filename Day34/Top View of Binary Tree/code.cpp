#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        if (root == NULL)
            return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node=it.first;
            int line = it.second;
            
            if(mp.find(line)==mp.end()){
                mp[line]=node->data;
            }
            if(node->left != NULL){
                q.push({node->left,line-1});
            }
            if(node->right != NULL){
                q.push({node->right,line+1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> result = solution.topView(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}