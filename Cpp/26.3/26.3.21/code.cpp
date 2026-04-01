class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> outerList;  // 最终结果矩阵
    
    // 遍历所有k×k子矩阵的左上角(row, col)
    for (int row = 0; row <= m - k; ++row) {
        vector<int> innerList;  // 存储当前行的所有子矩阵差值
        for (int col = 0; col <= n - k; ++col) {
            // 1. 提取当前k×k子矩阵的所有元素
            vector<int> values;
            for (int row2 = row; row2 < row + k; ++row2) {
                for (int col2 = col; col2 < col + k; ++col2) {
                    values.push_back(grid[row2][col2]);
                }
            }
            
            // 2. 排序元素，便于找相邻差值
            sort(values.begin(), values.end());
            
            // 3. 找最小的非零相邻差值
            int diff = INT_MAX;
            for (int i = 1; i < values.size(); ++i) {
                int current_diff = values[i] - values[i-1];
                if (current_diff != 0 && current_diff < diff) {
                    diff = current_diff;
                }
            }
            
            // 4. 如果所有元素相同（diff仍为INT_MAX），则存0，否则存最小差值
            innerList.push_back(diff == INT_MAX ? 0 : diff);
        }
        outerList.push_back(innerList);
    }
    
    return outerList;
    }
};