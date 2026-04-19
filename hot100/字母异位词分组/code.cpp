class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,int>index;
        int start = 0;
        for(int i=0;i<strs.size();i++){
            string now = strs[i];
            string sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            if(index.find(sorted)!=index.end()){
                int j = index[sorted];
                ans[j].push_back(now);
            }else{
                index[sorted]=start++;
                vector<string>first={now};
                ans.push_back(first);
            }
        }
        return ans;
    }
};