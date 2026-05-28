class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int>cou(26,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            char x = word[i];
            int p;
            if(x >= 'a' && x <= 'z'){
                p = x -'a';
                if(cou[p] == 2){
                    ans--;
                    cou[p] = -1;
                }
                if(cou[p] == -1){
                    continue;
                }
                cou[p] = 1;
            }else{
                p = x -'A';
                if(cou[p] == 2 || cou[p] == -1){
                    continue;
                }
                if(cou[p] == 1){
                    cou[p] = 2;
                    ans++;
                }
                if(cou[p] == 0){
                    cou[p] = -1;
                }
            }
        }
        return ans;
    }
};