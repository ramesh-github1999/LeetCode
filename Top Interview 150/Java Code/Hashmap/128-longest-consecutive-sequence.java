//Time :O(n)
//Space:O(n)
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0) return 0;
        Set<Integer>s=new TreeSet<>();
        for(int i=0;i<nums.length;i++) s.add(nums[i]);
        int best=1,count=1;
        for(int it:s){
            int k=it+1;
            if(s.contains(k)){
                count++;
                best=Math.max(best,count);
            }
            else count=1;
        }
        return best;
    }
}
