class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>cnt(5,0);
        for(int i = 0; i < text.size(); i++){
            char c = text[i];
            if(c == 'b'){
                cnt[0]++;
            }else if(c == 'a'){
                cnt[1]++;
            }else if(c == 'l'){
                cnt[2]++;
            }else if(c == 'o'){
                cnt[3]++;
            }else if(c == 'n'){
                cnt[4]++;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        int ans = *min_element(cnt.begin(), cnt.end());
        return ans;
    }
};