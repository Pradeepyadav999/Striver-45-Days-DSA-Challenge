#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Line->level->node
        map<int, map<int, multiset<int>>> mp;
        // {node, {row, column}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node=it.first;
            int line=it.second.first;
            int level=it.second.second;
            mp[line][level].insert(node->data);
            if(node->left){
                q.push({node->left,{line-1,level+1}});
            }
            if(node->right){
                q.push({node->right,{line+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>column;
            // it.second-->its line and level
            for(auto iterate : it.second){
                for (int x : iterate.second) {
                     column.push_back(x);
}
            }
            ans.push_back(column);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal: " << endl;
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}