class Solution {
    public int findMinArrowShots(int[][] nums) {
        Arrays.sort(nums,(a,b)->Integer.compare(a[0],b[0]));
         int cnt=1;
        int back=nums[0][1];
        for(int i=1;i<nums.length;i++){
            if(back>=nums[i][0]) {
                back=Math.min(nums[i][1],back);
            }
            else {
                cnt++;
                back=nums[i][1];
            }
        }
        return cnt;
    }
}
