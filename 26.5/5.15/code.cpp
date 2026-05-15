class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int>cou(n,0);
        int m = n-1;
        for(int i = 0; i < n;i++){
            int x = nums[i];
           
            if(x == m){
                if(++cou[x] > 2){
                    return false;
                }
            }else if(x < m){
                if(++cou[x] > 1){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};