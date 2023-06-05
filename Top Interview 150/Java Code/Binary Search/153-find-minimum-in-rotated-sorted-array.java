class Solution {
    public int findMin(int[] nums) {
        if(nums.length==1) return nums[0];
         int l = 0, r = nums.length - 1;
        if (nums[r] > nums[0]) return nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid + 1 < nums.length && nums[mid + 1] < nums[mid]) return nums[mid + 1];
            else if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];
            else if (nums[mid] > nums[0]) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
}
