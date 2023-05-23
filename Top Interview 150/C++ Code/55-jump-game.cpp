// Time: O(n)
// Space:O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int can_reach=0;
        for(int i=0;i<n;i++){
            if(can_reach<i) return false;
            can_reach=max(can_reach,i+nums[i]);
        }
        return true;
        
    }
};

class Solution2 {
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
