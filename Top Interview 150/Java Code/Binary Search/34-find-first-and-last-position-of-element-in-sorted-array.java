class Solution {
    public int[] searchRange(int[] nums, int target) {
        int []v=new int[2];
        // 1st occurance of target
        int n=nums.length;
        int res=-1;
        int l=0;
        int r=n-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res=mid;
                r=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
         }
         // last occurance of target
        v[0]=res;
        res=-1;
        l=0;
        r=n-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res=mid;
                l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
         }
        v[1]=res;
        return v;
        
    }
}
