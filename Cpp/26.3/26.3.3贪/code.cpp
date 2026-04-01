class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zero;
        int ans = 0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0){
                    count+=1;
                }else{
                    break;
                }
            }
            zero.push_back(count);
        }
        for(int i=0;i<n;i++){
            int target=n-1-i;
            int j=i;
            while(j<n&&zero[j]<target){
                j+=1;
            }
            if(j==n){
                return -1;
            }
            ans+=(j-i);
            int val=zero[j];
            zero.erase(zero.begin() + j);
            zero.insert(zero.begin() + i, val);
        }
        return ans;
    }
};