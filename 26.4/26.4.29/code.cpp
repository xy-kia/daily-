class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int t = grid[0][0]%x;
        vector<int> temp;
        for(int i = 0 ;i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]%x != t){
                    return -1;
                }
                temp.push_back(grid[i][j]);
            }
        }
        int ans = 0;
        int l = temp.size();
        sort(temp.begin(), temp.end());
        int target = temp[l/2];
        for(int i = 0; i<l;i++){
            if(i<= l/2){
                ans += (target-temp[i])/x;
            }else{
                ans += (temp[i]-target)/x;
            }
        }
        return ans;

    }
};