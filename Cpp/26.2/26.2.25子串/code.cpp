class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(n<k){
            return false;
        }
        unordered_set<string>ans;
        for(int i=0;i<n-k+1;i++){
            string sub_str = s.substr(i, k);
            ans.insert(sub_str);
        }
        return ans.size()==(1<<k);
    }
};