class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        while(1){
            if(i >= m && j >= n){
                break;
            }
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }else if(nums1[i] < nums2[j]){
                if(i + 1 >= m){
                    return -1;
                }else{
                    i++;
                }
            }else{
                if(j + 1 >= n){
                    return -1;
                }else{
                    j++;
                }
            }
        }
        return -1;
    }
};