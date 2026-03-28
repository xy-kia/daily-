class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // 偶数行左移 k，比较原位置和目标位置
                    if (mat[i][j] != mat[i][(j + k) % n]) return false;
                } else {
                    // 奇数行右移 k
                    if (mat[i][j] != mat[i][(j - k + n) % n]) return false;
                }
            }
        }
        return true;
    }
};