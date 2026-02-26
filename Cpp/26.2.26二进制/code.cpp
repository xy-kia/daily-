const int mask= 0x3FFF;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (int& x : arr) x ^= __builtin_popcount((unsigned)x) << 14;
        sort(arr.begin(), arr.end());
        for (int& x : arr) x &= mask;
        return arr;
    }
};