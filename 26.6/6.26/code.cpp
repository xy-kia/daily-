class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // 前缀平衡计数数组，偏移 n 避免下标负数
        // 平衡定义：遇到 target +1，其他数字 -1
        // cnt[val + n] = 此前前缀平衡值为 val 的出现次数
        vector<int> cnt(n * 2 + 1);
        // 初始前缀平衡 s=0（未遍历任何元素时），偏移后下标 n，出现次数初始化为1
        cnt[n] = 1;

        long long ans = 0; // 存储总合法子数组数，防止溢出用long long
        int s = n;         // 当前前缀平衡值，初始等价于平衡0（偏移n）
        int f = 0;         // 动态维护：当前前缀s下，满足平衡差>0的前缀数量

        for (int x : nums) {
            if (x == target) {
                // 当前是target，平衡值+1
                // 所有之前平衡等于当前s的前缀都能和当前形成合法子数组，加到f
                f += cnt[s];
                s++;
            } else {
                // 当前不是target，平衡值-1，先更新s再更新f
                s--;
                // 平衡下降，要减去等于新s的前缀数量
                f -= cnt[s];
            }
            // 遍历到当前位置时，f就是以当前下标为右端点的合法子数组总数
            ans += f;
            // 将当前平衡值s的计数+1，存入cnt数组供后续遍历使用
            cnt[s]++;
        }
        return ans;
    }
};