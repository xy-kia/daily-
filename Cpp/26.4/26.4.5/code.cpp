class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int i=startPos[0];
        int j=startPos[1];
        while(i!=homePos[0]){
            if(i<homePos[0]){
                ans+=rowCosts[i+1];
                i++;
            }else{
                ans+=rowCosts[i-1];
                i--;
            }
        }
        while(j!=homePos[1]){
            if(j<homePos[1]){
                ans+=colCosts[j+1];
                j++;
            }else{
                ans+=colCosts[j-1];
                j--;
            }
        }
        return ans;
    }
};