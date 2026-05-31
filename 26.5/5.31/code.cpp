class Solution {
public:
    // 线段树数组，存储区间最大空隙
    vector<int> seg;

    // 线段树更新函数
    // idx: 要更新的位置  val: 新值  p: 当前节点编号  l/r: 当前节点管辖区间 [l, r]
    void update(int idx, int val, int p, int l, int r) {
        // 递归到叶子节点，直接赋值
        if (l == r) {
            seg[p] = val;
            return;
        }
        // 二分区间
        int mid = (l + r) >> 1;
        // 要更新的位置在左子树
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else { // 在右子树
            update(idx, val, p << 1 | 1, mid + 1, r);
        }
        // 回溯更新父节点：左右孩子最大值
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    // 线段树查询区间 [L, R] 的最大值
    int query(int L, int R, int p, int l, int r) {
        // 当前区间完全在查询区间内，直接返回
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        // 左子树有重叠，查询左子树
        if (L <= mid) {
            res = max(res, query(L, R, p << 1, l, mid));
        }
        // 右子树有重叠，查询右子树
        if (R > mid) {
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // x 最大取值 50000
        int mx = 50000;
        // 线段树开 4 倍空间防止越界
        seg.resize(mx << 2);
        // 有序集合存储障碍物，初始 0 和 mx 两个边界
        set<int> st = {0, mx};
        // 初始化：位置 mx 的空隙是 mx-0 = mx
        update(mx, mx, 1, 0, mx);
        // 存储答案
        vector<bool> ans;

        // 遍历每一个查询
        for (auto& q : queries) {
            if (q[0] == 1) {
                // 操作1：在 x 处添加障碍物
                int x = q[1];
                // 找到第一个比 x 大的障碍物 r
                auto it = st.upper_bound(x);
                int r = *it;
                // 前一个障碍物 l
                int l = *prev(it);

                // 更新：x 到左边 l 的空隙
                update(x, x - l, 1, 0, mx);
                // 更新：r 到左边 x 的空隙（原来 r-l 被拆成两段）
                update(r, r - x, 1, 0, mx);
                // 把 x 插入障碍物集合
                st.insert(x);
            } else {
                // 操作2：查询在 <=x 处能否放下长度 sz 的物品
                int x = q[1];
                int sz = q[2];
                // 找到 <=x 的最后一个障碍物 pre
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;

                // 查询 [0, pre] 区间内最大空隙
                int max_space = query(0, pre, 1, 0, mx);
                // 再和 pre 到 x 的空隙比较，取最大
                max_space = max(max_space, x - pre);
                // 能放下就是 true
                ans.push_back(max_space >= sz);
            }
        }
        return ans;
    }
};