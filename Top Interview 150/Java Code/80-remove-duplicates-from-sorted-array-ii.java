// Time: O(n)
// Space: O(1)
class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        if(n<=2) return n;
        int next=2;
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[next-2]){
                nums[next]=nums[i];
                next++;
            } 
        }
        return next;
    }
}
