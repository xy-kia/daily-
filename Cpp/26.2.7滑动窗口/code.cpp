class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<n;i++){
            long x = (long)nums[i]*k;
            while(nums[j]<=x && j<=n-2){
                j++;
            }
            int res = n-j+i;
            if(j==(n-1) && nums[j]<=x){
                res--;
            }
            ans = min(ans,res);
            if(j==n-1 && x>=nums[j]){
                break;
            }     
        }
        return ans;    
    }
};