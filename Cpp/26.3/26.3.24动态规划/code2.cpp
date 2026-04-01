class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        
        // 1. long long 防溢出，dp[i][j][0]=最大值，dp[i][j][1]=最小值
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2)));
        
        // 2. 起点初始化：无硬编码，直接赋值真实值
        dp[0][0][0] = dp[0][0][1] = (long long)grid[0][0];
        
        // 3. 第一行：仅从左边来，真实乘积传递
        for (int j = 1; j < n; j++) {
            long long val = (long long)grid[0][j];
            dp[0][j][0] = dp[0][j-1][0] * val;
            dp[0][j][1] = dp[0][j-1][1] * val;
        }
        
        // 4. 第一列：仅从上面来，真实乘积传递
        for (int i = 1; i < m; i++) {
            long long val = (long long)grid[i][0];
            dp[i][0][0] = dp[i-1][0][0] * val;
            dp[i][0][1] = dp[i-1][0][1] * val;
        }
        
        // 5. 中间位置：枚举所有前驱乘积，取真实最大/最小值
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = (long long)grid[i][j];
                // 取出上方/左方的真实最大/最小值
                long long up_max = dp[i-1][j][0], up_min = dp[i-1][j][1];
                long long left_max = dp[i][j-1][0], left_min = dp[i][j-1][1];
                
                // 计算4种可能的乘积（所有路径的真实乘积）
                long long p1 = up_max * val;
                long long p2 = up_min * val;
                long long p3 = left_max * val;
                long long p4 = left_min * val;
                
                // 取真实最大值和最小值（无硬编码）
                dp[i][j][0] = max({p1, p2, p3, p4});
                dp[i][j][1] = min({p1, p2, p3, p4});
            }
        }
        
        // 6. 结果处理：取模 + 处理负数
        long long ans = dp[m-1][n-1][0];
        if (ans < 0) return -1;
        return (int)((ans % MOD + MOD) % MOD); // 确保结果为正
    }
};