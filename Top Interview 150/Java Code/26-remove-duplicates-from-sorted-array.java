// Time: O(n)
// Space: O(1)

class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int next=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[next-1]){
                nums[next]=nums[i];
                next++;
            }
        }
        return next;
    }
}
