#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    void dfs(int node,
             vector<int>& vis,
             vector<vector<int>>& adj,
             vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr, vis, adj, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        vector<int> ans;
        dfs(0, vis, adj, ans);
        return ans;
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        vector<int> ans;
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr : adj[node]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int V = 5; 
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}}; 

    vector<int> dfsResult = sol.dfsOfGraph(V, edges);
    cout << "DFS Traversal: ";
    for(int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    vector<int> bfsResult = sol.bfsOfGraph(V, edges);
    cout << "BFS Traversal: ";
    for(int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}