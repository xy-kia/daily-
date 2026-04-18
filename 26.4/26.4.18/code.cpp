class Solution {
private:
    int reverse(int n){
        int ans = 0;
        while (n > 0) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> pos;
        int minDist = INT_MAX;

        for (int j = 0; j < nums.size(); ++j) {
            // 检查之前是否有能和当前数组成镜像对的数
            if (pos.find(nums[j]) != pos.end()) {
                minDist = min(minDist, j - pos[nums[j]]);
            }
            // 更新当前数的反转值位置，后面的数可以匹配到更近的位置
            int rev = reverse(nums[j]);
            pos[rev] = j;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};