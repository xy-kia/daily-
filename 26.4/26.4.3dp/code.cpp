class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int dp[m + 1][n + 1][3];
        //走到i-1,j-1位置已经跳过k个负数时能获得的最大金币
        for(int i = 0; i <= m; i++)for(int j = 0; j <= n; j++)for(int k = 0; k < 3; k++) dp[i][j][k] = INT_MIN;
        //初始化
        for(int k = 0; k < 3; k++){
            dp[1][0][k] = 0;
            dp[0][1][k] = 0;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(coins[i][j] >= 0){
                    //大于0，捡金币
                    for(int k = 0; k < 3; k++){
                        dp[i + 1][j + 1][k] = max(dp[i][j + 1][k], dp[i + 1][j][k]) + coins[i][j];
                    }
                }
                else{
                    //小于0，扣或者跳过
                    for(int k = 0; k < 3; k++){
                        dp[i + 1][j + 1][k] = max(dp[i + 1][j][k], dp[i][j + 1][k]) + coins[i][j];
                    }
                    for(int k = 0; k < 2; k++){
                        //跳过,从跳过k个负数变为跳过k+1个负数
                        dp[i + 1][j + 1][k + 1] = max({dp[i + 1][j][k], dp[i][j + 1][k], dp[i + 1][j + 1][k + 1]});
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int k = 0; k < 3; k++) ans = max(ans, dp[m][n][k]);
        //取三者最大
        return ans;
    }
};