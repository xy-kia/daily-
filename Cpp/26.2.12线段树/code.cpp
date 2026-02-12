class SegmentTree {
private:
    int n;          // 原数组长度
    vector<int> treeMin;  // 维护区间最小值
    vector<int> treeMax;  // 维护区间最大值
    vector<int> lazy;     // 懒惰标记（区间加法）

    // 向下传递懒惰标记
    void pushDown(int node) {
        if (lazy[node] != 0) {
            int addVal = lazy[node];
            int left = node * 2;
            int right = node * 2 + 1;

            // 检查子节点是否在数组范围内（避免越界）
            if (left < treeMin.size()) {
                lazy[left] += addVal;
                treeMin[left] += addVal;
                treeMax[left] += addVal;
            }
            if (right < treeMin.size()) {
                lazy[right] += addVal;
                treeMin[right] += addVal;
                treeMax[right] += addVal;
            }

            // 清除当前节点标记
            lazy[node] = 0;
        }
    }

    // 向上更新当前节点的最小/最大值
    void pushUp(int node) {
        int left = node * 2;
        int right = node * 2 + 1;
        if (left < treeMin.size() && right < treeMin.size()) {
            treeMin[node] = min(treeMin[left], treeMin[right]);
            treeMax[node] = max(treeMax[left], treeMax[right]);
        } else if (left < treeMin.size()) {
            treeMin[node] = treeMin[left];
            treeMax[node] = treeMax[left];
        } else if (right < treeMin.size()) {
            treeMin[node] = treeMin[right];
            treeMax[node] = treeMax[right];
        }
    }

public:
    // 构造函数：线段树空间直接用 4*n（最稳妥的方式，避免计算错误）
    SegmentTree(int size) {
        this->n = size;
        // 4*n 是线段树的经典空间分配方式，完全覆盖所有可能的节点
        int treeSize = 4 * n;
        treeMin.resize(treeSize, 0);
        treeMax.resize(treeSize, 0);
        lazy.resize(treeSize, 0);
    }

    // 区间更新：[l, r] 范围内所有值加 val（node从1开始，start/end是当前节点覆盖的区间）
    void update(int node, int start, int end, int l, int r, int val) {
        // 区间无交集，直接返回
        if (l > end || r < start) {
            return;
        }

        // 当前区间完全包含在更新范围里
        if (l <= start && end <= r) {
            treeMin[node] += val;
            treeMax[node] += val;
            lazy[node] += val;
            return;
        }

        // 下放标记，递归更新子节点
        pushDown(node);
        int mid = start + (end - start) / 2;  // 避免 (start+end)/2 溢出
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);

        // 子节点更新后，更新当前节点
        pushUp(node);
    }

    // 查找 [l, r] 范围内最左边值为0的位置，返回-1表示未找到
    int findFirstZero(int node, int start, int end, int l, int r) {
        // 区间无0的可能，直接返回
        if (treeMin[node] > 0 || treeMax[node] < 0) {
            return -1;
        }

        // 区间越界
        if (l > end || r < start) {
            return -1;
        }

        // 叶子节点：检查是否为0
        if (start == end) {
            return (treeMin[node] == 0) ? start : -1;
        }

        // 下放标记
        pushDown(node);
        int mid = start + (end - start) / 2;

        // 优先查左子树（找最左边的0）
        int res = findFirstZero(node * 2, start, mid, l, r);
        if (res != -1) {
            return res;
        }

        // 左子树没找到，查右子树
        return findFirstZero(node * 2 + 1, mid + 1, end, l, r);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // 记录每个数字上一次出现的位置
        unordered_map<int, int> lastPos;
        vector<int> prevOccur(n, -1);

        for (int i = 0; i < n; ++i) {
            if (lastPos.find(nums[i]) != lastPos.end()) {
                prevOccur[i] = lastPos[nums[i]];
            }
            lastPos[nums[i]] = i;
        }

        // 初始化线段树
        SegmentTree st(n);
        int ans = 0;

        // 移动右端点 R，枚举所有可能的子数组结尾
        for (int R = 0; R < n; ++R) {
            int val = nums[R];
            // 偶数+1，奇数-1（平衡差）
            int change = (val % 2 == 0) ? 1 : -1;

            // 仅更新 [prevOccur[R]+1, R] 区间（该元素对这些起始点是"新"的）
            int updateL = prevOccur[R] + 1;
            int updateR = R;

            // 线段树区间更新（根节点是1，覆盖区间[0, n-1]）
            st.update(1, 0, n - 1, updateL, updateR, change);

            // 查找 [0, R] 范围内最左边的0（平衡差为0的起始点）
            int targetL = st.findFirstZero(1, 0, n - 1, 0, R);

            if (targetL != -1) {
                // 更新最长平衡子数组长度
                ans = max(ans, R - targetL + 1);
            }
        }

        return ans;
    }
};