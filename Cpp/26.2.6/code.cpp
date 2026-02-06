class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int y=(i+x)%n;
            if(y<0){
                y+=n;
            }
            ans[i]=nums[y];
        }
        return ans;
    }
};