class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        vector<int>row;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                }
                if(count>1){
                    break;
                }
            }
            if(count==1){
                row.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            int location=0;
            for(int j=0;j<m;j++){
                if(mat[j][i]==1){
                    count++;
                    location=j;
                }
                if(count>1){
                    break;
                }
            }
            if(count==1){
                auto it=find(row.begin(),row.end(),location);
                if(it!=row.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};