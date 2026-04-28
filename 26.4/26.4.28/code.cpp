class Solution {
public:
    // 每个数字 1~6 对应的：能往哪走（dx, dy）
    // 顺序：上下左右
    int dirs[5] = {-1, 0, 1, 0, -1};
    vector<vector<pair<int, int>>> shape = {
        {},                     // 0 占位
        {{0, -1}, {0, 1}},      // 1：左 ←→ 右
        {{-1, 0}, {1, 0}},      // 2：上 ↓↑ 下
        {{0, -1}, {1, 0}},      // 3：左 ↓ 下
        {{0, 1}, {1, 0}},       // 4：右 ↓ 下
        {{0, -1}, {-1, 0}},     // 5：左 ↑ 上
        {{0, 1}, {-1, 0}}       // 6：右 ↑ 上
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // DFS 从 (0,0) 出发，看能不能走到终点
        return dfs(0, 0, grid, visited, m, n);
    }

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n) {
        // 到达右下角 → 成功
        if (x == m - 1 && y == n - 1) return true;
        
        visited[x][y] = true;
        int type = grid[x][y];
        
        // 遍历当前街道允许的两个方向
        for (auto& d : shape[type]) {
            int nx = x + d.first;
            int ny = y + d.second;
            
            // 越界 / 已访问 → 跳过
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
            
            // 关键：下一个格子必须能**连回来**
            if (canConnect(grid[nx][ny], -d.first, -d.second)) {
                if (dfs(nx, ny, grid, visited, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }

    // 判断：当前街道 type，是否能接受从 (dx, dy) 方向进来的连接
    bool canConnect(int type, int dx, int dy) {
        for (auto& p : shape[type]) {
            if (p.first == dx && p.second == dy) {
                return true;
            }
        }
        return false;
    }
};