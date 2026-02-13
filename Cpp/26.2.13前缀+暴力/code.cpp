class Solution {
public:
    int longestBalanced(string s) {
         int n = s.size();
        vector<array<int, 26>> pre(n + 1);
        for(int i = 1; i <= n; i ++) {
            pre[i] = pre[i-1];
            pre[i][s[i-1] - 'a'] ++;
        }

        for(int len = n; len >= 1; len --) {
            for(int i = 0; i <= n - len; i ++) {
                int l = i, r = i + len - 1;
                int x = -1, flag = 1;
                for(int b = 0; b < 26 && flag; b ++) {
                    int y = pre[r+1][b] - pre[l][b];
                    if(y && x == -1) x = y;
                    else if(y && x != y) flag = 0; 
                }
                if(flag) return len;
            }
        }
        return -1;

    }
};