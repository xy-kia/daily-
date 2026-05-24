class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        for(int i = 1; i < n ;i++){
            if(nums[i] < nums[i-1]){
                if(start != 0 ){
                    return false;
                }
                start = i;
            }
        }
        if(start != 0 && nums[n-1] > nums[0]){
            return false;
        }
        return true;
    }
};