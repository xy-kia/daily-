class Solution {
public:
    int minFlips(string s) {
        char target1='0';
        char f1=target1;
        char target2='1';
        char f2=target2;
        int n=s.size();
        char l1,l2;
        if(n%2==0){
            l1=f2;
            l2=f1;
        }else{
            l1=f1;
            l2=f2;
        }
        int step1=0;
        int step2=0;
        int ans;
        for(int i=0;i<n;i++){
            if(s[i]!=target1){
                step1++;
            }else{
                step2++;
            }
            char temp=target1;
            target1=target2;
            target2=temp;
        }
        ans=min(step1,step2);
        for(int i=0;i<n-1;i++){
            int temp=step1;
            step1=step2;
            step2=temp;
            if(s[i]==f2){
                step2--;
                if(s[i]==l1){
                    step2++;
                }else{
                    step1++;
                }
            }else{
                step1--;
                if(s[i]==l1){
                    step2++;
                }else{
                    step1++;
                }
            }
            ans=min(ans,step1);
            ans=min(ans,step2);
        }
        return ans;
    }
};