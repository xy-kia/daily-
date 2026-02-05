
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        vector<vector<long long>>dp(n,vector<long long>(3,LLONG_MIN));
        for(int i=1;i<n;i++){
            long long cur=nums[i];
            long long pre=nums[i-1];

            if(cur>pre){
                dp[i][0]=max(dp[i-1][0],pre)+cur;
                long long maxP=max(dp[i-1][2],dp[i-1][1]);
                if(maxP != LLONG_MIN){
                    dp[i][2] = maxP+cur;
                }
            }else if(cur<pre){
                long long maxP = max(dp[i-1][1],dp[i-1][0]);
                if(maxP != LLONG_MIN){
                    dp[i][1] = maxP + cur;
                }
            }
            if(dp[i][2]>ans){
                ans=dp[i][2];
            }
            
        }
        return ans == LLONG_MIN?0:ans;
    }
};