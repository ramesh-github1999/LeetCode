class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        //Find the maximum subarray sum using Kadane's algorithm
        int n = nums.length;
        int curr_sum = nums[0], max_sum = nums[0];
        for (int i = 1; i < n; i++) {
            curr_sum = Math.max(curr_sum + nums[i], nums[i]);
            max_sum = Math.max(curr_sum, max_sum);
        }
        
        //Find the minimum subarray sum
        int curr_mini = nums[0], min_sum = nums[0];
        for (int i = 1; i < n; i++) {
            curr_mini = Math.min(curr_mini + nums[i], nums[i]);
            min_sum = Math.min(min_sum, curr_mini);
        }
        //Our ans will be the maximum of maximum subarray sum and sum-minimum subarray sum. 
        int sum = nums[0];
        for (int i = 1; i < n; i++) sum += nums[i];
        return sum == min_sum ? max_sum : Math.max(max_sum, sum - min_sum);
    }
}



// The above code can be written in just one for loop like : 
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int curr_sum = nums[0], curr_min = nums[0], sum = nums[0], max_sum = nums[0], min_sum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            curr_sum = Math.max(curr_sum + nums[i], nums[i]);
            max_sum = Math.max(curr_sum, max_sum);
            curr_min = Math.min(curr_min + nums[i], nums[i]);
            min_sum = Math.min(min_sum, curr_min);
            sum += nums[i];
        }
        return sum == min_sum ? max_sum : Math.max(max_sum, sum - min_sum);
    }
}
