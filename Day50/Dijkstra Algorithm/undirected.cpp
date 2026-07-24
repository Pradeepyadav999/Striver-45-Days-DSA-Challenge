#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Create adjacency list
        vector<vector<vector<int>>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Undirected graph
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min Heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (dis > dist[node]) continue;

            // Traverse neighbors
            for (auto &it : adj[node]) {

                int adjNode = it[0];
                int wt = it[1];

                if (dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};