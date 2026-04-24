class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;

        // 1. 把相同数字的下标全部收集起来
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }

        // 2. 对每一组下标，用前缀和算距离和
        for (auto& [val, idx] : mp) {
            int m = idx.size();
            vector<long long> preSum(m + 1, 0);

            // 构建前缀和
            for (int i = 0; i < m; ++i) {
                preSum[i + 1] = preSum[i] + idx[i];
            }

            // 公式计算每个位置的答案
            for (int i = 0; i < m; ++i) {
                long long left = (long long)idx[i] * i - preSum[i];
                long long right = (preSum[m] - preSum[i + 1]) - (long long)idx[i] * (m - i - 1);
                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};