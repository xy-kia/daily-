class Solution {

public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
       int n = nums.size();
        vector<int>f(n, INT_MAX);
        unordered_map<int,int>first;
        unordered_map<int,int>pre;
        for(int i = 0; i < n; i++){
            if(pre[nums[i]] != 0){
                f[pre[nums[i]] - 1] = min(f[pre[nums[i]] - 1], i - pre[nums[i]] + 1);
                f[i] = min(f[i], i - pre[nums[i]] + 1);
            }
            pre[nums[i]] = i + 1;
            if(first[nums[i]] != 0){
                f[first[nums[i]] - 1] = min(f[first[nums[i]] - 1], n - i + first[nums[i]] - 1);
                f[i] = min(f[i], n - i + first[nums[i]] - 1);
            }else{
                first[nums[i]] = i + 1;
            }
        }
        vector<int>ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            ans[i] = f[queries[i]] != INT_MAX? f[queries[i]] : -1;
        }
        return ans;
    }
};