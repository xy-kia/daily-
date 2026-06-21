class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        
        restrictions.push_back({1, 0});
        // 检查 n 是否已存在，不存在则加入边界
        bool has_n = false;
        for (auto& r : restrictions) {
            if (r[0] == n) { has_n = true; break; }
        }
        if (!has_n) restrictions.push_back({n, n - 1});
        int m = restrictions.size();
        if(m == 0){
            return n -1 ;
        }
        ranges::sort(restrictions, {}, [](auto& a) { return a[0]; }); // 按照 id 从小大到大排序
        for(int i = 1; i < m; ++i){
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }
        for(int i = m - 2; i >= 0; --i) {
            int dist = restrictions[i + 1][0] -restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        int ans = 0;
        for(int i = 1; i < m; ++i) {
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            ans =max(ans, (h1 + h2 + dist) / 2);
        }

        return ans;
    }
};