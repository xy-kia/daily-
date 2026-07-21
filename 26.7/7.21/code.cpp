class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total; // 超过总长度的偏移直接取模
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // 当前一维下标
                int pos = i * n + j;
                // 右移k后的新下标
                int newPos = (pos + k) % total;
                // 转回二维坐标
                int ni = newPos / n;
                int nj = newPos % n;
                res[ni][nj] = grid[i][j];
            }
        }
        return res;
    }
};