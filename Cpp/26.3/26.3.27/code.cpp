class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // 计算所有元素总和
        long long totalSum = 0;
        for (auto& row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

        // 检查水平分割
        if (checkHorizontal(grid, totalSum)) {
            return true;
        }

        // 检查垂直分割：矩阵转置后复用水平分割逻辑
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> gridT(n, vector<int>(m));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                gridT[c][r] = grid[r][c];
            }
        }
        return checkHorizontal(gridT, totalSum);
    }

private:
    bool checkHorizontal(vector<vector<int>>& mat, long long totalSum) {
        int m = mat.size();
        int n = mat[0].size();

        // 下方矩形的元素频率
        unordered_map<int, int> p2Counts;
        for (auto& row : mat) {
            for (int val : row) {
                p2Counts[val]++;
            }
        }

        // 上方矩阵的元素频率和总和
        unordered_map<int, int> p1Counts;
        long long p1Sum = 0;

        // 遍历所有水平分割线
        for (int i = 0; i < m - 1; i++) {
            // 将第 i 行从 P2 移动到 P1
            for (int j = 0; j < n; j++) {
                int val = mat[i][j];
                p1Sum += val;
                p1Counts[val]++;
                
                // 更新P2计数，为0时删除
                p2Counts[val]--;
                if (p2Counts[val] == 0) {
                    p2Counts.erase(val);
                }
            }

            long long p2Sum = totalSum - p1Sum;

            // 情况1：和直接相等
            if (p1Sum == p2Sum) {
                return true;
            }

            // 情况2：从 P1 移除一个元素使两边相等
            long long target1 = p1Sum - p2Sum;
            if (target1 > 0 && target1 <= INT_MAX) {
                int t1 = (int)target1;
                int h1 = i + 1;
                int w1 = n;

                // 连通性判断
                if (h1 > 1 && w1 > 1) {
                    if (p1Counts.count(t1)) return true;
                } else if (h1 == 1 && w1 == 1) {
                    if (mat[0][0] == t1) return true;
                } else if (h1 == 1) { // 单行，检查左右端点
                    if (mat[0][0] == t1 || mat[0][w1 - 1] == t1) return true;
                } else if (w1 == 1) { // 单列，检查上下端点
                    if (mat[0][0] == t1 || mat[i][0] == t1) return true;
                }
            }

            // 情况3：从 P2 移除一个元素使两边相等
            long long target2 = p2Sum - p1Sum;
            if (target2 > 0 && target2 <= INT_MAX) {
                int t2 = (int)target2;
                int h2 = m - i - 1;
                int w2 = n;

                // 连通性判断
                if (h2 > 1 && w2 > 1) {
                    if (p2Counts.count(t2)) return true;
                } else if (h2 == 1 && w2 == 1) {
                    if (mat[i + 1][0] == t2) return true;
                } else if (h2 == 1) { // 单行
                    if (mat[i + 1][0] == t2 || mat[i + 1][w2 - 1] == t2) return true;
                } else if (w2 == 1) { // 单列
                    if (mat[i + 1][0] == t2 || mat[m - 1][0] == t2) return true;
                }
            }
        }
        return false;
    }
};