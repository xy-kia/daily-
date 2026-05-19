class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0; // 只有一个元素，0步
        
        // 预处理：每个数值 对应 所有下标
        unordered_map<int, vector<int>> value_indices;
        for (int i = 0; i < n; ++i) {
            value_indices[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int step = 0;
        
        while (!q.empty()) {
            int size = q.size();
            // 遍历当前层所有节点
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                
                // 到达终点，直接返回步数
                if (cur == n - 1) return step;
                
                // 跳跃方式1：cur - 1
                if (cur - 1 >= 0 && !visited[cur - 1]) {
                    visited[cur - 1] = true;
                    q.push(cur - 1);
                }
                // 跳跃方式2：cur + 1
                if (cur + 1 < n && !visited[cur + 1]) {
                    visited[cur + 1] = true;
                    q.push(cur + 1);
                }
                // 跳跃方式3：所有相同值的下标
                for (int next : value_indices[arr[cur]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                // 优化：该数值已处理完，清空避免重复遍历（大幅提速）
                value_indices[arr[cur]].clear();
            }
            step++; // 一层遍历完，步数+1
        }
        return step;
    }
};