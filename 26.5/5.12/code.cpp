class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            // 转成字符串遍历每一位
            for (char c : to_string(num)) {
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};