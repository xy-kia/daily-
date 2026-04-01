class Solution {
public:
    bool checkOnesSegment(string s) {
        int cou1=0;
        char last=s[0];
        for(int i=1;i<s.size();i++){
            if(last=='1' && s[i]=='0'){
                cou1++;
            }
            last=s[i];
            if(cou1>1){
                return false;
            }
        }
        if(last=='1'){
            cou1++;
        }
        if(cou1>1){
            return false;
        }
        return true;
    }
};