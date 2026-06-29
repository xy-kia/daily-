class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int next = 1;
        for(int i = 0; i < n;i++){
            arr[i] = min(next,arr[i]);
            next = arr[i] + 1;
        }
        return arr[n-1];
    }
};