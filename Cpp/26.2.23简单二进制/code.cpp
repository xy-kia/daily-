class Solution {
public:
    int binaryGap(int n) {
        int dst=0;
        int ans=0;
        int flag=0;
        while(n){
            int temp=n&1;
            n>>=1;
            if(temp==1){
                if(flag==0){
                    flag=1;
                    dst=1;
                }else{
                    ans=max(ans,dst);
                    dst=1;
                }
            }else if(flag==1){
                dst++;
            }
        }
        return ans;
    }
};