class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(); 
        unordered_map<char,int>needl;
        int left = 0;
        for(int i = 0; i < t.size(); i++){
            char c = t[i];
            if(needl.find(c) != needl.end()){
                needl[c]++;
            }else{
                needl[c] = 1;
                left++;
            }
        }
        int ansl = INT_MAX;
        string ans = "";
        int l = 0;
        int r = 0;
        while(r < n){
            char c = s[r];
            if(needl.find(c) != needl.end()){
                needl[c]--;
                if(needl[c] == 0){
                    left--;
                }
            }
            while(l<r){
                char c1 = s[l];
                if(needl.find(c1) == needl.end()){
                    l++;
                }else{
                    if(needl[c1] < 0){
                        l++;
                        needl[c1]++;
                    }else{
                        break;
                    }
                }
            }
            if(left == 0){
                if((r - l + 1) < ansl){
                    ans = s.substr(l, (r - l + 1));
                    ansl = (r - l + 1);
                }
            }
            r++;
        }
        return ans;
    }
};