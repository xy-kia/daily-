class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        ranges::sort(intervals, {}, [](auto& a) { return pair(a[0], -a[1]); });

        int ans = 0;
        int maxr = 0;
        for(auto& p : intervals) {
            if(p[1] > maxr) {
                maxr = p[1];
                ans++;
            }
        }
        return ans;
    }
};