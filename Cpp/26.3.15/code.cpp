class Solution {
public:
    string getHappyString(int n, int k) {
        int total=3*(1<<(n-1));
        if(total<k){
            return "";
        }
        int x=(1<<(n-1));
        string ans="";
        char last;
        if((k/x)==0 || x==k) {
            ans=ans+'a';
            last='a';
        }else if((k/x)==1 || k==(2*x)){
            ans=ans+'b';
            last='b';
        }else{
            ans=ans+'c';
            last='c';
        }
        while(ans.size()!=n){
            k=(k%x);
            x>>=1;
            if(((k/x)==0 || k==x) && k!=0){
                if(last=='a'){
                    ans=ans+'b';
                    last='b';
                }else if(last=='b'){
                    ans=ans+'a';
                    last='a';
                }else{
                    ans=ans+'a';
                    last='a';
                }
            }else{
                if(last=='a'){
                    ans=ans+'c';
                    last='c';
                }else if(last=='b'){
                    ans=ans+'c';
                    last='c';
                }else{
                    ans=ans+'b';
                    last='b';
                }
            }
        }
        return ans;
    }
};