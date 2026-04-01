class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int e1[26] = {0}, o1[26] = {0};
        int e2[26] = {0}, o2[26] = {0};
        
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                // 偶数下标
                e1[s1[i] - 'a']++;
                e2[s2[i] - 'a']++;
            } else {
                // 奇数下标
                o1[s1[i] - 'a']++;
                o2[s2[i] - 'a']++;
            }
        }
        
        // 比较：偶数位完全一样 + 奇数位完全一样 → 返回 true
        for (int i = 0; i < 26; ++i) {
            if (e1[i] != e2[i] || o1[i] != o2[i])
                return false;
        }
        return true;
    }
};