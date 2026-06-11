class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int max_left = 0;
        int max_right = 0;
        int left = 1;
        int right = (int)height.size() - 2;

        for (int i = 1; i < (int)height.size() - 1; ++i) {
            if (height[left - 1] < height[right + 1]) {
                max_left = max(max_left, height[left - 1]);
                int min_val = max_left;
                if (min_val > height[left]) {
                    sum += min_val - height[left];
                }
                left++;
            } else {
                max_right = max(max_right, height[right + 1]);
                int min_val = max_right;
                if (min_val > height[right]) {
                    sum += min_val - height[right];
                }
                right--;
            }
        }
        return sum;
    }
};