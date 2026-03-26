class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto& r : grid) for (int x : r) total += x;

        // 水平切
        long long pre = 0;
        for (int i = 0; i < m-1; ++i) {
            for (int x : grid[i]) pre += x;
            if (pre * 2 == total) return true;
        }

        // 垂直切
        pre = 0;
        for (int j = 0; j < n-1; ++j) {
            for (int i = 0; i < m; ++i) pre += grid[i][j];
            if (pre * 2 == total) return true;
        }

        return false;
    }
};