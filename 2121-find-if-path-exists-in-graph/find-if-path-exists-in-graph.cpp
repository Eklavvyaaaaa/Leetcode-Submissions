class Solution {
private:
    bool dfs(int current, int destination, vector<vector<int>>& adj,
             vector<int>& vis) {
        if (current == destination) {
            return true;
        }

        vis[current] = 1;

        for (int neighbour : adj[current]) {
            if (vis[neighbour] == 0) {
                if (dfs(neighbour, destination, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source, destination, adj, vis);
    }
};

