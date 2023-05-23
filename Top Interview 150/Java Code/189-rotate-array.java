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

// Time:O(n)
// Space O(1)
class Solution {
   public static void reverse(int []nums,int l,int h){
       while(l<h){
          int temp=nums[l];
           nums[l]=nums[h];
           nums[h]=temp;
           l++;h--;
       }
   }
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
       reverse(nums,0,n-1);
       reverse(nums,0,k-1);
       reverse(nums,k,n-1);     
    }
}
