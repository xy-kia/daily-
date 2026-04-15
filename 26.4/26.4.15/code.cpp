class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int n = robot.size();
        int m = factory.size();

        // dp[i][j]：前 i 个工厂修理前 j 个机器人的最小距离
        long long inf = LLONG_MAX / 2;
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, inf));

        // 边界：0 个机器人，距离都是 0
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }

        // 递推
        for (int i = 1; i <= m; ++i) {
            int pos = factory[i - 1][0];
            int limit = factory[i - 1][1];

            for (int j = 1; j <= n; ++j) {
                // 第 i 个工厂一个不修
                dp[i][j] = dp[i - 1][j];

                long long cur_dist = 0;
                // 第 i 个工厂修 k 个机器人
                for (int k = 1; k <= min(j, limit); ++k) {
                    // 累加距离
                    cur_dist += abs((long long)robot[j - k] - pos);
                    // 状态转移
                    if (dp[i - 1][j - k] != inf) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + cur_dist);
                    }
                }
            }
        }

        return dp[m][n];

    }
};