class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return (b[1]-b[0]) < (a[1]-a[0]);
        });
        int cur = 0;
        int ans = 0;
        int n = tasks.size();
        for(int i = 0; i< n ;i++){
            int cost= tasks[i][0];
            int minimum = tasks[i][1];

            if(cur < minimum){
                int diff = minimum -cur;
                ans += diff;
                cur += diff;
            }
            cur -= cost;
        }
        return ans;
    }
};