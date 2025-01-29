class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initialize each node to be its own parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Find function with path compression
        function<int(int)> find = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            return parent[node];
        };

        // Union function
        auto unite = [&](int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false; // Cycle detected
            parent[pu] = pv;
            return true;
        };

        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};
