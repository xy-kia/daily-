class Solution {
public:
    int countBinarySubstrings(string s) {
        char now=s[0];
        int lc=0;
        int nc=1;
        int ans=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==now){
                nc++;
            }else{
                int x=min(lc,nc);
                ans+=x;
                lc=nc;
                nc=1;
                now=s[i];
            }
        }
        int x=min(lc,nc);
        ans+=x;
        return ans;
    }
};