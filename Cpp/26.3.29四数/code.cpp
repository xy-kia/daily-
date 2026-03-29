class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;  // 存储最终结果
        int n = nums.size();
        if (n < 4) return res;   // 数组长度小于4，直接返回空
        
        sort(nums.begin(), nums.end());  // 1. 排序：为双指针和去重做准备
        
        // 固定第一个数 i
        for (int i = 0; i < n - 3; ++i) {
            // 对i去重：和前一个数相同，跳过
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // 固定第二个数 j
            for (int j = i + 1; j < n - 2; ++j) {
                // 对j去重：和前一个数相同，跳过
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int left = j + 1;   // 左指针：j的下一位
                int right = n - 1;  // 右指针：数组末尾
                
                // 双指针遍历
                while (left < right) {
                    // 用long long防止整数溢出（关键！）
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        // 找到符合条件的四元组，加入结果
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // 对left去重
                        while (left < right && nums[left] == nums[left+1]) left++;
                        // 对right去重
                        while (left < right && nums[right] == nums[right-1]) right--;
                        
                        // 移动指针，寻找下一组解
                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        // 和太小，左指针右移（增大数值）
                        left++;
                    }
                    else {
                        // 和太大，右指针左移（减小数值）
                        right--;
                    }
                }
            }
        }
        return res;
    }
};