#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int i = 0; i < numLayers; i++) {
            int top = i;
            int left = i;
            int bottom = m - 1 - i;
            int right = n - 1 - i;

            vector<int> layer;

            // 左侧边 从上到下
            for (int r = top; r < bottom; r++) {
                layer.push_back(grid[r][left]);
            }
            // 下侧边 从左到右
            for (int c = left; c < right; c++) {
                layer.push_back(grid[bottom][c]);
            }
            // 右侧边 从下到上
            for (int r = bottom; r > top; r--) {
                layer.push_back(grid[r][right]);
            }
            // 上侧边 从右到左
            for (int c = right; c > left; c--) {
                layer.push_back(grid[top][c]);
            }

            int len = layer.size();
            int realK = k % len;
            if (realK == 0) continue;

            int idx = 0;
            // 写回：左侧
            for (int r = top; r < bottom; r++) {
                grid[r][left] = layer[(idx + len - realK) % len];
                idx++;
            }
            // 写回：下侧
            for (int c = left; c < right; c++) {
                grid[bottom][c] = layer[(idx + len - realK) % len];
                idx++;
            }
            // 写回：右侧
            for (int r = bottom; r > top; r--) {
                grid[r][right] = layer[(idx + len - realK) % len];
                idx++;
            }
            // 写回：上侧
            for (int c = right; c > left; c--) {
                grid[top][c] = layer[(idx + len - realK) % len];
                idx++;
            }
        }
        return grid;
    }
};