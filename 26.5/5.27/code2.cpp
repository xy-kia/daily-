class Solution {
public:
    int numberOfSpecialChars(string word) {
        int mask[2]{}; // 大写字母集合、小写字母集合
        for (char c : word) {
            // 用 c>>5&1 区分大小写，c&31 获取 c 是第几个字母
            mask[c >> 5 & 1] |= 1 << (c & 31);
        }
        return popcount(1u * (mask[0] & mask[1])); // 计算交集大小
    }
};