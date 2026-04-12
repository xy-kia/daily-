class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
    int n = nums.size();
    
    // 第一步：记录每个数字的所有下标
    for (int i = 0; i < n; ++i) {
        pos[nums[i]].push_back(i);
    }
    
    int min_dist = INT_MAX;  // 初始化最小距离为最大值
    
    // 第二步：遍历每个数字的下标列表
    for (auto& pair : pos) {
        vector<int>& indices = pair.second;
        int m = indices.size();
        // 下标数量不足3个，无法组成三元组，跳过
        if (m < 3) continue;
        
        // 暴力枚举所有三元组组合 (i,j,k) 且 i<j<k
        for (int a = 0; a < m; ++a) {
            for (int b = a + 1; b < m; ++b) {
                for (int c = b + 1; c < m; ++c) {
                    int x = indices[a];
                    int y = indices[b];
                    int z = indices[c];
                    // 化简后的距离公式：2*(最大下标 - 最小下标)
                    int dist = 2 * (z - x);
                    // 更新最小距离
                    if (dist < min_dist) {
                        min_dist = dist;
                    }
                }
            }
        }
    }
    
    // 没有有效三元组返回-1，否则返回最小值
    return min_dist == INT_MAX ? -1 : min_dist;
    }
};