#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {

        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {

                if (dfs(it, adj, vis, dfsVis))
                    return true;

            }
            else if (dfsVis[it]) {

                return true;
            }
        }

        dfsVis[node] = 0;   // Remove from recursion stack
        return false;
    }

    bool isCyclic(int N, vector<int> adj[]) {

        vector<int> vis(N, 0);
        vector<int> dfsVis(N, 0);

        for (int i = 0; i < N; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, dfsVis))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> adj[N];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    bool ans = obj.isCyclic(N, adj);

    if (ans)
        cout << "Cycle detected in the directed graph." << endl;
    else
        cout << "No cycle detected in the directed graph." << endl;

    return 0;
}