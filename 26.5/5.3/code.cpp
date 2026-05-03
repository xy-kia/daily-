class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            string s = to_string(i);
            bool isValid = true;
            bool hasDiff = false;

            for (char c : s) {
                // 出现 3、4、7 → 直接无效
                if (c == '3' || c == '4' || c == '7') {
                    isValid = false;
                    break;
                }
                // 出现 2、5、6、9 → 旋转后数字会变
                if (c == '2' || c == '5' || c == '6' || c == '9') {
                    hasDiff = true;
                }
            }

            // 有效 且 旋转后不一样 → 计数+1
            if (isValid && hasDiff) {
                ans++;
            }
        }

        return ans;
    }
};