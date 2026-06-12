class Solution {
public:
    const int mod = 1e9 + 7;
    long long pow(long long x, long n){
        long long res = 1;
        for(; n > 0; n /= 2){
            if(n%2){
                res = res * x % mod;
            }
            x = x * x %mod;
        }
        return res;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> e(n + 1);
        for(vector<int>& edge : edges){
            int x = edge[0];
            int y = edge[1];
            e[x].push_back(y);
            e[y].push_back(x);
        }
        auto dfs =[&](this auto&& dfs, int x, int fa) ->int {
            int d = 0;
            for(int y : e[x]){
                if(y != fa){
                    d = max(d, dfs(y, x) + 1);
                }
            }
            return d;
        };
        int k = dfs(1, 0);
        return pow(2, k - 1);
    }
};