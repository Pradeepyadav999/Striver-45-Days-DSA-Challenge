#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {

        vis[node] = 1;

        for (int nbr : adj[node]) {

            // If neighbor is not visited
            if (!vis[nbr]) {

                if (dfs(nbr, node, adj, vis))
                    return true;
            }

            // If neighbor is visited and is NOT the parent
            else if (nbr != parent) {

                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);

        // Handle disconnected components
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    if (obj.isCycle(V, adj))
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle detected in the graph." << endl;

    return 0;
}