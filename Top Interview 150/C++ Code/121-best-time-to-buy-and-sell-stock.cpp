class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=max(ans,nums[i]-mini);
            mini=min(nums[i],mini);
            
        }
        return ans;
    }
};
