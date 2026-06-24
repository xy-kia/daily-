class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        constexpr int MOD = 1'000'000'007;
        int k = r - l + 1;
        vector<int> f(k, 1);

        for (int i = 1; i < n; i++) {
            if (i % 2) { // 增
                long long pre = 0;
                for (int j = 0; j < k; j++) {
                    int v = f[j];
                    f[j] = pre % MOD;
                    pre += v;
                }
            } else { // 减
                long long suf = 0;
                for (int j = k - 1; j >= 0; j--) {
                    int v = f[j];
                    f[j] = suf % MOD;
                    suf += v;
                }
            }
        }

        return reduce(f.begin(), f.end(), 0LL) * 2 % MOD;
    }
};