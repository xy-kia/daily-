class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int now = 0;
        for(int i = 0; i < gain.size(); i++){
            now += gain[i];
            ans = max(ans , now);
        }
        return ans;
    }
};