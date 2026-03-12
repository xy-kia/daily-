class Solution {
public:
    int bitwiseComplement(int n) {
        int bits=0;
        if(n==0){
            return 1;
        }
        int o=n;
        while(n){
            bits++;
            n>>=1;
        }
        int m=(1<<bits)-1;
        int ans=m-o;
        return ans;
    }
};