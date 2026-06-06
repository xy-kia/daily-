class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            ans += countWa(i);
        }
        return ans;
    }

private:
    int countWa(int n){
        if(n < 100) return 0;
        int ret = 0;
        int prev2 = n % 10; n /= 10;
        int prev1 = n % 10; n /= 10;

        while (n > 0) {
            int cur = n % 10;

            if((prev1 >prev2 && prev1 > cur) || (prev1 < prev2 && prev1 < cur)){
                ret++;
            }
            prev2 = prev1;
            prev1 = cur;
            n /= 10;
        }
        return ret;
    }
};