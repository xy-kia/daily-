class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int temp = 0;
            while(x){
               
                temp += (x % 10);
                x /= 10;

            }
            ans = min(ans, temp);
        }
        return ans;
    }
};