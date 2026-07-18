#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> indegree(N, 0);
        for(int i=0;i<N;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==N){
            return false;
        }
        else{
            return true;
        }
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