class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // find the maximum subarray sum using Kadane's algorithm
        int n = nums.size();
        int curr_sum = nums[0], max_sum = nums[0];
        for(int i = 1; i < n; i++){
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(curr_sum, max_sum);
        }
        
        // find the minimum subarray sum
        int curr_mini = nums[0], min_sum = nums[0];
        for(int i = 1; i < n; i++){
            curr_mini = min(curr_mini + nums[i], nums[i]);
            min_sum = min(min_sum, curr_mini);
        }
       // our ans will be maximum of maximum subarray sum and sum-minimum subarray sum. 
        int sum = nums[0];
        for(int i = 1; i < n; i++) sum += nums[i];
        return sum == min_sum ? max_sum : max(sum - min_sum,max_sum);
    }
};


// The above code can be written in just one for loop like : 
class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max = 0, cur_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
        for (int num : nums) {
            cur_max = max(cur_max, 0) + num;
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min, 0) + num;
            min_sum = min(min_sum, cur_min);
            sum += num;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};
