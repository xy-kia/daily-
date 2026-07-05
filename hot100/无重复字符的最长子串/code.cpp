class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pos;
        int maxLen = 0, left = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            // 字符存在且下标>=左边界，说明在当前窗口重复
            if(pos.count(c) && pos[c] >= left){
                left = pos[c] + 1;
            }
            pos[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};