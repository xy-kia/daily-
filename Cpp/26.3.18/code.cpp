class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            vector<int>cur = matrix[i];
            sort(cur.begin(),cur.end(),greater<int>());
            for(int j=0;j<n;j++){
                if(cur[j]==0){
                    break;
                }
                ans=max(ans,cur[j]*(j+1));
            }
        }
        return ans;
    }
};