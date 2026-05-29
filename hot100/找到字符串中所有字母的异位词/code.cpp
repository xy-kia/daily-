class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int len = p.size();
        vector<int>ans;
        if(n < len){
            return ans;
        }
        int l = 0;
        int r = len - 1;
        vector<int>t(26,0);
        vector<int>now(26,0);
        for(int i = 0; i < len; i++){
            t[p[i]-'a']++;
            now[s[i] - 'a']++;
        }
        if(now == t){
            ans.push_back(0);
        }
        while(r+1 < n){
            now[s[l++] - 'a']--;
            now[s[++r] - 'a']++;
            if(now == t){
                ans.push_back(l);
            }
        }
        return ans;
    }
};