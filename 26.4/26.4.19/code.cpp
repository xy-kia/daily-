class Solution {
public:
    int mirrorDistance(int n) {
        int rn=0;
        int o=n;
        while(n){
            int temp = n%10;
            rn = rn*10+temp;
            n/=10;
        }
        int ans = abs(o-rn);
        return ans;
    }
};