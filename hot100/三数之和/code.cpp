class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int k = 0;k<n-2;k++){
            if(nums[k]>0){
                break;
            }
            if(k > 0 && nums[k-1] == nums[k]){
                continue;
            }
            int i = k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[k]+nums[i]+nums[j];
                if(sum<0){
                    while(i<j && nums[i]==nums[++i]);
                }else if (sum >0){
                    while(i<j && nums[j]==nums[--j]);
                }else{
                    vector<int>toadd = {nums[k],nums[i],nums[j]};
                    ans.push_back(toadd);
                    while(i<j && nums[i] == nums[++i]);
                    while(i<j && nums[j] == nums[--j]);
                }
            }
        }
        return ans;
    }
};