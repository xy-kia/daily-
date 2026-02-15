class Solution {
public:
    using ll = long long;
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>tower(101,vector<double>(101,0.0));
        tower[0][0] = max(0.0,poured-1.0); 
        if(query_glass==0&&query_row==0){
            return min(poured+0.0,1.0);
        }
        for(int i = 1;i<=query_row;i++){
            for(int j = 0;j<=i;j++){
                if(j){
                    tower[i][j]+=tower[i-1][j-1] /2 ;
                }
                tower[i][j] += tower[i-1][j] /2 ;
            }
            if(i==query_row) return min(1.0,tower[i][query_glass]);
            for(int j=0;j<=i;j++){
                tower[i][j]=max(0.0,tower[i][j]-1.0);
            }
        }
        return tower[query_row][query_glass];
    }
};