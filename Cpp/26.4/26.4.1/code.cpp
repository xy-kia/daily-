 class Solution {
public:
    string generateString(string str1, string str2) {
        int m = str1.size(),n = str2.size();
        string ans(m + n - 1,'#');
        vector <bool> tough(m + n - 1);
        for (int i = 0;i < m;i ++) {
            if (str1[i] == 'T') {
                for (int j = i;j < i + n;j ++) {
                    tough[j] = true;
                    if (ans[j] == '#')
                        ans[j] = str2[j - i];
                    else if (ans[j] != str2[j - i]) {
                        return "";
                    }
                }
            }
        }
        for (int i = 0;i < m + n - 1;i ++) {
            if (ans[i] == '#')
                ans[i] = 'a';
        }
        for (int i = 0;i < m;i ++) {
            if (str1[i] == 'T')
                continue;
            bool same = true;
            int pos = i;
            for (int j = i;j < i + n;j ++) {
                if (!tough[j])
                    pos = j;
                if (ans[j] != str2[j - i]) {
                    same = false;
                    break;
                }
            }
            if (!same)
                continue;
            if (tough[pos])
                return "";
            ans[pos] ++;
        }
        return ans;
    }
};