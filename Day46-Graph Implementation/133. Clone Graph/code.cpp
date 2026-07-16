#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        // If empty
        if(node==NULL){
            return NULL;
        }
        // If already cloned
        if(mp.count(node)){
            return mp[node];
        }
        // Clone
        Node* clone = new Node(node->val);
        mp[node]=clone;
        // For neighbours
        for(Node* nbr : node->neighbors){
            clone->neighbors.push_back(cloneGraph(nbr));
        }
        return clone;
    }
};

int main(){
    Node* node = new Node(1);
    node->neighbors.push_back(new Node(2));
    node->neighbors.push_back(new Node(3));
    node->neighbors.push_back(new Node(4));

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node);

    cout << "Cloned Graph:" << endl;
    cout << "Node: " << clonedGraph->val << endl;
    cout << "Neighbors: ";
    for (Node* neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    return 0;
}