class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long y=0;
        int o=x;
        while(x){
            int temp=x%10;
            x/=10;
            y=y*10+temp;
        }
        if(o==y){
            return true;
        }
        return false;
    }
};