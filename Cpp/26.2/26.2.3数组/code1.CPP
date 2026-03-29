
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if (numRows == 1) {
            return s;
        }
        vector<vector<char>>dp(numRows,vector<char>(n,'?'));
        int lie=1;
        int h=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(lie){
                dp[h][l]=s[i];
                h++;
                if(h==numRows){
                    lie=0;
                    h-=2;
                    l++;
                }
            }else{
                    dp[h][l]=s[i];
                    h--;
                    l++;
                    if(h<0){
                        lie=1;
                        h=1;
                        l--;
                    }
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!='?'){
                    ans=ans+dp[i][j];
                }
            }
        }
        return ans;
    }
};