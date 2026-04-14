class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start;
        int j=start;
        int n = nums.size();
        while(i>=0 || j<n){
            if(nums[i]==target){
                return start-i;
            }
            if(nums[j]==target){
                return j-start;
            }
            if((i-1)>=0){
                i--;
            }
            if((j+1)<n){
                j++;
            }
        }
        return -1;
    }
};