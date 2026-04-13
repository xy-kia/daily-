class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // 存每个数字 最近3个 位置
        vector<vector<int>> pos(n + 1);
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            pos[x].push_back(i);

            // 只要 >=3 个，就看 最后三个
            if (pos[x].size() >= 3) {
                int m = pos[x].size();
                int a = pos[x][m - 3];
                int b = pos[x][m - 2];
                int c = pos[x][m - 1];
                ans = min(ans, 2 * (c - a));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};