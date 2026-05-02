/**
 * @param {number[]} nums
 * @return {number}
 */
var maxRotateFunction = function(nums) {
    const n = nums.length;
    let f = 0;
    let sum = 0;
    for(let i = 0;i<n;i++){
        f += i*nums[i];
        sum += nums[i];
    }
    let ans = f;
    for(let i = n-1;i>0;i--){
        f += sum - n * nums[i];
        ans = Math.max(ans,f);
    }
    return ans;
};