class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int carry=0;
        int n=s.size();
        for(int i=n-1;i>=1;i--){
            int val=s[i]-'0'+carry;
            if(val==1){
                ans+=2;
                carry=1;
            }else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};