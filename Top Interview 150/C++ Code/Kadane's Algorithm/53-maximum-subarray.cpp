class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxsum>=0)maxsum+=nums[i];
            else maxsum=nums[i];
            ans=max(ans,maxsum);
        }
        return ans;
    }
};
