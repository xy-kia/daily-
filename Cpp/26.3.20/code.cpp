class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans = 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<vector<int>>x_count(m,vector<int>(n,0));
        if(grid[0][0]=='X'){
            dp[0][0]++;
            x_count[0][0]++;
        }else if(grid[0][0]=='Y'){
            dp[0][0]--;
        }
        for(int i=1;i<m;i++){
            if(grid[i][0]=='X'){
                dp[i][0]=dp[i-1][0]+1;
                x_count[i][0]=x_count[i-1][0]+1;
            }else if(grid[i][0]=='Y'){
                dp[i][0]=dp[i-1][0]-1;
                x_count[i][0]=x_count[i-1][0];
            }else{
                dp[i][0]=dp[i-1][0];
                x_count[i][0]=x_count[i-1][0];
            }
            if(dp[i][0]==0 && x_count[i][0]>0){
                ans++;
            }
        }
        for(int i=1;i<n;i++){
            if(grid[0][i]=='X'){
                dp[0][i]=dp[0][i-1]+1;
                x_count[0][i]=x_count[0][i-1]+1;
            }else if(grid[0][i]=='Y'){
                dp[0][i]=dp[0][i-1]-1;
                x_count[0][i]=x_count[0][i-1];
            }else{
                dp[0][i]=dp[0][i-1];
                x_count[0][i]=x_count[0][i-1];
            }
            if(dp[0][i]==0 && x_count[0][i]>0){
                ans++;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]=='X'){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]+1-dp[i-1][j-1];
                    x_count[i][j] =x_count[i-1][j]+x_count[i][j-1]+1-x_count[i-1][j-1];
                }else if(grid[i][j]=='Y'){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-1-dp[i-1][j-1];
                    x_count[i][j] =x_count[i-1][j]+x_count[i][j-1]-x_count[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                    x_count[i][j] =x_count[i-1][j]+x_count[i][j-1]-x_count[i-1][j-1];
                }
                if(dp[i][j]==0 && x_count[i][j] >0){
                    ans++;
                }
            }
        }
        return ans;
    }
};