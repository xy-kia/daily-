class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long mod = 1e9+7;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(2,0)));
        if(grid[0][0]>0){
            dp[0][0][0]=grid[0][0];   //记录i,j处的路径乘积最大非负值
            dp[0][0][1]=1;            //表示不存在该值
        }else if(grid[0][0]<0){
            dp[0][0][1]=grid[0][0];   //记录i,j处的路径乘积最小非正值
            dp[0][0][0]=-1;           //表示不存在该值
        }
        for(int j = 1;j < n;j++){    //更新第一行
            if(grid[0][j]>0){
                if(dp[0][j-1][0]>0){  //存在该值才更新
                    dp[0][j][0]=(dp[0][j-1][0]*grid[0][j]);
                    dp[0][j][1]=1;
                }
                if(dp[0][j-1][1]<0){
                    dp[0][j][1]=(dp[0][j-1][1]*grid[0][j]);
                    dp[0][j][0]=-1;
                }
            }else if(grid[0][j]<0){
                if(dp[0][j-1][0]>0){
                    dp[0][j][1]=(dp[0][j-1][0]*grid[0][j]);
                    dp[0][j][0]=-1;
                }
                if(dp[0][j-1][1]<0){
                    dp[0][j][0]=(dp[0][j-1][1]*grid[0][j]);
                    dp[0][j][1]=1;
                }
            }       //由于初始化为0，所以不需要
        }
        for(int i = 1;i<m;i++){    //更新第一列
            if(grid[i][0]>0){
                if(dp[i-1][0][0]>0){
                    dp[i][0][0]=(dp[i-1][0][0]*grid[i][0]);
                    dp[i][0][1]=1;
                }
                if(dp[i-1][0][1]<0){
                    dp[i][0][1]=(dp[i-1][0][1]*grid[i][0]);
                    dp[i][0][0]=-1;
                }
            }else if(grid[i][0]<0){
                if(dp[i-1][0][0]>0){
                    dp[i][0][1]=(dp[i-1][0][0]*grid[i][0]);
                    dp[i][0][0]=-1;
                }
                if(dp[i-1][0][1]<0){
                    dp[i][0][0]=(dp[i-1][0][1]*grid[i][0]);
                    dp[i][0][1]=1;
                }
            }
        }
        for(int i = 1;i<m;i++){
            for(int j=1;j<n;j++){    //更新到第i,j处
                long long x=-1;
                long long y=1;
                if(grid[i][j]>0){
                    if(dp[i-1][j][0]>0){
                        x=max(x,((dp[i-1][j][0]*grid[i][j])));
                    }
                    if(dp[i-1][j][1]<0){
                        y=min(y,((dp[i-1][j][1]*grid[i][j])));
                    }
                    if(dp[i-1][j][0]==0 || dp[i-1][j][1]==0){
                        x=max(x,0LL);
                        y=min(y,0LL);
                    }
                    if(dp[i][j-1][0]>0){
                        x=max(x,((dp[i][j-1][0]*grid[i][j])));
                    }
                    if(dp[i][j-1][1]<0){
                        y=min(y,((dp[i][j-1][1]*grid[i][j])));
                    }
                    if(dp[i][j-1][0]==0 || dp[i][j-1][1]==0){
                        x=max(x,0LL);
                        y=min(y,0LL);
                    }
                }else if(grid[i][j]<0){
                    if(dp[i-1][j][1]<0){
                        x=max(x,((dp[i-1][j][1]*grid[i][j])));
                    }
                    if(dp[i-1][j][0]>0){
                        y=min(y,((dp[i-1][j][0]*grid[i][j])));
                    }
                    if(dp[i-1][j][0]==0 || dp[i-1][j][1]==0){
                        x=max(x,0LL);
                        y=min(y,0LL);
                    }
                    if(dp[i][j-1][1]<0){
                        x=max(x,((dp[i][j-1][1]*grid[i][j])));
                    }
                    if(dp[i][j-1][0]>0){
                        y=min(y,((dp[i][j-1][0]*grid[i][j])));
                    }
                    if(dp[i][j-1][0]==0 || dp[i][j-1][1]==0 ){
                        x=max(x,0LL);
                        y=min(y,0LL);
                    }
                }else{
                    x=0LL;
                    y=0LL;
                }
                dp[i][j][0]=x;
                dp[i][j][1]=y;
            }
        }
        if(dp[m-1][n-1][0]>=0LL){
            return (dp[m-1][n-1][0]%mod);
        }else{
            return -1;
        }

    }
};