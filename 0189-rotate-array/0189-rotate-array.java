// Time:O(n)
// Space O(n)
class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        List<Integer>v=new ArrayList<>();
        k=k%n;
        for(int i=n-k;i<n;i++) v.add(nums[i]);            
        for(int i=0;i<n-k;i++) v.add(nums[i]);  
        for(int i=0;i<n;i++) nums[i]=v.get(i);
        
    }
}