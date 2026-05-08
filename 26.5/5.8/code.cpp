class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        int preM[n];
        int curM = INT_MIN;
        for(int i = 0;i<n;i++){
            curM = max(curM,nums[i]);
            preM[i] = curM;
        }
        int sufm[n];
        int curm = INT_MAX;
        for(int i = n-1;i>=0;i--){
            curm = min(curm,nums[i]);
            sufm[i] = curm;
        }
        vector<int>ans(n);
        int start = 0;
        for(int i = 0;i<n;i++){
            if(i == n-1 || preM[i]<=sufm[i+1]){
                int blockMax = preM[i];
    
                for(int j = start; j<=i ;j++){
                ans[j] = blockMax;
                }
                start = i+1;
            }
        }
        return ans;
    }
};