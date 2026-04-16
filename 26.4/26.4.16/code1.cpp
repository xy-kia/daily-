class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<string>doword = words;
        doword.insert(doword.end(),words.begin(),words.end());
        int n = doword.size();
        int i = startIndex+words.size();
        int j = startIndex;
        while(i>=0 || j<n){
            if(i-1 == -1 && j+1 == n){
                break;
            }
            if(doword[i]==target){
                return startIndex-i+words.size();
            }
            if(doword[j]==target){
                return j-startIndex;
            }
            if(i-1 >=0){
                i--;
            }
            if(j+1 < n){
                j++;
            }
        }
        return -1;
    }
};