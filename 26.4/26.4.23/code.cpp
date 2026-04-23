class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res; // 存储结果
        // 第一层for：遍历所有查询单词
        for (string& q : queries) {
            bool ok = false;
            // 第二层for：遍历字典所有单词
            for (string& d : dictionary) {
                int diff = 0;
                // 计算两个单词的字符差异数
                for (int i = 0; i < q.size(); ++i) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }
                // 只要有一个字典单词满足差异≤2
                if (diff <= 2) {
                    ok = true;
                    break;
                }
            }
            // 满足条件就加入结果
            if (ok) {
                res.push_back(q);
            }
        }
        return res;
    }
};