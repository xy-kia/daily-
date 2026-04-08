class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target){
            return true;
        }
        int n = mat.size();
        for(int c=0;c<3;c++){
            for(int i = 0;i< n/2 ; i++){
                for(int j = i;j<n-1-i;j++){
                    int tmp = mat [i][j];
                    mat[i][j]=mat[n-j-1][i];
                    mat[n-j-1][i]=mat[n-i-1][n-j-1];
                    mat[n-i-1][n-j-1]=mat[j][n-i-1];
                    mat[j][n-i-1]=tmp;
                }
            }
            if(mat == target){
                return true;
            }
        }
        return false;

    }
};