class Solution {
public:
    int findLowestIndex(vector<int>&nums){
        int l=0,r=nums.size()-1;
        if(nums[r]>nums[0]) return 0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid+1]<nums[mid]) return mid+1;
            else if(nums[mid]<nums[mid-1]) return mid;
           else if(nums[mid]>nums[0]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
    
    int binarySearch(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else  l=mid+1;
         }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) {
            if(nums[0]==target) return 0;
            else return -1;
        }
        int k=findLowestIndex(nums); 
        if(nums[k]==target) return k;
        if(k==0) return binarySearch(nums,0,n-1,target);
        if(nums[0]<=target) return binarySearch(nums,0,k-1,target);
        else return binarySearch(nums,k+1,n-1,target);        
    }
};
