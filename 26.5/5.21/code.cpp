class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>counts(n+1,0);
        vector<int>ans(n,0);
        if(A[0] == B[0]){
            counts[A[0]] = 2;
            ans[0] = 1;
        }else{
            counts[A[0]]++;
            counts[B[0]]++;
        }
        for(int i = 1;i < n;i++){
            ans[i] = ans[i-1];
            if(counts[A[i]] == 1){
                ans[i]++;
            }
            counts[A[i]]++;
            if(counts[B[i]] == 1){
                ans[i]++;
            }
            counts[B[i]]++;
        }
        return ans;
    }
}; 