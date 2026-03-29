class Solution {
public:
    int longestBalanced(vector<int>& nums) {
         int numsLength = nums.size();
        int result = 0;
        // 外层循环：枚举子数组起始位置
        for (int i = 0; i < numsLength; i++) {
            // 每次起始位置变更，重置两个集合（统计当前子数组的不同奇/偶数）
            unordered_set<int> odd;   // 对应Java的HashSet<Integer> odd
            unordered_set<int> even;  // 对应Java的HashSet<Integer> even
            // 内层循环：枚举子数组结束位置
            for (int j = i; j < numsLength; j++) {
                // 判断奇偶并加入对应集合
                if (nums[j] % 2 == 1) {
                    odd.insert(nums[j]); // C++中add对应insert
                } else {
                    even.insert(nums[j]);
                }
                // 满足平衡条件且当前长度更大时，更新结果
                if (odd.size() == even.size() && result < j - i + 1) {
                    result = j - i + 1;
                }
            }
        }
        return result;
    }
};
    