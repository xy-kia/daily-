class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool group1 = (s1[0] == s2[0] && s1[2] == s2[2]) || 
                      (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // 检查第二组：位置1和3
        bool group2 = (s1[1] == s2[1] && s1[3] == s2[3]) || 
                      (s1[1] == s2[3] && s1[3] == s2[1]);
        
        // 两组都满足才返回true
        return group1 && group2;
    }
};