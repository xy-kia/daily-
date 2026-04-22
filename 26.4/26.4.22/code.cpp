class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        // 并查集初始化
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        // 查找 + 路径压缩
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        
        // 合并
        auto unite = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) parent[x] = y;
            else {
                parent[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
            }
        };
        
        // 合并所有可交换下标
        for (auto& e : allowedSwaps) unite(e[0], e[1]);
        
        // 按连通分量分组
        unordered_map<int, vector<int>> group;
        for (int i = 0; i < n; ++i) group[find(i)].push_back(i);
        
        int match = 0;
        for (auto& [root, idx] : group) {
            vector<int> s, t;
            for (int i : idx) {
                s.push_back(source[i]);
                t.push_back(target[i]);
            }
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            int i = 0, j = 0;
            while (i < s.size() && j < t.size()) {
                if (s[i] == t[j]) {
                    match++;
                    i++;
                    j++;
                } else if (s[i] < t[j]) i++;
                else j++;
            }
        }
        
        return n - match;
    }
};