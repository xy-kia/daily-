class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mins = ranges::min(nums);
        int maxs = ranges::max(nums);
        return gcd(mins, maxs);
    }
};