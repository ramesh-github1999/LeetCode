class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 1st occurance of target
        int res=-1,l=0,r=nums.size()-1;
        vector<int>v;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res=mid;
                r=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
         }
        v.push_back(res);
        
        // last occurance of target
        res=-1;
        l=0,r=nums.size()-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res=mid;
                l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
         }
        v.push_back(res);
        return v;
        
    }
};
