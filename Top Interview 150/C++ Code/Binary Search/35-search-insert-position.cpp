class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};


// Recurrsive solution
class Solution {
    int fun(int [] nums,int l,int r,int t){
        if(l>r) return l;
        int mid=(l+r)/2;
        if(nums[mid]==t) return mid;
        else if(nums[mid]>t) return fun(nums,l,mid-1,t);
        return fun(nums,mid+1,r,t);
    }
    public int searchInsert(int[] nums, int target) {
         int l=0,r=nums.length-1;
       return fun(nums,0,r,target);
    }
}
