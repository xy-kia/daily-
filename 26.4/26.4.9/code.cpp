class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int v=queries[i][3];
            int k=queries[i][2];
            while(l<=r){
                long long x=(long long)nums[l]*v;
                x%=mod;
                nums[l]=x;
                l+=k;
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans ^=nums[i];
        }
        return ans;
    }
};