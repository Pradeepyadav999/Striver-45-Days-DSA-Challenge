#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, st);
            }
        }

        st.push(node);
    }

    void revDFS(int node, vector<int> transpose[], vector<int> &visited) {
        visited[node] = 1;

        for (auto it : transpose[node]) {
            if (!visited[it]) {
                revDFS(it, transpose, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {

        // Step 1: Convert edge list to adjacency list
        vector<int> adj[V];

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        // Step 2: DFS and store finish time
        stack<int> st;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Step 3: Build transpose graph
        vector<int> transpose[V];

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }

        // Step 4: Reset visited
        fill(visited.begin(), visited.end(), 0);

        // Step 5: DFS on transpose
        int scc = 0;

        while (!st.empty()) {

            int node = st.top();
            st.pop();

            if (!visited[node]) {
                scc++;
                revDFS(node, transpose, visited);
            }
        }

        return scc;
    }
};