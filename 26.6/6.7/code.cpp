class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int after = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            int x = nums[i];
            nums[i] = abs(sum - after * 2 - x );
            after += x;
        }
        return nums;
    }
};