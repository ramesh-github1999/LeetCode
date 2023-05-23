// Time:O(n)
// Space: O(1)
class Solution {
    public boolean canJump(int[] nums) {
         int n=nums.length;
        int current=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=current)
                current=i;
        }
        return current==0;
    }
}
