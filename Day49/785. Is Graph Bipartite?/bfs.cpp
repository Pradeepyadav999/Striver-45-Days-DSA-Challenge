#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {

        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int nbr : graph[node]) {

                // If not colored
                if (color[nbr] == -1) {
                    color[nbr] = 1 - color[node];
                    q.push(nbr);
                }

                // Same color as current node
                else if (color[nbr] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);

        // Handle disconnected graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    Solution obj;
    bool ans = obj.isBipartite(graph);

    if (ans)
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is not bipartite." << endl;

    return 0;
}