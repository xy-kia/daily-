class Solution {
public:
    int concatenatedBinary(int n) {
        int yu = 1e9+7;
        using ll = long long int;
        ll te=1;
        ll ans=0;
        for(int i=n;i>0;i--){
            int now=i;
            while(now){
                if(now&1){
                    ans=(ans+te)%yu;
                }
                now>>=1;
                te=te*2%yu;
            }
        }
        return ans;
    }
};