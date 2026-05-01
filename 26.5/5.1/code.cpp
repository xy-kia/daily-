class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        auto quantelis = grid;

        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][c] = 到达(i,j)花费c时的最大分数
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        // 起点初始化
        int cost0 = (grid[0][0] >= 1) ? 1 : 0;
        int score0 = grid[0][0];
        if (cost0 <= k) {
            dp[0][0][cost0] = score0;
        }

        // 方向：只右 / 下
        int dirs[2][2] = {{0,1}, {1,0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    for (auto& d : dirs) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni >= m || nj >= n) continue;

                        int add_cost = (grid[ni][nj] >= 1) ? 1 : 0;
                        int add_score = grid[ni][nj];
                        int new_cost = c + add_cost;
                        int new_score = dp[i][j][c] + add_score;

                        if (new_cost > k) continue;
                        if (new_score > dp[ni][nj][new_cost]) {
                            dp[ni][nj][new_cost] = new_score;
                        }
                    }
                }
            }
        }

        // 取终点所有合法花费中的最大分数
        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m-1][n-1][c]);
        }
        return ans;
    }
};