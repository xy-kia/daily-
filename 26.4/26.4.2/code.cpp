class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         int n = positions.size();
        vector<int> idx(n);
        //// 索引数组：保存机器人原始下标，用于按位置排序
        vector<int> res(n, -1);
        //res[i] 存储第 i 个机器人最终血量，-1 表示已毁灭
        for(int i = 0; i < n; i ++) idx[i] = i;
        //初始化
        ranges::sort(idx, [&](auto& i, auto& j){
            return positions[i] < positions[j];
        });
        //按位置排序
        deque<array<int, 2>> q;
        //存储向右走的机器人
        for(auto& i : idx) {
            //遍历机器人
            int pos = i; //原始下标
            int health = healths[i];
            char dir = directions[i];
            if(dir == 'R') q.push_back({pos, health});
            //向右走暂时不碰撞，加入队列
            else {
                //左走，与左边向右的碰撞
                while(q.size()) {
                    auto [tp_pos, tp_health] = q.back();
                    //取出最后一个
                    if(tp_health < health) {//比左走小，死亡
                        q.pop_back();
                        health --;
                    }
                    else if(tp_health == health) {//相等，都去世
                        health = -1;
                        q.pop_back();
                        break;
                    }
                    else {//大于，肘击成功
                        health = -1;
                        q.back()[1] --;
                        break;
                    }
                }
                if(health != -1) res[i] = health;//左走最终成活，记录血量
            }
        }
        while(q.size()) {//剩余右走存货，记录血量
            auto [pos, health] = q.front();
            q.pop_front();
            res[pos] = health;
        }
        vector<int> ans;//去除-1血量的
        for(auto& x : res) if(x != -1) ans.push_back(x);
        return ans;
    }
};