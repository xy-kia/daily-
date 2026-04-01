class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int temp =0 ;
        for(int i=x;i<((2*x+k)/2);i++){
            for(int j=y;j<y+k;j++){
                temp=grid[i][j];
                grid[i][j]=grid[x+k-1-i+x][j];
                grid[x+k-1-i+x][j]=temp;
            }
        }
        return grid;
    }
};