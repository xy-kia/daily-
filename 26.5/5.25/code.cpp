class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> temp;
        vector<int> dp(n, 0);
        int ans = 1;
        for(int i = 0;i < n; i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n;i++){
            int index = temp[i][1];
            dp[index] = 1;
            for(int j = index - 1; j >= index - d && j >= 0; j--){
                if(arr[j] >= arr[index]){
                    break;
                }
                if(dp[j] !=0){
                    dp[index] = max(dp[index], dp[j] + 1);
                }
            }
            for(int j = index + 1; j <= index + d && j <= n-1; j++){
                if(arr[j] >= arr[index]){
                    break;
                }
                if(dp[j] != 0){
                    dp[index] = max(dp[index], dp[j] + 1);
                }
            }
            ans = max(dp[index], ans);
        }
        return ans;

        
    }
};