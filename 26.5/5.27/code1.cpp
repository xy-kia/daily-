class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<vector<int>> speacial(26,vector<int>(2,0));
        unordered_set<char> valid;
        for(int i = 0; i < n; i++){
            char x = word[i];
            int p;
            if(x <= 'Z' && x >= 'A'){
                p = x - 'A';
                speacial[p][0] = 1;
            }else{
                p = x - 'a';
                speacial[p][1] = 1;
            }
            if(speacial[p][0] == 1 && speacial[p][1] == 1){
                valid.insert(p);
            }
        }
        int ans = valid.size();
        return ans;
    }
};