class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 先记录当前数字的最后一位（最低位）
        int prev_bit = n & 1;
        // 右移一位，去掉已经检查过的最低位
        n = n >> 1;
        
        // 循环检查剩余的位
        while (n > 0) {
            // 获取当前的最低位
            int curr_bit = n & 1;
            // 如果当前位和前一位相同，说明不是交替的，直接返回false
            if (curr_bit == prev_bit) {
                return false;
            }
            // 更新前一位为当前位，继续检查下一位
            prev_bit = curr_bit;
            // 右移一位
            n = n >> 1;
        }
        // 所有位都检查完毕，是交替的
        return true;
    }
};