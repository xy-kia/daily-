class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        // 情况1：以最左边的房子为基准，找所有右边颜色不同的房子的最大距离
        int leftColor = colors[0];
        for (int i = 1; i < n; ++i) {
            if (colors[i] != leftColor) {
                maxDist = max(maxDist, i - 0);
            }
        }
        // 情况2：以最右边的房子为基准，找所有左边颜色不同的房子的最大距离
        int rightColor = colors[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (colors[i] != rightColor) {
                maxDist = max(maxDist, (n - 1) - i);
            }
        }
        return maxDist;
    }
};