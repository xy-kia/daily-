class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='C'){
                if(s[i+1]== 'M'){
                    ans+=900;
                    i++;
                    continue;
                }else if(s[i+1]=='D'){
                    ans+=400;
                    i++;
                    continue;
                }else{
                    ans+=100;
                }
            }
            if(s[i]=='M'){
                ans+=1000;
                continue;
            }
            if(s[i]=='D'){
                ans+=500;
                continue;
            }
            if(s[i]=='X'){
                if(s[i+1]=='C'){
                    ans+=90;
                    i++;
                    continue;
                }else if(s[i+1]=='L'){
                    ans+=40;
                    i++;
                    continue;
                }else{
                    ans+=10;
                }
            }
            if(s[i]=='L'){
                ans+=50;
            }
            if(s[i]=='I'){
                if(s[i+1]=='X'){
                    ans+=9;
                    return ans;
                }else if(s[i+1]=='V'){
                    ans+=4;
                    return ans;
                }else{
                    ans++;
                }
            }
            if(s[i]=='V'){
                ans+=5;
            }
        }
        return ans;
    }
};