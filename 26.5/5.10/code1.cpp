class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int l = n;
        int h = m;
        int start = 0;
        int direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(l>0){
            int totall = 2*h + 2*l -4;
            int step = k%totall;
            vector<int>temp;
            int nx = start;
            int ny = start;
            int d = 0;
            while(step){
                if(nx + direction[d][1] <start || nx +direction[d][1] > start+l-1 || ny + direction[d][0] <start || ny +direction[d][0] > start+h-1){
                    d=(d+1)%4;
                    continue;
                }
                nx = nx + direction[d][1];
                ny = ny + direction[d][0];
                step--;
            }
            for(int i = 0;i<totall;i++){
                temp.push_back(grid[ny][nx]);
                if(nx + direction[d][1] <start || nx +direction[d][1] > start+l-1 || ny + direction[d][0] <start || ny +direction[d][0] > start+h-1){
                    d=(d+1)%4;
                }
                nx = nx +direction[d][1];
                ny = ny +direction[d][0];
            }
            d = 0;
            nx = start;
            ny = start;
            for(int i = 0; i<totall;i++){
                grid[ny][nx] = temp[i];
                if(nx + direction[d][1] <start || nx +direction[d][1] > start+l-1 || ny + direction[d][0] <start || ny +direction[d][0] > start+h-1){
                    d=(d+1)%4;
                }
                ny = ny + direction[d][0];
                nx = nx + direction[d][1];
            }
            l -=2;
            h -=2;
            start++;
        }
        return grid;
    }
};