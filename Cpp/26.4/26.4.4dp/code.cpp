class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        // 绑在一起按位置排序
        vector<vector<int>> pts(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            pts[i][0] = robots[i];
            pts[i][1] = distance[i];
        }
        sort(pts.begin(), pts.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        sort(walls.begin(), walls.end());
        
        // 统计机器人脚下的墙壁
        vector<int> W_at(n);
        for (int i = 0; i < n; ++i) {
            int pos = pts[i][0];
            int l = lower_bound(walls.begin(), walls.end(), pos) - walls.begin();
            //最后一个位置小于pos的下标
            int r = upper_bound(walls.begin(), walls.end(), pos) - walls.begin();
            //第一个位置大于pos的下标
            W_at[i] = r - l;
            //相减即为脚下的墙壁数
        }
        
        // 第一个机器人向左的墙壁数
        int idx_l_start = lower_bound(walls.begin(), walls.end(), pts[0][0] - pts[0][1]) - walls.begin();
        int idx_l_end = lower_bound(walls.begin(), walls.end(), pts[0][0]) - walls.begin();
        int ExtraL = max(0, idx_l_end - idx_l_start);
        
        // 最后一个机器人向右的墙壁数
        int idx_r_start = upper_bound(walls.begin(), walls.end(), pts[n-1][0]) - walls.begin();
        int idx_r_end = upper_bound(walls.begin(), walls.end(), pts[n-1][0] + pts[n-1][1]) - walls.begin();
        int ExtraR = max(0, idx_r_end - idx_r_start);
        
        // 计算每个间隙的贡献
        vector<int> L_only(n, 0);
        vector<int> R_only(n, 0);
        vector<int> Union(n, 0);
        
        for (int i = 1; i < n; ++i) {
            int p_prev = pts[i-1][0], d_prev = pts[i-1][1];
            int p_curr = pts[i][0], d_curr = pts[i][1];
            
            // 提取间隙内的墙壁范围
            int w_start = upper_bound(walls.begin(), walls.end(), p_prev) - walls.begin();
            int w_end = lower_bound(walls.begin(), walls.end(), p_curr) - walls.begin();
            
            if (w_start < w_end) {
                int gap_len = w_end - w_start;
                // i-1向右射击覆盖的墙
                auto left_it = walls.begin() + w_start;
                auto right_it = walls.begin() + w_end;
                int r_cnt = upper_bound(left_it, right_it, p_prev + d_prev) - left_it;
                R_only[i] = r_cnt;
                
                // i向左射击覆盖的墙
                int l_cnt = right_it - lower_bound(left_it, right_it, p_curr - d_curr);
                L_only[i] = l_cnt;
                
                // 两者覆盖墙的并集
                int neither_start = upper_bound(left_it, right_it, p_prev + d_prev) - walls.begin();
                int neither_end = lower_bound(left_it, right_it, p_curr - d_curr) - walls.begin();
                Union[i] = gap_len - max(0, neither_end - neither_start);
            }
        }
        
        // dp[i][0/1]: 机器人 i 向左/右射时，i之前及i脚下能摧毁的最大墙壁数
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // 初始化
        dp[0][0] = W_at[0] + ExtraL;
        dp[0][1] = W_at[0];
        
        for (int i = 1; i < n; ++i) {
            // i 向左射
            dp[i][0] = max(dp[i-1][0] + L_only[i], 
                           dp[i-1][1] + Union[i]) + W_at[i];
            //若i-1向左射，则这段间隙有向左射
            //若i-1向右射，则这段间隙二者皆有，取并集
            
            // i 向右射
            dp[i][1] = max(dp[i-1][0] + 0, 
                           dp[i-1][1] + R_only[i]) + W_at[i];
            //若i-1向左，则这段间隙没有被射
            //若i-1向右，则这段间隙只有向右
        }
        
        // 最后一步返回最大值
        return max(dp[n-1][0], dp[n-1][1] + ExtraR);

    }
};