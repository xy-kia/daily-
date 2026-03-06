class Solution {
public:
    int minOperations(string s) {
        char target1='0';
        char target2='1';
        int step1=0;
        int step2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==target1){
                step2++;
            }else{
                step1++;
            }
            char temp=target1;
            target1=target2;
            target2=temp;
        }
        int ans = min(step1,step2);
        return ans;
    }
};