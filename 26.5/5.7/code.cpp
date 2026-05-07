class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();    // 原矩阵行数
        int n = boxGrid[0].size(); // 原矩阵列数

        // 第一步：处理每一行，让石头#靠右侧下落，.在左侧，*不动
        for (int i = 0; i < m; ++i) {
            processRow(boxGrid[i]);
        }

        // 第二步：顺时针旋转90度，生成n行m列的结果矩阵
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 旋转核心：原矩阵第j行 倒数第i+1个元素 → 结果矩阵第i行第j列
                res[i][j] = boxGrid[m - 1 - j][i];
            }
        }
        return res;
    }

private:
    // 处理单行，类比移动零算法，#靠右，.靠左，*分隔
    void processRow(vector<char>& row) {
        int len = row.size();
        int right = len - 1; // 石头最终放置的位置（从右往左放）

        // 从右向左遍历，处理每个位置
        for (int i = len - 1; i >= 0; --i) {
            if (row[i] == '*') {
                // 遇到障碍物，重置右边界，障碍物位置不变
                right = i - 1;
            } else if (row[i] == '#') {
                // 遇到石头：移动到右边界，原位置置空
                if (i != right) {
                    row[right] = '#';
                    row[i] = '.';
                }
                right--; // 下一个石头放在左边
            }
            // 空位置. 无需处理
        }
    }
};