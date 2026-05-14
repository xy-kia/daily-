class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2 + 2 * limit);
        
        for(int i = 0;i < n/2; i++){
            int a = nums[i];
            int b =nums[n-1-i];

            if(a > b){
                int temp =a;
                a = b;
                b = temp;
            }

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            diff[a+1] -=1;
            diff[b + limit + 1] += 1;

            diff[a + b] -=1;
            diff[a + b +1] +=1;
        }
        int ans = n;
        int cur = 0;

        for(int x = 2; x <= 2* limit; x++){
            cur += diff[x];
            if(cur <ans){
                ans =cur;
            }
        }
        return ans;

    }
};