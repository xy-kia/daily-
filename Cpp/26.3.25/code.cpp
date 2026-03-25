class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int L = n * m;
        const int MOD = 12345;

        // 二维转一维
        vector<int> nums(L);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                nums[idx++] = grid[i][j];
            }
        }

        // 前缀乘积 pre
        vector<int> pre(L);
        pre[0] = 1;
        for (int k = 1; k < L; ++k) {
            pre[k] = (long long)pre[k-1] * (nums[k-1] % MOD) % MOD;
        }

        // 后缀乘积 suf
        vector<int> suf(L);
        suf[L-1] = 1;
        for (int k = L-2; k >= 0; --k) {
            suf[k] = (long long)suf[k+1] * (nums[k+1] % MOD) % MOD;
        }

        // 构造答案
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int k = i * m + j;
                ans[i][j] = (long long)pre[k] * suf[k] % MOD;
            }
        }

        return ans;
    }
};