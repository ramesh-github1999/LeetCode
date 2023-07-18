class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==1) return nums[0];
        int inc=nums[0],exe=0;
        for(int i=1;i<n;i++){
            int ninc=exe+nums[i];
            int nexe=Math.max(inc,exe);
            inc=ninc;
            exe=nexe;
        }
        return Math.max(exe,inc);
    }
}
