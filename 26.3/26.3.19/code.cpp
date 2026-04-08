class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int result = 0;
        int he=grid.size();
        int wi=grid[0].size();
        vector<vector<int>>dp(he,vector<int>(wi,0));
        dp[0][0]=grid[0][0];
        if(dp[0][0]<=k){
            result++;
        }
        for(int i=1;i<he;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
            if(dp[i][0]<=k){
                result++;
            }
        }
        for(int i=1;i<wi;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
            if(dp[0][i]<=k){
                result++;
            }
        }
        for (int i=1;i<he;i++){
            for (int j=1;j<wi;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i][j];
                if (dp[i][j]<=k){
                    result++;
                }
            }
        }
        return result;
    }
};