class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        while(ans < costs.size() && coins >= costs[ans] ){
            coins -= costs[ans];
            ans++;
        }
        return ans;
    }
};