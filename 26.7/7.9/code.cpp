static constexpr int MOD = 1'000'000'007;
static constexpr int MAX_N = 100'001;
int pow10[MAX_N];

int init = [] {
    // 预处理 10 的幂
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pow10[i] = pow10[i - 1] * 10LL % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(const string& s, const vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum_d(n + 1), pre_num(n + 1), sum_non_zero(n + 1);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum_d[i + 1] = sum_d[i] + d; // s 的前缀和
            pre_num[i + 1] = d > 0 ? (pre_num[i] * 10LL + d) % MOD : pre_num[i]; // s 的前缀对应的数字（模 MOD）
            sum_non_zero[i + 1] = sum_non_zero[i] + (d > 0); // s 的前缀中的非零数字个数
        }

        vector<int> ans;
        ans.reserve(queries.size()); // 预分配空间
        for (auto& q : queries) {
            int l = q[0], r = q[1] + 1; // 注意这里已经把 r 加一了
            int length = sum_non_zero[r] - sum_non_zero[l];
            long long x = pre_num[r] - 1LL * pre_num[l] * pow10[length] % MOD + MOD; // +MOD 保证结果非负
            ans.push_back(x * (sum_d[r] - sum_d[l]) % MOD);
        }
        return ans;
    }
};