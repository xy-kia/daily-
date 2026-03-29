class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==2){
            return min(height[0],height[1]);
        }
        int l=0;
        int r=n-1;
        int ans=(min(height[l],height[r])*(r-l));
        while(r!=l){
            if(height[l]<height[r]){
                l++;
                int h=min(height[l],height[r]);
                ans=max(ans,h*(r-l));
            }else{
                r--;
                int h=min(height[l],height[r]);
                ans=max(ans,h*(r-l));
            }
        }
        return ans;
    }
};