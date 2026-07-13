class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>last(1,"");
        for(int i=0;i<n;i++){
            int x=digits[i]-'0';
            char f='a'+(x-2)*3;
            if(x>7){
                f++;
            }
            vector<string>now1=last;
            vector<string>now2=last;
            vector<string>now3=last;
            for(int j=0;j<last.size();j++){
                now1[j]=now1[j]+f;
            }
            f++;
            for(int j=0;j<last.size();j++){
                now2[j]=now2[j]+f;
            }
            f++;
            for(int j=0;j<last.size();j++){
                now3[j]=now3[j]+f;
            }
            vector<string>now4=last;
            if(x==7||x==9){
                f++;
                for(int j=0;j<last.size();j++){
                now4[j]=now4[j]+f;
                }
            }
            vector<string>now;
            for(int j=0;j<last.size();j++){
                now.push_back(now1[j]);
                now.push_back(now2[j]);
                now.push_back(now3[j]);
                if(x==7||x==9){
                    now.push_back(now4[j]);
                }
            }
            last=now;
        }
        return last;
    }
};