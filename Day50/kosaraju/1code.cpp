#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    // DFS on the transpose graph
    void revDFS(int node, vector<int> transpose[], vector<int> &visited) {
        visited[node] = 1;
        for (auto it : transpose[node]) {
            if (!visited[it]) {
                revDFS(it, transpose, visited);
            }
        }
    }
    // DFS to store nodes according to finish time
    void dfs(int node,vector<int> adj[],vector<int>&visited,stack<int>&st){
        visited[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(node);
    }
    int kosaraju(int V, vector<int> adj[]){
        stack<int> st;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        // transpose
        vector<int>transpose[V];
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                transpose[it].push_back(i);
            }
        }
        // Reset visited
        fill(visited.begin(), visited.end(), 0);
        int scc=0;
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
