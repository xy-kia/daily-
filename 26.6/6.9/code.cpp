class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> mids;
        vector<int>right;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            }else if(nums[i] == pivot){
                mids.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }
        vector<int>ans;
        ans.insert(ans.end(),left.begin(),left.end());
        ans.insert(ans.end(),mids.begin(),mids.end());
        ans.insert(ans.end(),right.begin(),right.end());
        return ans;
    }
};