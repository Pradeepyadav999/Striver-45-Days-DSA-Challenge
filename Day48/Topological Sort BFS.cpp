#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);
        // Creating indegree array
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            // Node in your topo topoSort
            // please remove it from indegree
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo;
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
    }

    Solution obj;
    vector<int> topoOrder = obj.topoSort(V, adj);

    cout << "Topological Sort Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}