class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            // 只从连续序列的起点开始遍历（x-1 不存在）
            if (!s.count(x - 1)) {
                int cur = x;
                int len = 1;
                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};