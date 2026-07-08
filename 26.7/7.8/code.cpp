class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int sum = 0;
        string s = to_string(n);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0'){
                continue;
            }
            char c = s[i];
            int x = c - '0';
            ans = ans * 10 + x;
            sum += x;
        }
        ans *= sum;
        return ans;
    }
}; 