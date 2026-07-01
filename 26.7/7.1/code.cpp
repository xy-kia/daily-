class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3]{};
        int ans = 0;
        int left = 0;
        for(char c: s){
            cnt[c - 'a']++;
            while(cnt[0]&& cnt[1] && cnt[2]){
                cnt[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};