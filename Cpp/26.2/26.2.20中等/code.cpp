class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int n=s.size();
        int flag=0;
        int turn=1;
        for(int i=0;i<n;i++){
            if(flag==0){
                if(s[i]!=' '){
                    flag=1;
                    i--;
                }
            }else if(flag==1){
                if(s[i]=='-'){
                    turn=-1;
                    flag=2;
                }else if(s[i]=='+'){
                    flag=2;
                }else{
                    flag=2;
                    i--;
                }
            }else if(flag==2){
                if(s[i]!='0'){
                    flag=3;
                    i--;
                }
            }else if(flag==3){
                if(s[i]>='0'&&s[i]<='9'){
                    ans*=10;
                    ans+=(s[i]-'0');
                    if(ans>INT_MAX){
                        if(turn<0){
                            return INT_MIN;
                        }else{
                            return INT_MAX;
                        }
                    }
                }else{
                    ans*=turn;
                    return ans;
                }
            }
        }
        ans*=turn;
        return ans;
    }
};