class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        uint64_t p = 0, q = 0;
        for(int i = 0; i < A.size(); i++){
            p |= 1ULL << A[i];
            q |= 1ULL << B[i];
            A[i] = popcount(p & q);
        }
        return A;
    }
}; 