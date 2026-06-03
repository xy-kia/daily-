class Solution {
public:
    int minsolve(vector<int>&fstartTime, vector<int>& fduarTime, vector<int>& sstartTime, vector<int> & sduartime){
        int min_finish = INT_MAX;
        for(int i = 0; i < fstartTime.size(); i++){
            min_finish = min(min_finish, fstartTime[i] + fduarTime[i]);
        }
        int ans = INT_MAX;
        for(int i = 0; i <sstartTime.size(); i++){
            ans = min(ans, max(sstartTime[i], min_finish) + sduartime[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_f = minsolve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_f = minsolve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_f, water_f);
    }
};