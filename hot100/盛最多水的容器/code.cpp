class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = (min(height[l], height[r])) * (r - l);
        while(l<r){
            if(height[l] < height[r]){
                l++;
                int h = min(height[l], height[r]);
                int v = h * (r - l);
                if(v > ans){
                    ans = v;
                }
            }else{
                r--;
                int h = min(height[l], height[r]);
                int v = h * (r - l);
                if(v > ans){
                    ans = v;
                }
            }
        }
        return ans;
    }
};