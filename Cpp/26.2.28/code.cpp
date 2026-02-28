class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mindif = INT_MAX;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 1 ;i< n;i++){
            mindif = min(mindif,arr[i]-arr[i-1]);
        }
        vector<vector<int>> ans;
        for(int i = 1 ; i< n;i++){
            if(arr[i]-arr[i-1] == mindif){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};

