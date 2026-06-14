class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        int n = words.size();
        for(int i = 0; i < n; i++){
            string x = words[i];
            int total = 0;
            for(auto c:x){
                int temp = c - 'a';
                total = (total + weights[temp]) % 26;
            }
            char y = 'z' - total;
            ans += y;
        }
        return ans;
    }
};