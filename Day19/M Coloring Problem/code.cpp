class Solution{
public:
    bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& adj){
        for (int neighbor : adj[node]) {
            if (colors[neighbor] == color)
                return false;
        }
        return true;
    }
    bool solve(int node, int n, int m, vector<int>& colors, vector<vector<int>>& adj){
        if(node==n){
            return true;
        }
        for(int color=1;color<=m;color++){
            if(isSafe(node, color, colors, adj)){
                colors[node]=color;
                if(solve(node + 1, n, m, colors, adj)){
                    return true;
                }
                colors[node]=0;   // backtrack
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n, 0);
        return solve(0, n, m, colors, adj);
    }
};