class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p,q;
        int phase=0;
        for(int i=1;i<n;i++){
            if(phase==0){
                if(nums[i]<=nums[i-1]){
                    phase=1;
                    if((i-1)==0){
                        return false;
                    }
                }
            }
            if(phase==1){
                if(nums[i]>=nums[i-1]){
                    phase=2;
                }
            }
            if(phase==2){
                if(nums[i]<=nums[i-1]){
                    return false;
                }
            }
        }
        if(phase!=2){
            return false;
        }
        return true;
    }
};