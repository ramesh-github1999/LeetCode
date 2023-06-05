// Linear search 
// Time=O(n)

class Solution {
    public int findPeakElement(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                return i;
        }
        return n-1;
    }
}


// Binary search solution method 1, Time=O(logn)
class Solution2 {
    public int findPeakElement(int[] nums) {
        int l=0,r=nums.length-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(mid+1<nums.length && nums[mid+1]>nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
}


// Binary Search method 2;
class Solution3{
    public int findPeakElement(int[] nums) {
        int n=nums.length;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        // search in remaing array
        
        int l=1,r=nums.length-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(mid+1<nums.length && nums[mid+1]>nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
}
