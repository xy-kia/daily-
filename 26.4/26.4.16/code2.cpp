class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;

        // 遍历一遍，找到所有 target，计算最短距离
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                // 顺时针距离 + 逆时针距离，取最小
                int dist = min(abs(i - startIndex), n - abs(i - startIndex));
                if (dist < minDist) {
                    minDist = dist;
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};