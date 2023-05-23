// Time: O(n)
// Space:O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int current=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=current)
                current=i;
        }
        return current==0;
    }
};
