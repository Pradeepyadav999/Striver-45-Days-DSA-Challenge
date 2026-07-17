#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int src, vector<int> adj[], vector<int> &vis) {

        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nbr : adj[node]) {

                if (!vis[nbr]) {

                    vis[nbr] = 1;
                    q.push({nbr, node});

                }
                else if (nbr != parent) {

                    return true;   // Cycle found

                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (bfs(i, adj, vis))
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
    if (obj.isCycle(V, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}