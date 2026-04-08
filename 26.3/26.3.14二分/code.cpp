class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        // 找到最快的工人，计算最坏情况（仅他一人完成）的时间作为上界
        int minW = INT_MAX;
        for (int w : workerTimes) {
            if (w < minW) {
                minW = w;
            }
        }
        long long high = (long long)minW * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        // 二分查找核心逻辑
        while (low <= high) {
            long long mid = low + (high - low) / 2; // 防止溢出的写法
            if (check(mid, mountainHeight, workerTimes)) {
                ans = mid;      // 当前时间可行，尝试找更短的时间
                high = mid - 1;
            } else {
                low = mid + 1;  // 时间不够，需要更长时间
            }
        }
        return ans;
    }

private:
    // 检查在limit时间内，所有工人能否完成至少mountainHeight的高度
    bool check(long long limit, int mountainHeight, vector<int>& workerTimes) {
        long long total_h = 0;
        for (int w : workerTimes) {
            // 公式推导：w * x*(x+1)/2 <= limit → x² + x - 2*limit/w <= 0
            // 求根公式 x = [-1 + sqrt(1 + 8*limit/w)] / 2
            double sqrt_val = sqrt(1 + 8.0 * limit / w);
            long long x = (long long)((sqrt_val - 1) / 2);
            
            total_h += x;
            
            // 提前终止，优化性能
            if (total_h >= mountainHeight) {
                return true;
            }
        }
        return total_h >= mountainHeight;
    }
};