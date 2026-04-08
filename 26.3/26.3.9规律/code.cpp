class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0;i<nums.size();i++){
            char x=nums[i][i];
            x= (x=='0'?'1':'0');
            ans=ans+x;
        }
        return ans;
    }
};