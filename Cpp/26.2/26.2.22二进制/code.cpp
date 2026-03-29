class Solution {
public:
    int countPrimeSetBits(int left, int right) {
       unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0; // 统计符合条件的数字个数
        
        // 遍历[left, right]范围内的所有数字
        for (int num = left; num <= right; ++num) {
            // 计算当前数字二进制中1的个数（使用__builtin_popcount内置函数，高效且简洁）
            int bits = __builtin_popcount(num);
            // 判断1的个数是否在质数集合中
            if (primes.find(bits) != primes.end()) {
                count++;
            }
        }
        return count;
    }
};               