class Solution {
public:
    char processStr(string s, long long k) {
        long long sz = 0;
        for (char c : s) {
            if (c == '*') {
                sz = max(sz - 1, 0LL);
            } else if (c == '#') {
                sz *= 2;
            } else if (c != '%') {
                sz++;
            }
        }

        if (k >= sz) {
            return '.';
        }

        for (int i = s.size() - 1; ; i--) {
            char c = s[i];
            if (c == '*') {
                sz++;
            } else if (c == '#') {
                sz /= 2;
                if (k >= sz) {
                    k -= sz;
                }
            } else if (c == '%') {
                k = sz - 1 - k;
            } else {
                sz--;
                if (k == sz) {
                    return c;
                }
            }
        }

    }
};