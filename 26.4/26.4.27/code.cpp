class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    // 四个方向：上，下，左，右
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(int x, int y, int from_x, int from_y, char target, vector<vector<char>>& grid) {
        // 已经访问过，说明成环
        if (visited[x][y]) {
            return true;
        }

        visited[x][y] = true;
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            // 边界检查 + 不能回到上一个点 + 字符相同
            if (nx >= 0 && nx < m && ny >= 0 && ny < n 
                && !(nx == from_x && ny == from_y) 
                && grid[nx][ny] == target) {
                if (dfs(nx, ny, x, y, target, grid)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
