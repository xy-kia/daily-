typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n);

        // 小步长查询分组：和 Java 完全一样
        vector<vector<vector<int>>> smallKQueries(B);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (v == 1) continue;

            if (k >= B) {
                // 大步长：直接暴力更新
                for (int i = l; i <= r; i += k) {
                    nums[i] = (ll)nums[i] * v % MOD;
                }
            } else {
                // 小步长：先存起来
                smallKQueries[k].push_back({l, r, v});
            }
        }

        // 统一处理所有小步长
        for (int k = 1; k < B; ++k) {
            if (smallKQueries[k].empty()) continue;

            vector<ll> diff(n + k + 1, 1); // 乘法差分初始为 1

            for (auto& sq : smallKQueries[k]) {
                int l = sq[0], r = sq[1], v = sq[2];
                int endPos = l + ((r - l) / k + 1) * k;

                // 差分起点 * v
                diff[l] = diff[l] * v % MOD;
                ll invV = power(v, MOD - 2);
                // 差分终点 * 逆元
                if (endPos < n + k) {
                    diff[endPos] = diff[endPos] * invV % MOD;
                }
            }

            // 前缀积还原差分
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = diff[i] * diff[i - k] % MOD;
                }
                nums[i] = (ll)nums[i] * diff[i] % MOD;
            }
        }

        // 计算异或
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }

private:
    ll power(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
};