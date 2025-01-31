class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n, -1);
        vector<int> size(m * n, 0);
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];  
                x = parent[x];
            }
            return x;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    parent[idx] = idx;
                    size[idx] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    for (auto [dx, dy] : directions) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            int neighborIdx = x * n + y;
                            int root1 = find(idx);
                            int root2 = find(neighborIdx);
                            if (root1 != root2) {
                                parent[root2] = root1;
                                size[root1] += size[root2];
                            }
                        }
                    }
                }
            }
        }
        int maxSize = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    maxSize = max(maxSize, size[find(idx)]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int newSize = 1;
                    set<int> uniqueRoots;
                    for (auto [dx, dy] : directions) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            int neighborIdx = x * n + y;
                            int root = find(neighborIdx);
                            uniqueRoots.insert(root);
                        }
                    }
                    for (int root : uniqueRoots) {
                        newSize += size[root];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};