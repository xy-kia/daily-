class Solution {
public:
    bool rotateString(string s, string goal) {
        vector<int>index;
        int n = s.size();
        if(n != goal.size()){
            return false;
        }
        for(int i = 0;i<n;i++){
            if(s[i]==goal[0]){
                index.push_back(i);
            }
        }
        if(index.size()==0){
            return false;
        }
        string dou = s+s;
        for(int i=0;i<index.size();i++){
            int offset = index[i];
            int j = 0;
            while(j<n){
                if(dou[j+offset]!=goal[j]){
                    break;
                }
                j++;
            }
            if(j == n){
                return true;
            }
        }
        return false;
    }
};