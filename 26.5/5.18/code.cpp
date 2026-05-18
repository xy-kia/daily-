class Solution {
public:
    bool dfs(vector<int>&arr, int p, vector<bool>&visited){
        if(p >= arr.size() || p < 0){
            return false;
        }
        if(arr[p] == 0) return true;
        if(visited[p]) return false;
        visited[p] = true;
        return dfs(arr,p + arr[p],visited) || dfs(arr, p - arr[p], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>visited(n,false);
        return dfs(arr, start, visited);
    }
};