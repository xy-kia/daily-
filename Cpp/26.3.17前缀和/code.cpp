class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 预处理对角线前缀和（数组开 m+2/n+2 避免越界）
        // d1: ↘ 方向（行+1，列+1）
        // d2: ↙ 方向（行+1，列+2）
        vector<vector<int>> d1(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> d2(m + 2, vector<int>(n + 2, 0));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                d1[r + 1][c + 1] = grid[r][c] + d1[r][c];
                d2[r + 1][c + 1] = grid[r][c] + d2[r][c + 2];
            }
        }
        
        unordered_set<int> sums; // 存储所有菱形和，自动去重
        
        // 枚举每个上顶点 (r,c)
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // 单个格子本身也是边长为0的菱形
                sums.insert(grid[r][c]);
                
                // 枚举菱形半径 k（k=1 对应最小的完整菱形）
                for (int k = 1; k < m; ++k) {
                    // 检查四个顶点是否越界：下顶点、左顶点、右顶点
                    if (r + 2 * k >= m || c - k < 0 || c + k >= n) {
                        break; // 半径过大，后续k更大会越界，直接退出
                    }
                    
                    // 四个顶点坐标
                    // top: (r,c), bottom: (r+2k,c), left: (r+k,c-k), right: (r+k,c+k)
                    
                    // 计算四条边的和（利用前缀和快速计算）
                    int s1 = d1[(r + k) + 1][(c + k) + 1] - d1[r][c]; // 右上到顶的↘边
                    int s2 = d1[(r + 2 * k) + 1][c + 1] - d1[(r + k)][(c - k)]; // 左下到下的↘边
                    int s3 = d2[(r + k) + 1][(c - k) + 1] - d2[r][c + 2]; // 左上到顶的↙边
                    int s4 = d2[(r + 2 * k) + 1][c + 1] - d2[(r + k)][(c + k) + 2]; // 右下到下的↙边
                    
                    // 总和 = 四条边和 - 重复计算的四个顶点（每个顶点被加了两次）
                    int curSum = s1 + s2 + s3 + s4 
                                 - grid[r][c]          // top
                                 - grid[r + 2 * k][c]  // bottom
                                 - grid[r + k][c - k]  // left
                                 - grid[r + k][c + k]; // right
                    sums.insert(curSum);
                }
            }
        }
        
        // 排序：从大到小
        vector<int> sortedSums(sums.begin(), sums.end());
        sort(sortedSums.begin(), sortedSums.end(), greater<int>());
        
        // 取前3个（不足3个则取全部）
        int size = min(3, (int)sortedSums.size());
        vector<int> result;
        for (int i = 0; i < size; ++i) {
            result.push_back(sortedSums[i]);
        }
        return result;
    }
};