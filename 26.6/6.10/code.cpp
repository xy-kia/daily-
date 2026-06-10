class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return k*(0ll+ranges::max(nums)-ranges::min(nums));
    }
};