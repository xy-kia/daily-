class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 方向：上、右、下、左 (对应heading 0-3)
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0, y = 0;    // 机器人坐标
        int heading = 0;     // 朝向
        int maxDist = 0;     // 最大欧式距离平方

        // 哈希集合存储障碍物坐标（核心优化！）
        unordered_set<long long> obsSet;
        for (auto& obs : obstacles) {
            // 坐标偏移+编码成唯一long long，避免哈希冲突
            long long nx = obs[0] + 30000;
            long long ny = obs[1] + 30000;
            obsSet.insert((nx << 16) | ny);
        }

        for (int cmd : commands) {
            if (cmd == -1) {
                // 右转
                heading = (heading + 1) % 4;
            } else if (cmd == -2) {
                // 左转
                heading = (heading + 3) % 4; // 等价于-1，避免负数
            } else {
                // 一步一步走
                for (int k = 0; k < cmd; k++) {
                    int nx = x + dx[heading];
                    int ny = y + dy[heading];
                    
                    // 编码下一个位置，检查是否是障碍物
                    long long code = ((nx + 30000) << 16) | (ny + 30000);
                    if (obsSet.count(code)) {
                        break; // 遇到障碍物，停止前进
                    }
                    
                    // 更新位置
                    x = nx;
                    y = ny;
                    // 更新最大距离
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};