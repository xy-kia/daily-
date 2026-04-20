class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int i = nums1.size() - 1, j = nums2.size() - 1; i >= 0 && j >= 0; --j)
            while (i >= 0 && nums1[i] <= nums2[j])
                res = max(res, j - i--);
        return res;
    }
};