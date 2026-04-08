class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        vector<char>temp=letters;
        sort(letters.begin(),letters.end());
        int l=letters.size();
        for(int i=0;i<l;i++){
            if(letters[i]>target){
                ans=letters[i];
                break;
            }
        }
        return ans;
    }
};