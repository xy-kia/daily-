class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        int DIRS[4][2] = {{0 , 1}, {0, -1}, {1, 0}, {-1 , 0}};
        vector<vector<int>> dis(m, vector(n, INT_MAX));
        dis[0][0] = grid[0][0];
        deque<pair<int,int>> q;
        q.emplace_front(0, 0);
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop_front();
            for(auto& [dx, dy] : DIRS) {
                int x = i + dx;
                int y = j + dy;
                if(0 <= x && x < m && 0 <= y && y < n) {
                    int cost = grid[x][y];
                    if(dis[i][j] + cost < dis[x][y]){
                        dis[x][y] = dis[i][j] + cost;
                        cost == 0 ? q.emplace_front(x, y) : q.emplace_back(x, y);
                    }
                }
            }
        }
        return dis[m - 1][n - 1] < health;
    }
};