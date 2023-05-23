// Time: O(n)
// Space: O(1)
class Solution {
    public int jump(int[] nums) {
        int n=nums.length;
        if(n<=1) return 0;
        int curr_end=0,curr_max=0,count=0;
        for(int i=0;i<n;i++){
            curr_max=Math.max(curr_max,i+nums[i]);
            if(i==curr_end){
                count++;
                curr_end=curr_max;
            }
            if(curr_end>=n-1) return count;
        }
        return count;
    }
}
