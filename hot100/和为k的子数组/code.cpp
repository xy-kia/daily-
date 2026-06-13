class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        int s = 0;
        for(int x: nums){
            cnt[s] ++;
            s += x;
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
        }
        return ans;
    }
};