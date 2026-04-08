class Solution {
public:
    int longestBalanced(string s) {
       int n = s.size();
        int ans = 0;
        
        // 包含 3 种字符的情况
        // 状态：用字符串拼接 "(a-b),(b-c)" 作为键，替代 Java 的 String 键
        unordered_map<string, int> seen;
        seen["0,0"] = -1;
        int a = 0, b = 0, c = 0;
        
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == 'a') a++;
            else if (ch == 'b') b++;
            else c++;
            
            // 拼接差值为字符串，和 Java 的 (a-b) + "," + (b-c) 逻辑一致
            stringstream ss;
            ss << (a - b) << "," << (b - c);
            string diff = ss.str();
            
            if (seen.find(diff) != seen.end()) {
                ans = max(ans, i - seen[diff]);
            } else {
                seen[diff] = i;
            }
        }

        // 包含 2 种字符的情况，调用辅助函数并更新最大值
        ans = max(ans, checkTwoChars(s, 'a', 'b', 'c')); // a=b，无c
        ans = max(ans, checkTwoChars(s, 'a', 'c', 'b')); // a=c，无b
        ans = max(ans, checkTwoChars(s, 'b', 'c', 'a')); // b=c，无a

        // 包含 1 种字符的情况（连续相同字符）
        int curLen = 0;
        char lastChar = ' '; // 初始值和 Java 保持一致
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == lastChar) {
                curLen++;
            } else {
                curLen = 1;
                lastChar = ch;
            }
            ans = max(ans, curLen);
        }

        return ans;
    }

private:
    // 辅助函数：寻找只包含 x 和 y 且数量相等的子串，遇到 forbidden 重置状态
    int checkTwoChars(const string& s, char x, char y, char forbidden) {
        int maxLen = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int diff = 0;  
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == forbidden) {
                // 遇到禁止字符，重置哈希表和差值（和 Java 逻辑一致）
                mp.clear();
                mp[0] = i;
                diff = 0;
            } else {
                if (ch == x) {
                    diff++;
                } else if (ch == y) {
                    diff--;
                }
                
                // 更新最大长度
                if (mp.find(diff) != mp.end()) {
                    maxLen = max(maxLen, i - mp[diff]);
                } else {
                    mp[diff] = i;
                }
            }
        }
        return maxLen;
    }
};
